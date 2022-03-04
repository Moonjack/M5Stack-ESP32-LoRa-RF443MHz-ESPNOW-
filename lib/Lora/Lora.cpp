#include "Arduino.h"
#include "M5Stack.h"
#include "Lora.h"


void Lora::initSender()
{
  Serial.printf("DUMMY");
}
void Lora::init()
{
  Serial2.begin(9600, SERIAL_8N1, 16, 17);
}


int Lora::receive(int len, byte *receiveBytepar)
{
//  Serial.printf("\n---->WE IN R <----\n");
  #ifndef Modul_RX
  *receiveBytepar = Serial2.read();
   #else
   if(Serial2.available() > 0)
   {
       Serial.printf("\n---->WE IN R <----\n");
     byte x = Serial2.read();
       Serial.printf("\n---->WE IN R2 <----\n");
     if(x != 0)
     {

     
     M5.Lcd.fillRect(0,20,320,220,TFT_GREEN);
     delay(1000);
     M5.Lcd.clear();
     M5.Lcd.clear();
     M5.Lcd.setCursor(2,0);
     M5.Lcd.printf("Data %02x read", x);
     File localFile = SD.open("/log.txt",FILE_APPEND);
     localFile.printf("Data %c was read\n",x);
     byte datax[1];
     byte yy = 0xFF;
     byte empty[1];
     //this->send(datax,sizeof(datax),empty);
      Serial2.write(yy);
     delay(2000);
     return 1;
     }
   }
   #endif
  while (Serial2.read() >= 0);
  return 0;
}

void Lora::send(byte * byte,size_t size, uint8_t * savebytes)
{
    bool gate = false;
    if(Serial2.availableForWrite() > 0){
       //char *  byte2 = (char*) byte;
          Serial.printf("\n----->%02x:<------\n",(char) byte[0]);

          Serial2.write((char) byte[0]);
          Serial2.flush();
    }
   #ifndef Modul_RX
   M5.Lcd.setCursor(2,0);
   M5.lcd.println("Waiting for ACK..\n");
   delay(1000);
   do{
     M5.update();
     if(Serial2.available() > 0)
     {
       gate = true;

   
       this->receive(1,savebytes);
    if(savebytes[0]==0xFF)
    {
    M5.Lcd.fillRect(0,20,320,220,TFT_GREEN);
    delay(1000);
    M5.Lcd.clear();
      M5.Lcd.clear();
      M5.Lcd.setCursor(2,0);
    }
   
       //Serial.printf("\nR----->%02x:<------R\n",savebytes[0]);
     }
     if(M5.BtnC.wasReleased())
     {
       break;
     }

   }while(gate!=true);
   #endif
    
}



/*


LoRa_E22 e22ttl(&Serial2);

void Lora::init()
{
    //this->e22ttl.begin();
       e22ttl.begin();
}

void Lora::send(String byte)
{
    e22ttl.sendMessage(byte);
}


bool Lora::receive()
{
    
   if(e22ttl.available()>1)
  {
    Serial.printf("RECEIVED SOMETHING\n");
    ResponseContainer rc = e22ttl.receiveMessage();
    if(rc.status.code!=1)
    {
       rc.status.getResponseDescription();
        return false;
    }
    else{
      Serial.println(rc.data);
      File localFile = SD.open("/log.txt",FILE_APPEND);
      localFile.printf("Data %s was read\n",rc.data);
      Serial.printf("DATA READ\n");
      M5.Lcd.fillRect(0,20,320,220,TFT_GREEN);
      delay(1000);
    M5.Lcd.clear();
      M5.Lcd.clear();
      M5.Lcd.setCursor(2,0);
      M5.Lcd.printf("Data %s was read\n",rc.data);
      #ifdef Modul_RX
      Serial.printf("FF was sent\n");
      this->send("FF");
      #endif
      delay(1500);
      localFile.close();
      return true;
    }

}
    return false;
}
*/