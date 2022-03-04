#include <Arduino.h>
#include <rom/crc.h>
#include <M5Stack.h>
#include <FuncModule.h>
#include <RF433.h>

rmt_item32_t rmtbuff[2048];
uint8_t receivedBytes[5];
void RF433::initSender()
{   pinMode(RTM_TX_GPIO_NUM,OUTPUT);
    pinMode(RTM_RX_GPIO_NUM,INPUT);
    rmt_config_t txconfig;
    txconfig.rmt_mode = RMT_MODE_TX;
    txconfig.channel = RMT_TX_CHANNEL;
    txconfig.gpio_num = gpio_num_t(RTM_TX_GPIO_NUM);
    txconfig.mem_block_num = RTM_BLOCK_NUM;
    txconfig.tx_config.loop_en = false;
    txconfig.tx_config.carrier_en = false;
    txconfig.tx_config.idle_output_en = true;
    txconfig.tx_config.idle_level = rmt_idle_level_t(0);
    txconfig.clk_div = RMT_CLK_DIV;			//时钟分频
    ESP_ERROR_CHECK(rmt_config(&txconfig));
    ESP_ERROR_CHECK(rmt_driver_install(txconfig.channel, 0, 0));

}
void RF433::init()
{
    /*
    pinMode(RTM_TX_GPIO_NUM,OUTPUT);
    pinMode(RTM_RX_GPIO_NUM,INPUT);
    #ifndef Modul_RX    
    rmt_config_t txconfig;
    txconfig.rmt_mode = RMT_MODE_TX;
    txconfig.channel = RMT_TX_CHANNEL;
    txconfig.gpio_num = gpio_num_t(RTM_TX_GPIO_NUM);
    txconfig.mem_block_num = RTM_BLOCK_NUM;
    txconfig.tx_config.loop_en = false;
    txconfig.tx_config.carrier_en = false;
    txconfig.tx_config.idle_output_en = true;
    txconfig.tx_config.idle_level = rmt_idle_level_t(0);
    txconfig.clk_div = RMT_CLK_DIV;			//时钟分频
    ESP_ERROR_CHECK(rmt_config(&txconfig));
    ESP_ERROR_CHECK(rmt_driver_install(txconfig.channel, 0, 0));
*/

  //   #else
    rmt_config_t rxconfig;
    rxconfig.rmt_mode = RMT_MODE_RX;
    rxconfig.channel = RMT_RX_CHANNEL;
    rxconfig.gpio_num = gpio_num_t(RTM_RX_GPIO_NUM);
    rxconfig.mem_block_num = 6;
    rxconfig.clk_div = RMT_CLK_DIV;			//时钟分频
    rxconfig.rx_config.filter_en = true;  //开启滤波器
    rxconfig.rx_config.filter_ticks_thresh = 200 * RMT_1US_TICKS; //滤波信号宽度100*1M = 100us
    rxconfig.rx_config.idle_threshold = 3 * RMT_1MS_TICKS;
    
    ESP_ERROR_CHECK(rmt_config(&rxconfig));
    ESP_ERROR_CHECK(rmt_driver_install(rxconfig.channel, 2048, 0));
    
  // #endif
    


}


void RF433::send(uint8_t * buff,size_t size,uint8_t * cr)
{
    int init = 0;
  
    uint16_t crc = ~crc16_le(~init,buff,size);
  *(buff+size) = (uint8_t)(crc&0xFF);
  *(buff+size+1) = (uint8_t)(crc>>8);
  *(cr) = *(buff+size);
  *(cr+1) = *(buff+size+1);
  //Serial.printf("DATABUFF[0]: %02x\n",databuff[0]);
  Serial.printf("DATABUFF[1]: %02x\n",buff[1]);
  Serial.printf("DATABUFF[2]: %02x\n",buff[2]);
    rmtbuff[0] = (rmt_item32_t){RMT_START_CODE0};
    rmtbuff[1] = (rmt_item32_t){RMT_START_CODE1};
    for (int i = 0; i < size+2; i++)
    {
        uint8_t mark = 0x80;
        for (int n = 0; n < 8; n++)
        {
            rmtbuff[2+i*8+n] = ((buff[i]&mark))?((rmt_item32_t){RMT_CODE_H}):((rmt_item32_t){RMT_CODE_L});
            mark >>= 1;
        }
    }
    for( int i = 0; i< 7;i++)
    {
        ESP_ERROR_CHECK(rmt_write_items(RMT_TX_CHANNEL, rmtbuff, 42, false));
        ESP_ERROR_CHECK(rmt_wait_tx_done(RMT_TX_CHANNEL, portMAX_DELAY));
    }
}


