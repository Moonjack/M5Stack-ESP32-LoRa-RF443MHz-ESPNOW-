#include <Arduino.h>
#include <M5Stack.h>
#include <ESPNOW.h>
#include <rom/crc.h>
#include "WiFi.h"
// 24:0A:C4:F8:CF:84 RECEIVER
// 24:0A:C4:F8:D4:34 Sender
//#include <esp_now.h>

 

typedef struct struct_message {
byte a[248];
  //int b;
  //float c;
  //bool d
  
} struct_message;
struct_message mydata;

ESPNOW * global;
uint8_t broadcastAddress2[] = {0x24, 0x0A, 0xC4, 0xF8, 0xCF, 0x84};




void ESPNOW::setReference(ESPNOW * a)
{
  global = a;
}
void ESPNOW::send(uint8_t * address, size_t size, uint8_t * packet)
{
   // Serial.printf("%02x %02x %02x %02x %02x %02x",broadcastAddress[0],broadcastAddress[1],broadcastAddress[2],broadcastAddress[3],broadcastAddress[4],broadcastAddress[5]);
  //  int init = 0;
  //  uint16_t crc = ~crc16_le(~init,packet,size);
    
//     Serial.printf("size: %d\n", size);
  //  *(packet+size) = (uint8_t)(crc&0xFF);
  // *(packet+size+1) = (uint8_t)(crc>>8);
  // Serial.printf("SENDER::CRC %02x",*(packet+size));
  // Serial.printf("SENDER::CRC %02x",*(packet+size+1));
    esp_err_t result = esp_now_send(address, packet, size);
   
  if (result == ESP_OK) {
    Serial.println("Sent with success");
  }
  else {
    Serial.println("Error sending the data");
  }
}

void ESPNOW::OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status)
{
    Serial.print("\r\nLast Packet Send Status:\t");
    Serial.printf("2nd SERIAL\n");
    #ifndef Modul_RX
    M5.Lcd.printf(status == ESP_NOW_SEND_SUCCESS ? "Success" : "Fail");
    M5.Lcd.setTextColor(TFT_GREEN);
    #endif
    #ifdef Modul_RX
    //M5.lcd.printf("ACK sent\n");
    //delay(1000);
    //M5.Lcd.clear();
    global->outputGate = true;
    #else
    //M5.Lcd.printf("Data sent\n");
    #endif
    
          Serial.printf("OPEN BEFORE FILE\n");
          File localFile = SD.open("/log.txt",FILE_APPEND);
          localFile.println(global->logger);
       //   localFile.printf("CPU TIME: %d::%d::%d\n",global->hours,global->minutes,global->seconds);
          if( status == ESP_NOW_SEND_SUCCESS)
           localFile.printf("250 Bytes delivery succes\n");
           else
           localFile.printf("250 Bytes delivery fail\n");
           localFile.close();
           global->logger="";
           Serial.printf("SENT OVER\n");
    //status1== ESP_NOW_SEND_SUCCESS ? status1 = true: status1 = false;
    //Serial.printf("STATUS1: %d\n",status1);
    
}


void ESPNOW::OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
  memcpy(&mydata, incomingData,len);
 /*  int init = 0;
   Serial.printf("CRCincoming:: %02x %02x\n",mydata.a[0],mydata.a[1]);
   uint16_t x = ~crc16_le(~init,mydata.a,len);
   Serial.printf("CRCReceiveResult: %04x\n",x);
  Serial.print("Bytes received: ");
  Serial.println(len);
  Serial.printf("Data: %02x\n",mydata.a[0]);
  */
 uint16_t x = 0x0000;
  if(x==0x0000)
  {
    
    M5.lcd.setCursor(2,0);
    M5.Lcd.fillRect(0,20,320,220,TFT_GREEN);
    delay(1000);
    M5.Lcd.clear();
    M5.Lcd.setTextColor(TFT_GREEN);
    M5.Lcd.printf("250 Bytes got\n");
    M5.Lcd.printf("Data %02x read\n",mydata.a[0]);
    File localFile = SD.open("/log.txt",FILE_APPEND);
          localFile.println(global->logger);
  //        localFile.printf("CPU TIME: %d::%d::%d\n",global->hours,global->minutes,global->seconds);
          localFile.printf("250 Bytes received\n");
          localFile.printf("Data %02x read\n",mydata.a[0]);
           localFile.close();
           global->logger="";
    global->receiveStatus=true;
    return;

  }
  else{
      M5.Lcd.printf("Bits flipped ERR\n");
       File localFile = SD.open("/log.txt",FILE_APPEND);
          localFile.println(global->logger);
          localFile.printf("Bytes lost\n");
           localFile.close();
           global->logger="";
  }
  
  
  //global->send(broadcastAddress2,(uint8_t *)&myData,sizeof(myData));
  global->receiveStatus = true;
}

void ESPNOW::initESPNOW(esp_now_peer_info_t * peerInfo, uint8_t * broadcastAddress)
{
  Serial.printf("ESP NOW initializing ....\n");
  WiFi.mode(WIFI_STA);

  // Init ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
   
  }
    esp_now_register_send_cb(ESPNOW::OnDataSent);
   esp_now_register_recv_cb(ESPNOW::OnDataRecv);

  memcpy(peerInfo->peer_addr, broadcastAddress, 6);
  peerInfo->channel = 0;  
  peerInfo->encrypt = false;

  if (esp_now_add_peer(peerInfo) != ESP_OK){
    Serial.println("Failed to add peer");
    //while(1);
    return;
  }
  
}
int ESPNOW::receive(int len, byte *receiveBytepar)
{
    Serial.printf("Receive\n");
}
void ESPNOW::init()
{
    Serial.printf("DUMMY");
}
void ESPNOW::initSender()
{
  Serial.printf("DUMMY\n");
}