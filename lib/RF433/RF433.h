#ifndef RF433_H
#define RF433_H

#include <driver/rmt.h>
#include <FuncModule.h>



#define RMT_TX_CHANNEL     RMT_CHANNEL_0
#define RMT_RX_CHANNEL     RMT_CHANNEL_1
#define RTM_TX_GPIO_NUM    17
#define RTM_RX_GPIO_NUM    16
#define RTM_BLOCK_NUM      1

#define RMT_CLK_DIV         80    /*!< RMT counter clock divider */ 
#define RMT_1US_TICKS (80000000 / RMT_CLK_DIV / 1000000)
#define RMT_1MS_TICKS (RMT_1US_TICKS * 1000)



#define T0H 	670
#define T1H 	320
#define T0L  	348
#define T1L  	642

#define RMT_CODE_H      {670,1,320,0}
#define RMT_CODE_L      {348,1,642,0}
#define RMT_START_CODE0 {4868,1,2469,0}
#define RMT_START_CODE1 {1647,1,315,0}

class RF433 : public FuncModule
{


    bool SEND_RECV;
    int parsedData(rmt_item32_t* item,size_t size,uint8_t* dataptr,size_t maxsize);
public:
    //RF433();
   virtual void init();
    virtual void initSender();
    void send(uint8_t * byte, size_t size,uint8_t*cr);
    
    int receive(int len, byte *receiveBytepar);


};
#endif