int RF433::parsedData(rmt_item32_t* item,size_t size,uint8_t* dataptr,size_t maxsize)
{
    if(size < 4)return -1;
    int cnt = 0;
    uint8_t data = 0;
    uint8_t bitcnt = 0, hex_cnt = 0;
    if((( item[0].level0 == 0 ))&&(item[0].duration0 > 2300 )&&( item[0].duration0 < 2600 ))
    {
        //dataptr = (uint8_t*)malloc(size * sizeof(uint8_t));
        rmt_item32_t dataitem;
        dataitem.level0 = 1;
        dataitem.level1 = 0;
        dataitem.duration0 = item[0].duration1;
        do
        {
            cnt ++;
            dataitem.duration1 = item[cnt].duration0;
            if( cnt > 1 )
            {
                //Serial.printf("%d:%d,%d:%d ",dataitem.level0,dataitem.duration0,dataitem.level1,dataitem.duration1);
                if((( dataitem.duration0 + dataitem.duration1 ) < 1100 )&&(( dataitem.duration0 + dataitem.duration1 ) > 800 ))
                {
                    data <<= 1;
                    if( dataitem.duration0 > dataitem.duration1 )
                    {
                        data += 1;
                    }

                    bitcnt ++;
                    if( bitcnt >= 8 )
                    {
                        Serial.printf("%02x ",data);
                        if( hex_cnt >= maxsize )
                        {
                            return hex_cnt;
                        }
                        dataptr[hex_cnt] = data;
                        data = 0;
                        hex_cnt ++;
                        bitcnt = 0;
                    }
                }
                else
                {
                    Serial.printf("%d %d:%d,%d:%d ",hex_cnt,dataitem.level0,dataitem.duration0,dataitem.level1,dataitem.duration1);
                    return hex_cnt;
                }
            }
            dataitem.duration0 = item[cnt].duration1;
        }while (cnt < size);

        Serial.println("END");
    }
    return hex_cnt;

}

int RF433::receive(int len, byte * receiveBytespar)
{    unsigned long startTime = millis();
    int revicecnt = 0;
    int result = -1;
    RingbufHandle_t rb = nullptr;
    rmt_get_ringbuf_handle(RMT_RX_CHANNEL,&rb);
    rmt_rx_start(RMT_RX_CHANNEL,true);
    Serial.printf("RECEIVE: begin\n");
    while (rb) 
    {
        unsigned long timer = millis();
        if(millis() -startTime > 10000)
        {
            Serial.printf("\nWE LEAVE RECEIVE\n");
            return -1;

        }
        
        size_t rx_size = 0;
        rmt_item32_t* item = (rmt_item32_t*) xRingbufferReceive(rb, &rx_size, 500);
        Serial.printf("RECEIVE BUFFER INITIALIZATION\n");
        if( item != nullptr )
        {
            if( rx_size != 0 )
            {
                uint8_t databuff[256];
                
                Serial.printf("\r\nsize:%d\r\n",rx_size);
                int size = parsedData(item,rx_size,databuff,255);
                int init = 0;
             
                
                uint16_t x = ~crc16_le(~init,databuff,len+2);
                Serial.printf("CRC: %d\n",x); 
                if(( size >= 3 )&&( x == 0x0000 ))
                {
                    revicecnt ++;
                    Serial.printf("Revice %d\r\n",revicecnt);
                    if( revicecnt == 4 )
                    {
                        for(int i = 0; i<len+2; i++)
                        {
                            M5.Lcd.setTextColor(TFT_GREEN);
                            //M5.Lcd.printf("Data %c was received\n",databuff[i]);
                            receivedBytes[i] =databuff[i];
                        }
                        M5.Lcd.clear();
                        M5.Lcd.fillRect(0,20,320,220,TFT_GREEN);
                        Serial.printf("Green\r\n");
                        result = 1;
                    }
                }
            }
            vRingbufferReturnItem(rb, (void*) item);
        }
        else 
        {
            //Serial.printf("mmp????\r\n");
            if( revicecnt != 0 )
            {
                Serial.printf("Revice %d\r\n",revicecnt);
                M5.Lcd.clear();
                M5.Lcd.fillRect(0,20,320,220,TFT_RED);
                delay(1000);
                for(int i = 0; i<len+2;i++)
                {
                    receiveBytespar[i] = receivedBytes[i];
                }
                
                return result;
            }
            revicecnt = 0;
        }
    }
    rmt_rx_stop(RMT_RX_CHANNEL);
    return result;
}