#include <Arduino.h>
#include <M5Stack.h>
#include <Menu.h>
#include <FuncModule.h>
#include <RF433.h>
#include <ESPNOW.h>
#include <Lora.h>

#ifdef Modul_RX
uint8_t broadcastAddress[] = {0x24, 0x0A, 0xC4, 0xF8, 0xD4, 0x34};
#else 
uint8_t broadcastAddress[] = {0x24, 0x0A, 0xC4, 0xF8, 0xCF, 0x84};
#endif 
esp_now_peer_info_t globalpeerInfo;

typedef struct{
  byte data[10];
  int len;
}Datenpaket;
Datenpaket * global1Byte;
Menu * MC;
int qq;
page * test;
FuncModule * Func;
ESPNOW * Func2;
FuncModule * Func3;

page * testR;
page * sendStandort;
page * receiveStandort;
page * RECEIVEESPNOW;
page * SENDERESPNOW;
page * Byteref;
page * Byterefx;
page * Sender_ReceiverG;
page * deleteSD;
page * start_menuG;
page * SenderLora;
page * ReceiveLora;

String CurrentLocation;
byte position;
File globalFile;
String StringFunc;
String StartFunc;
int id;
int counter = 0;
typedef struct struct_message {
byte a[248];

  
} struct_message;
struct_message myData;
void foo()
{
  Serial.printf("FOO CALLED");
}
void informLoRa()
{
  StringFunc = StringFunc + "1 Byte Protokoll";
}
void inform()
{
  StringFunc = StringFunc + "\n 250 Byte Protokoll";
}
void generateOneByte()
{
   StringFunc = StringFunc + "\n_ 1 + 2 Byte Protokoll";
  Serial.printf("CREATED TASK\n");
  Datenpaket * a1 = new Datenpaket();
     a1->data[0]=position;
    
     a1->len = 1;
     global1Byte = a1;
  

}

void generateTwoByte()
{
  StringFunc = StringFunc + "\n_ 2 + 2 Byte Protokoll";
  Serial.printf("CREATED TASK\n");
  Datenpaket * a1 = new Datenpaket();
     a1->data[0]= position;
     a1->data[1]=0x42;
    
     a1->len = 2;
     global1Byte = a1;
 

}

void generateThreeByte()
{
  StringFunc = StringFunc + "\n_ 3 + 2 Byte Protokoll";
  Serial.printf("CREATED TASK\n");
  Datenpaket * a1 = new Datenpaket();
     a1->data[0]= position;
     a1->data[1]=0x42;
     a1->data[2]=0x43;
     
    
     a1->len = 3;
     global1Byte = a1;
  

}

void DefineByteLenOne()
{ StringFunc = StringFunc + "\n_ 1 + 2 Byte Protokoll";
  Datenpaket * a1 = new Datenpaket();
  a1->len =1;
  global1Byte = a1;

}


void DefineByteLenTwo()
{ StringFunc = StringFunc + "\n_ 2 + 2 Byte Protokoll";
  Datenpaket * a1 = new Datenpaket();
  a1->len =2;
  global1Byte = a1;
  
}


void DefineByteLenThree()
{ StringFunc = StringFunc + "\n_ 3 + 2 Byte Protokoll";
  Datenpaket * a1 = new Datenpaket();
  a1->len =3;
  global1Byte = a1;

}
void setLocationA(){
  CurrentLocation = "01";
   position = 0x01;
   StringFunc =  StartFunc + "_" + "Location_" + CurrentLocation;
   Serial.println(StringFunc);
  
  
}

void setLocationB(){
  CurrentLocation = "02";
  position = 0x02;
  StringFunc =  StartFunc + "_" + "Location_" + CurrentLocation;
  
}

void setLocationC(){
  CurrentLocation = "03";
  position = 0x03;
  StringFunc =  StartFunc + "_" + "Location_" + CurrentLocation;
  
}

void setLocationD(){
  CurrentLocation = "04";
  position = 0x04;
  StringFunc =  StartFunc + "_" + "Location_" + CurrentLocation;
  
}

void setLocationE(){
  CurrentLocation = "05";
  position = 0x05;
  StringFunc =  StartFunc + "_" + "Location_" + CurrentLocation;
  
}
void setLocationF(){
  CurrentLocation = "06";
  position = 0x06;
  StringFunc =  StartFunc + "_" + "Location_" + CurrentLocation;
  
}
void setLocationG(){
  CurrentLocation = "07";
  position = 0x07;
  StringFunc =  StartFunc + "_" + "Location_" + CurrentLocation;
  
}
void setLocationH(){
  CurrentLocation = "08";
  position = 0x08;
  StringFunc =  StartFunc + "_" + "Location_" + CurrentLocation;
  
}
void setLocationI(){
  CurrentLocation = "09";
  position = 0x09;
  StringFunc =  StartFunc + "_" + "Location_" + CurrentLocation;
  
}
void setLocationJ(){
  CurrentLocation = "10";
  position = 0x10;
  StringFunc =  StartFunc + "_" + "Location_" + CurrentLocation;
  
}
void setLocationK(){
  CurrentLocation = "11";
  position = 0x11;
  StringFunc =  StartFunc + "_" + "Location_" + CurrentLocation;
  
}
void setLocationL(){
  CurrentLocation = "12";
  position = 0x12;
  StringFunc =  StartFunc + "_" + "Location_" + CurrentLocation;
  
}
void setLocationM(){
  CurrentLocation = "13";
  position = 0x13;
  StringFunc =  StartFunc + "_" + "Location_" + CurrentLocation;
  
}
void setLocationN(){
  CurrentLocation = "14";
  position = 0x14;
  StringFunc =  StartFunc + "_" + "Location_" + CurrentLocation;
  
}
void setLocationO(){
  CurrentLocation = "15";
  position = 0x15;
  StringFunc =  StartFunc + "_" + "Location_" + CurrentLocation;
  
  
}

void setLocation16(){
  CurrentLocation = "16";
  position = 0x16;
  StringFunc =  StartFunc + "_" + "Location_" + CurrentLocation;
  
  
}

void setLocation17(){
  CurrentLocation = "17";
  position = 0x17;
  StringFunc =  StartFunc + "_" + "Location_" + CurrentLocation;
  
  
}

void setLocation18(){
  CurrentLocation = "18";
  position = 0x18;
  StringFunc =  StartFunc + "_" + "Location_" + CurrentLocation;
  
  
}

void setLocation19(){
  CurrentLocation = "19";
  position = 0x19;
  StringFunc =  StartFunc + "_" + "Location_" + CurrentLocation;
  
  
}


void setLocation20(){
  CurrentLocation = "20";
  position = 0x20;
  StringFunc =  StartFunc + "_" + "Location_" + CurrentLocation;
  
  
}


void setLocation21(){
  CurrentLocation = "21";
  position = 0x21;
  StringFunc =  StartFunc + "_" + "Location_" + CurrentLocation;
  
  
}

void setLocation22(){
  CurrentLocation = "22";
  position = 0x22;
  StringFunc =  StartFunc + "_" + "Location_" + CurrentLocation;
  
  
}

void setLocation23(){
  CurrentLocation = "23";
  position = 0x23;
  StringFunc =  StartFunc + "_" + "Location_" + CurrentLocation;
  
  
}

void setLocation24(){
  CurrentLocation = "24";
  position = 0x24;
  StringFunc =  StartFunc + "_" + "Location_" + CurrentLocation;
  
  
}

void setLocation25(){
  CurrentLocation = "25";
  position = 0x25;
  StringFunc =  StartFunc + "_" + "Location_" + CurrentLocation;
  
  
}

void setLocation26(){
  CurrentLocation = "26";
  position = 0x26;
  StringFunc =  StartFunc + "_" + "Location_" + CurrentLocation;
  
  
}

void setLocation27(){
  CurrentLocation = "27";
  position = 0x27;
  StringFunc =  StartFunc + "_" + "Location_" + CurrentLocation;
  
  
}

void setLocation28(){
  CurrentLocation = "28";
  position = 0x28;
  StringFunc =  StartFunc + "_" + "Location_" + CurrentLocation;
  
  
}

void setLocation29(){
  CurrentLocation = "29";
  position = 0x29;
  StringFunc =  StartFunc + "_" + "Location_" + CurrentLocation;
  
  
}

void setLocation30(){
  CurrentLocation = "30";
  position = 0x30;
  StringFunc =  StartFunc + "_" + "Location_" + CurrentLocation;
  
  
}

void setLocation31(){
  CurrentLocation = "31";
  position = 0x31;
  StringFunc =  StartFunc + "_" + "Location_" + CurrentLocation;
  
  
}

void setLocation32(){
  CurrentLocation = "32";
  position = 0x32;
  StringFunc =  StartFunc + "_" + "Location_" + CurrentLocation;
  
  
}

void setLocation33(){
  CurrentLocation = "33";
  position = 0x33;
  StringFunc =  StartFunc + "_" + "Location_" + CurrentLocation;
  
  
}

void setLocation34(){
  CurrentLocation = "34";
  position = 0x34;
  StringFunc =  StartFunc + "_" + "Location_" + CurrentLocation;
  
  
}
void setLocation35(){
  CurrentLocation = "35";
  position = 0x35;
  StringFunc =  StartFunc + "_" + "Location_" + CurrentLocation;
  
  
}

void setLocation36(){
  CurrentLocation = "36";
  position = 0x36;
  StringFunc =  StartFunc + "_" + "Location_" + CurrentLocation;
  
  
}

void setLocation37(){
  CurrentLocation = "37";
  position = 0x37;
  StringFunc =  StartFunc + "_" + "Location_" + CurrentLocation;
  
  
}

void setLocation38(){
  CurrentLocation = "38";
  position = 0x38;
  StringFunc =  StartFunc + "_" + "Location_" + CurrentLocation;
  
  
}

void setLocation39(){
  CurrentLocation = "39";
  position = 0x39;
  StringFunc =  StartFunc + "_" + "Location_" + CurrentLocation;
  
  
}

void setLocation40(){
  CurrentLocation = "40";
  position = 0x40;
  StringFunc =  StartFunc + "_" + "Location_" + CurrentLocation;
  
  
}

void setLocation41(){
  CurrentLocation = "41";
  position = 0x41;
  StringFunc =  StartFunc + "_" + "Location_" + CurrentLocation;
  
  
}

void setLocation42(){
  CurrentLocation = "42";
  position = 0x42;
  StringFunc =  StartFunc + "_" + "Location_" + CurrentLocation;
  
  
}

void setLocation43(){
  CurrentLocation = "43";
  position = 0x43;
  StringFunc =  StartFunc + "_" + "Location_" + CurrentLocation;
  
  
}

void setLocation44(){
  CurrentLocation = "44";
  position = 0x44;
  StringFunc =  StartFunc + "_" + "Location_" + CurrentLocation;
  
  
}

void setRF433()
{
  StartFunc ="RF433";
  Serial.printf("StartFunc Set");
    Byteref->setEntry(new MenuEntry("RF433 1 Byte",sendStandort,&generateOneByte));
    Byteref->setEntry(new MenuEntry("RF433 2 Byte",sendStandort,&generateTwoByte));
    Byteref->setEntry(new MenuEntry("RF433 3 Byte",sendStandort,&generateThreeByte));
    Byterefx->setEntry(new MenuEntry("RF433 1 Byte",testR,&generateOneByte));
    Byterefx->setEntry(new MenuEntry("RF433 2 Byte",testR,&generateTwoByte));
    Byterefx->setEntry(new MenuEntry("RF433 3 Byte",testR,&generateThreeByte));



    sendStandort->setEntry(new MenuEntry("Standort 01",test,&setLocationA));
    sendStandort->setEntry(new MenuEntry("Standort 02",test,&setLocationB));
    sendStandort->setEntry(new MenuEntry("Standort 03",test,&setLocationC));
    sendStandort->setEntry(new MenuEntry("Standort 04",test,&setLocationD));
    sendStandort->setEntry(new MenuEntry("Standort 05",test,&setLocationE));
    sendStandort->setEntry(new MenuEntry("Standort 06",test,&setLocationF));
    sendStandort->setEntry(new MenuEntry("Standort 07",test,&setLocationG));
    sendStandort->setEntry(new MenuEntry("Standort 08",test,&setLocationH));
    sendStandort->setEntry(new MenuEntry("Standort 09",test,&setLocationI));
    sendStandort->setEntry(new MenuEntry("Standort 10",test,&setLocationJ));
    sendStandort->setEntry(new MenuEntry("Standort 11",test,&setLocationK));
    sendStandort->setEntry(new MenuEntry("Standort 12",test,&setLocationL));
    sendStandort->setEntry(new MenuEntry("Standort 13",test,&setLocationM));
    sendStandort->setEntry(new MenuEntry("Standort 14",test,&setLocationN));
    sendStandort->setEntry(new MenuEntry("Standort 15",test,&setLocationO));
    sendStandort->setEntry(new MenuEntry("Standort 16",test,&setLocation16));
    sendStandort->setEntry(new MenuEntry("Standort 17",test,&setLocation17));
    sendStandort->setEntry(new MenuEntry("Standort 18",test,&setLocation18));
    sendStandort->setEntry(new MenuEntry("Standort 19",test,&setLocation19));
    sendStandort->setEntry(new MenuEntry("Standort 20",test,&setLocation20));
    sendStandort->setEntry(new MenuEntry("Standort 21",test,&setLocation21));
    sendStandort->setEntry(new MenuEntry("Standort 22",test,&setLocation22));
    sendStandort->setEntry(new MenuEntry("Standort 23",test,&setLocation23));
    sendStandort->setEntry(new MenuEntry("Standort 24",test,&setLocation24));
    sendStandort->setEntry(new MenuEntry("Standort 25",test,&setLocation25));
    sendStandort->setEntry(new MenuEntry("Standort 26",test,&setLocation26));
    sendStandort->setEntry(new MenuEntry("Standort 27",test,&setLocation27));
    sendStandort->setEntry(new MenuEntry("Standort 28",test,&setLocation28));
    sendStandort->setEntry(new MenuEntry("Standort 29",test,&setLocation29));
    sendStandort->setEntry(new MenuEntry("Standort 30",test,&setLocation30));
    sendStandort->setEntry(new MenuEntry("Standort 31",test,&setLocation31));
    sendStandort->setEntry(new MenuEntry("Standort 32",test,&setLocation32));
    sendStandort->setEntry(new MenuEntry("Standort 33",test,&setLocation33));
    sendStandort->setEntry(new MenuEntry("Standort 34",test,&setLocation34));
    sendStandort->setEntry(new MenuEntry("Standort 35",test,&setLocation35));
    sendStandort->setEntry(new MenuEntry("Standort 36",test,&setLocation36));
    sendStandort->setEntry(new MenuEntry("Standort 37",test,&setLocation37));
    sendStandort->setEntry(new MenuEntry("Standort 38",test,&setLocation38));
    sendStandort->setEntry(new MenuEntry("Standort 39",test,&setLocation39));
    sendStandort->setEntry(new MenuEntry("Standort 40",test,&setLocation40));
    sendStandort->setEntry(new MenuEntry("Standort 41",test,&setLocation41));
    sendStandort->setEntry(new MenuEntry("Standort 42",test,&setLocation42));
    sendStandort->setEntry(new MenuEntry("Standort 43",test,&setLocation43));
    sendStandort->setEntry(new MenuEntry("Standort 44",test,&setLocation44));
}
void setESPNOW()
{
  StartFunc = "ESPNOW";
  #ifndef Modul_RX
  Byteref->setEntry(new MenuEntry("ESP NOW 250",sendStandort,&inform));
  #else
  Byterefx->setEntry(new MenuEntry("ESPNOW 250 ",RECEIVEESPNOW,&inform));
  #endif
    #ifndef Modul_RX
    sendStandort->setEntry(new MenuEntry("Standort 01",SENDERESPNOW,&setLocationA));
    sendStandort->setEntry(new MenuEntry("Standort 02",SENDERESPNOW,&setLocationB));
    sendStandort->setEntry(new MenuEntry("Standort 03",SENDERESPNOW,&setLocationC));
    sendStandort->setEntry(new MenuEntry("Standort 04",SENDERESPNOW,&setLocationD));
    sendStandort->setEntry(new MenuEntry("Standort 05",SENDERESPNOW,&setLocationE));
    sendStandort->setEntry(new MenuEntry("Standort 06",SENDERESPNOW,&setLocationF));
    sendStandort->setEntry(new MenuEntry("Standort 07",SENDERESPNOW,&setLocationG));
    sendStandort->setEntry(new MenuEntry("Standort 08",SENDERESPNOW,&setLocationH));
    sendStandort->setEntry(new MenuEntry("Standort 09",SENDERESPNOW,&setLocationI));
    sendStandort->setEntry(new MenuEntry("Standort 10",SENDERESPNOW,&setLocationJ));
    sendStandort->setEntry(new MenuEntry("Standort 11",SENDERESPNOW,&setLocationK));
    sendStandort->setEntry(new MenuEntry("Standort 12",SENDERESPNOW,&setLocationL));
    sendStandort->setEntry(new MenuEntry("Standort 13",SENDERESPNOW,&setLocationM));
    sendStandort->setEntry(new MenuEntry("Standort 14",SENDERESPNOW,&setLocationN));
    sendStandort->setEntry(new MenuEntry("Standort 15",SENDERESPNOW,&setLocationO));
    sendStandort->setEntry(new MenuEntry("Standort 16",SENDERESPNOW,&setLocation16));
    sendStandort->setEntry(new MenuEntry("Standort 17",SENDERESPNOW,&setLocation17));
    sendStandort->setEntry(new MenuEntry("Standort 18",SENDERESPNOW,&setLocation18));
    sendStandort->setEntry(new MenuEntry("Standort 19",SENDERESPNOW,&setLocation19));
    sendStandort->setEntry(new MenuEntry("Standort 20",SENDERESPNOW,&setLocation20));
    sendStandort->setEntry(new MenuEntry("Standort 21",SENDERESPNOW,&setLocation21));
    sendStandort->setEntry(new MenuEntry("Standort 22",SENDERESPNOW,&setLocation22));
    sendStandort->setEntry(new MenuEntry("Standort 23",SENDERESPNOW,&setLocation23));
    sendStandort->setEntry(new MenuEntry("Standort 24",SENDERESPNOW,&setLocation24));
    sendStandort->setEntry(new MenuEntry("Standort 25",SENDERESPNOW,&setLocation25));
    sendStandort->setEntry(new MenuEntry("Standort 26",SENDERESPNOW,&setLocation26));
    sendStandort->setEntry(new MenuEntry("Standort 27",SENDERESPNOW,&setLocation27));
    sendStandort->setEntry(new MenuEntry("Standort 28",SENDERESPNOW,&setLocation28));
    sendStandort->setEntry(new MenuEntry("Standort 29",SENDERESPNOW,&setLocation29));
    sendStandort->setEntry(new MenuEntry("Standort 30",SENDERESPNOW,&setLocation30));
    sendStandort->setEntry(new MenuEntry("Standort 31",SENDERESPNOW,&setLocation31));
    sendStandort->setEntry(new MenuEntry("Standort 32",SENDERESPNOW,&setLocation32));
    sendStandort->setEntry(new MenuEntry("Standort 33",SENDERESPNOW,&setLocation33));
    sendStandort->setEntry(new MenuEntry("Standort 34",SENDERESPNOW,&setLocation34));
    sendStandort->setEntry(new MenuEntry("Standort 35",SENDERESPNOW,&setLocation35));
    sendStandort->setEntry(new MenuEntry("Standort 36",SENDERESPNOW,&setLocation36));
    sendStandort->setEntry(new MenuEntry("Standort 37",SENDERESPNOW,&setLocation37));
    sendStandort->setEntry(new MenuEntry("Standort 38",SENDERESPNOW,&setLocation38));
    sendStandort->setEntry(new MenuEntry("Standort 39",SENDERESPNOW,&setLocation39));
    sendStandort->setEntry(new MenuEntry("Standort 40",SENDERESPNOW,&setLocation40));
    sendStandort->setEntry(new MenuEntry("Standort 41",SENDERESPNOW,&setLocation41));
    sendStandort->setEntry(new MenuEntry("Standort 42",SENDERESPNOW,&setLocation42));
    sendStandort->setEntry(new MenuEntry("Standort 43",SENDERESPNOW,&setLocation43));
    sendStandort->setEntry(new MenuEntry("Standort 44",SENDERESPNOW,&setLocation44));
    #endif

   
}
void setLora()
{
  StartFunc = "LoRa";
  #ifndef Modul_RX
  Byteref->setEntry(new MenuEntry("LoRa 1 Byte",sendStandort,&inform));
  #else
  Byterefx->setEntry(new MenuEntry("LoRa 1 Byte ",ReceiveLora,&inform));
  #endif
    #ifndef Modul_RX
    sendStandort->setEntry(new MenuEntry("Standort 01",SenderLora,&setLocationA));
    sendStandort->setEntry(new MenuEntry("Standort 02",SenderLora,&setLocationB));
    sendStandort->setEntry(new MenuEntry("Standort 03",SenderLora,&setLocationC));
    sendStandort->setEntry(new MenuEntry("Standort 04",SenderLora,&setLocationD));
    sendStandort->setEntry(new MenuEntry("Standort 05",SenderLora,&setLocationE));
    sendStandort->setEntry(new MenuEntry("Standort 06",SenderLora,&setLocationF));
    sendStandort->setEntry(new MenuEntry("Standort 07",SenderLora,&setLocationG));
    sendStandort->setEntry(new MenuEntry("Standort 08",SenderLora,&setLocationH));
    sendStandort->setEntry(new MenuEntry("Standort 09",SenderLora,&setLocationI));
    sendStandort->setEntry(new MenuEntry("Standort 10",SenderLora,&setLocationJ));
    sendStandort->setEntry(new MenuEntry("Standort 11",SenderLora,&setLocationK));
    sendStandort->setEntry(new MenuEntry("Standort 12",SenderLora,&setLocationL));
    sendStandort->setEntry(new MenuEntry("Standort 13",SenderLora,&setLocationM));
    sendStandort->setEntry(new MenuEntry("Standort 14",SenderLora,&setLocationN));
    sendStandort->setEntry(new MenuEntry("Standort 15",SenderLora,&setLocationO));
    sendStandort->setEntry(new MenuEntry("Standort 16",SenderLora,&setLocation16));
    sendStandort->setEntry(new MenuEntry("Standort 17",SenderLora,&setLocation17));
    sendStandort->setEntry(new MenuEntry("Standort 18",SenderLora,&setLocation18));
    sendStandort->setEntry(new MenuEntry("Standort 19",SenderLora,&setLocation19));
    sendStandort->setEntry(new MenuEntry("Standort 20",SenderLora,&setLocation20));
    sendStandort->setEntry(new MenuEntry("Standort 21",SenderLora,&setLocation21));
    sendStandort->setEntry(new MenuEntry("Standort 22",SenderLora,&setLocation22));
    sendStandort->setEntry(new MenuEntry("Standort 23",SenderLora,&setLocation23));
    sendStandort->setEntry(new MenuEntry("Standort 24",SenderLora,&setLocation24));
    sendStandort->setEntry(new MenuEntry("Standort 25",SenderLora,&setLocation25));
    sendStandort->setEntry(new MenuEntry("Standort 26",SenderLora,&setLocation26));
    sendStandort->setEntry(new MenuEntry("Standort 27",SenderLora,&setLocation27));
    sendStandort->setEntry(new MenuEntry("Standort 28",SenderLora,&setLocation28));
    sendStandort->setEntry(new MenuEntry("Standort 29",SenderLora,&setLocation29));
    sendStandort->setEntry(new MenuEntry("Standort 30",SenderLora,&setLocation30));
    sendStandort->setEntry(new MenuEntry("Standort 31",SenderLora,&setLocation31));
    sendStandort->setEntry(new MenuEntry("Standort 32",SenderLora,&setLocation32));
    sendStandort->setEntry(new MenuEntry("Standort 33",SenderLora,&setLocation33));
    sendStandort->setEntry(new MenuEntry("Standort 34",SenderLora,&setLocation34));
    sendStandort->setEntry(new MenuEntry("Standort 35",SenderLora,&setLocation35));
    sendStandort->setEntry(new MenuEntry("Standort 36",SenderLora,&setLocation36));
    sendStandort->setEntry(new MenuEntry("Standort 37",SenderLora,&setLocation37));
    sendStandort->setEntry(new MenuEntry("Standort 38",SenderLora,&setLocation38));
    sendStandort->setEntry(new MenuEntry("Standort 39",SenderLora,&setLocation39));
    sendStandort->setEntry(new MenuEntry("Standort 40",SenderLora,&setLocation40));
    sendStandort->setEntry(new MenuEntry("Standort 41",SenderLora,&setLocation41));
    sendStandort->setEntry(new MenuEntry("Standort 42",SenderLora,&setLocation42));
    sendStandort->setEntry(new MenuEntry("Standort 43",SenderLora,&setLocation43));
    sendStandort->setEntry(new MenuEntry("Standort 44",SenderLora,&setLocation44));
    #endif


}

void setPromptSender()
{
  StartFunc=StartFunc + "::Sender::";
}
void setPromptReceiver()
{
  StartFunc=StartFunc + "::Receiver::";
}

void deleteCard()
{
  SD.remove("/log.txt");
}
void setup() {
  

  M5.begin();
  M5.Lcd.setTextSize(3);
//  M5.Lcd.printf("HELLO USER\n");
  

    Func = new RF433();
    Func2 = new ESPNOW();
    Func3 = new Lora();
   // Func3 = new Lora();
    esp_now_peer_info_t peerInfo;
    globalpeerInfo = peerInfo;
   
    page * start_menu = new page("Main");
    Menu * M1 = new Menu(start_menu);
    MC = M1;
    page * Bytes = new page("Bytes");
    page * ByteLenRx = new page("Bytes");
    page * Sender_Receiver = new page("Sender/Receiver");
    page * standort = new page("Standort");
    page * standortR = new page("StandortR");
    SenderLora = new page("LoRa");
    ReceiveLora = new page("RLora");
    deleteSD = new page("Delete");
    testR = new page("testReceive");
    test = new page("Sending data..");
    SENDERESPNOW = new page ("SENDERESPNOW");
    RECEIVEESPNOW = new page("Receive ESPNOW");
    start_menu->setEntry(new MenuEntry("RF433MHz",Sender_Receiver,&setRF433));
    start_menu->setEntry(new MenuEntry("LoRa",Sender_Receiver,&setLora));
    start_menu->setEntry(new MenuEntry("ESPNOW",Sender_Receiver,&setESPNOW));
    start_menu->setEntry(new MenuEntry("DeleteSD",deleteSD,&deleteCard));
    #ifndef Modul_RX
    Sender_Receiver->setEntry(new MenuEntry("Send",Bytes,&setPromptSender));
    #else
    Sender_Receiver->setEntry(new MenuEntry("Receive",ByteLenRx,&setPromptReceiver));
    #endif
     M5.Lcd.setTextColor(TFT_GREEN);
   
   
    MC->display(1);
     if(!SD.begin())
    {
      Serial.printf("Card failed..!\n");
      while(1);

    }
    globalFile = SD.open("/log.txt",FILE_APPEND);
    globalFile.println("CPU RESTART !!!!");
    globalFile.close();
    sendStandort=standort;
    receiveStandort=standortR;
    Byteref = Bytes;
    Byterefx = ByteLenRx;
    Sender_ReceiverG = Sender_Receiver;
    start_menuG = start_menu;
   
}


void loop() {
  // put your main code here, to run repeatedly:
  static int x = 0;
  static bool ESPNOWx = true;
  static int t = 0;

  
  M5.update();
  if(M5.BtnB.wasReleased())
  {
     
     MC->current_page->select();
     
     MC->display(MC->current_page->Line);

  }
  
  else if(M5.BtnA.wasReleased())
  {
    if(MC->current_page==test || MC->current_page == testR || MC->current_page == RECEIVEESPNOW || MC->current_page == SENDERESPNOW)
     return;
  
            
       MC->push(MC->current_page);
      
       MC->current_page = MC->current_page->gopage(MC->current_page->Line -1);
         Serial.printf("::current-page %s",MC->current_page->txt);
     
      Datenpaket getData;  
      uint8_t * globalFuncData;

      if(MC->current_page == deleteSD)
      {
        M5.Lcd.clear();
        M5.Lcd.println("FILE DELETED");
        M5.Lcd.println("GO BACK!");
      }

   else if(MC->current_page == test)
      {

           
        M5.Lcd.clear();
        M5.lcd.setCursor(0,25);
        M5.Lcd.setTextColor(TFT_RED);
        M5.Lcd.printf("Generating Data..\n");
        Serial.printf("WE ARE SENDING RF433MHz\n");
        
         delay(1000);
       
         Serial.printf("READ TASK\n");
  
  
      if(x==0)
      Func->initSender();
   
     uint8_t crc[2];
      global1Byte->data[0] = position;
     Serial.printf("DATA IS: %02x\n",global1Byte->data[0]);

      Func->send(global1Byte->data,global1Byte->len,crc);
      x++;
       M5.Lcd.clear();
       MC->current_page->Line = 1;
       MC->display(MC->current_page->Line);
       M5.Lcd.printf("CurrentLocation: %s\n",CurrentLocation);
       globalFile = SD.open("/log.txt",FILE_APPEND);
       if(globalFile)
       {
    Serial.printf("FILE OPENDED\n");
       }
      else 
      {
        M5.Lcd.clear();
        M5.Lcd.printf("RECORD NOT POSSIBLE\nPLEASE MAKE RESET\n");
        while(1);
        Serial.printf("Open Error\n");
      }
     
       globalFile.println(StringFunc);
       Serial.println(StringFunc);
       for(int i = 0; i < global1Byte->len; i++)
       {
         
           M5.Lcd.setTextColor(TFT_GREEN);
           M5.Lcd.printf("Data %02x was sent\n",global1Byte->data[i]);
           globalFile.printf("    Data %02x was sent\n",global1Byte->data[i]);

       }
      
       globalFile.close();
       StringFunc = "";
          
         
          
        }
       
      else if(MC->current_page == testR)
      {
        
        
           
        M5.Lcd.clear();
        M5.lcd.setCursor(2,0);
        M5.Lcd.printf("Waiting .... \n");
        if(t==0)
        {
          Func->init();
        
          t++;
        }
        globalFile = SD.open("/log.txt",FILE_APPEND);
        globalFile.println(StringFunc);
        while(1)
        {
          
          Serial.printf("WE ARE IN LOOP\n");
          byte callref[global1Byte->len];
          int x = Func->receive(global1Byte->len,callref);
          if(x == 1 )
          {
            M5.Lcd.clear();
            M5.lcd.setCursor(2,0);
            M5.Lcd.printf("CurrentLocation: %s\n",CurrentLocation);
            for(int i = 0; i<global1Byte->len; i++)
            {
              Serial.printf("LOOP FOOORsdcard\n");
               M5.Lcd.setTextColor(TFT_GREEN);

              M5.Lcd.printf("Data %02x was read\n",callref[i]);
              globalFile.printf("       Data %02x was read\n",callref[i]);
            }
              globalFile.printf("       CRC: %02x, %02x\n",callref[global1Byte->len],callref[global1Byte->len+1]);
             
             //globalFile.close();  globalFile.println(StringFunc);
              StringFunc="";
            //M5.Lcd.printf("Wait for Logging\n");
          }
          
          else if(x==-1)
          {
           /*
            M5.Lcd.printf("Timeout ...\n");
              globalFile.printf("       Timeout...\n");
              globalFile.close();
              StringFunc="";
            M5.Lcd.printf("Please wait for sending");
            Serial.printf("Nothing Received\n");
            //break;
            */
            globalFile.close();
            M5.Lcd.clear();
            M5.lcd.setCursor(2,0);
            M5.Lcd.printf("Waiting .... \n");
            globalFile = SD.open("/log.txt",FILE_APPEND);
            globalFile.println("Timeout");
          }
          
          
          
        }
        
        
        
        
        
       

      }
      else if(MC->current_page == RECEIVEESPNOW)
      {
    
        Func2->receiveStatus = false;
        Serial.printf("\nESPNOW\n");
          while(1)
          {   M5.update();
            if(M5.BtnC.wasReleased())
            {
              M5.Lcd.printf("PLEASE RESET\n");
              break;
            }
               
              if(Func2->outputGate==true)
              {
                M5.Lcd.clear();
                M5.lcd.setCursor(2,0);
                M5.Lcd.setTextSize(3);
                M5.Lcd.setTextColor(TFT_RED);
                Func2->logger = StringFunc;
                
  
                M5.lcd.println("Waiting.....");
                if(counter==0)
                {
                  Serial.printf("INITIALIZATION: \n");
                  for(int i = 0; i<8; i++)
                  {
                    Serial.printf("%02x ", broadcastAddress[i]);
                  }
                  Serial.printf("\n");
                  Func2->initESPNOW(&globalpeerInfo,broadcastAddress);
                  Func2->setReference(Func2);
                  counter++;
                }
     
    Func2->outputGate = false;
              }

              
              if(Func2->receiveStatus==true)
              {
    
                Serial.printf("TEEEST\n");
             

       
                for(int i = 0; i < 250; i++)
                {
                  myData.a[i] = 0xFF;
                }

        
                  Serial.printf("%d",sizeof(myData));
        
                  Func2->send(broadcastAddress,sizeof(myData),(uint8_t*)&myData);
                  Serial.printf("SENT BACK\n");
                  Func2->receiveStatus = false;
                  Func2->outputGate = true;
               

                }
          
        counter++;
}
      }
     else if(MC->current_page==SENDERESPNOW)
     {
       M5.Lcd.clear();
       M5.lcd.setCursor(2,0);
       
              
          Func2->logger = StringFunc;
        if(ESPNOWx==true)
              {
                M5.Lcd.clear();
                M5.lcd.setCursor(2,0);
                M5.Lcd.setTextSize(3);
                M5.lcd.println("Sending.....");
                delay(500);
                
                
                  Func2->initESPNOW(&globalpeerInfo,broadcastAddress);
                  Func2->setReference(Func2);
                  
               
     
    ESPNOWx = false;
              }
        myData.a[0] = position;
        for(int i = 1; i < 248; i++)
        {
            myData.a[i] = (byte) i;
        }
 
        
      

        
        Serial.printf("%d",sizeof(myData));
        
        Func2->send(broadcastAddress,sizeof(myData),(uint8_t*)&myData);
       
     }
     else if(MC->current_page == SenderLora)
     {
       Serial.printf("LOOOOORAAAA\n");
       M5.Lcd.clear();
        M5.Lcd.setTextColor(TFT_RED);
        M5.Lcd.printf("Generating Data..\n");
         Serial.printf("GENERATE DATA\n");
         delay(1000);
       
         Serial.printf("READ TASK\n");

  
       if(x==0)
       {
         Func3->init();
       }
       byte datax[1];
        datax[0] = position;
        byte empty[1];
       Func3->send(datax,sizeof(position),empty);
       
       x++;
       MC->current_page->Line = 1;
       MC->display(MC->current_page->Line);
       M5.Lcd.setTextColor(TFT_GREEN);
       M5.Lcd.printf("CurrentLocation: %s\n",CurrentLocation);
       if(empty[0] != 0xFF)
       M5.Lcd.printf("NO ACK\n");
       else
       M5.Lcd.printf("ACK  %02x was received\n",empty[0]);
       delay(2000);
       globalFile = SD.open("/log.txt",FILE_APPEND);
       if(globalFile)
       {
    Serial.printf("FILE OPENDED\n");
       }
      else 
      {
        M5.Lcd.clear();
        M5.Lcd.printf("RECORD NOT POSSIBLE\nPLEASE MAKE RESET\n");
        while(1);
        Serial.printf("Open Error\n");
      }

      globalFile.println(StringFunc);
      globalFile.printf("Data %s was sent\n",CurrentLocation);
      globalFile.printf("Data %02x was received\n",empty[0]);
      globalFile.close();
     
       StringFunc = ""; 
     } 
     else if(MC->current_page == ReceiveLora)
     {
       M5.Lcd.clear();
        M5.lcd.setCursor(2,0);
        M5.Lcd.printf("Waiting .... \n");
        if(t==0)
        {
          
          Func3->init();
          Serial.printf("INITIALIED..\n");
      
          t++;
        }
        globalFile = SD.open("/log.txt",FILE_APPEND);
        globalFile.println(StringFunc);

     
          int ini = 1;
        while(1)
        {
          M5.update();
          if(M5.BtnC.wasReleased())
          {
            break;
          }
          byte * receivepar;
          int xx;
          if(Serial2.available() >0)
          {
            Serial.printf("TEST\n");
         xx = Func3->receive(1,receivepar);}
          if(xx == 1 || ini == 1)
          {
            M5.Lcd.clear();
            M5.lcd.setCursor(2,0);
            M5.Lcd.printf("Waiting...\n");
            xx = 0;
            ini = 0;
            
          }
          
        }
     }
     if(MC->current_page==Byterefx || MC->current_page == Byteref)
     {
       MC->prompt = "Protokoll";
     }
     else if(MC->current_page== receiveStandort || MC->current_page == sendStandort)
     {
       MC->prompt = StartFunc;
     }
  if(MC->current_page!=test && MC->current_page != testR && MC->current_page != RECEIVEESPNOW && MC->current_page != SENDERESPNOW && MC->current_page!=deleteSD && MC->current_page != SenderLora)
  { MC->current_page->Line = 1;
        MC->display(MC->current_page->Line);
  }
  }
  else if(M5.BtnC.wasReleased())
  {
  
    Serial.printf("BUTTON C WAS CALLED\n");
    if(!MC->stackxy.isEmpty())
    MC->current_page = MC->pop();
    Serial.printf("POPED  %s\n",MC->current_page->txt);
    if(MC->current_page == sendStandort)
    {
      MC->prompt = StartFunc;
      M5.Lcd.clear();
      M5.Lcd.printf("DATA LOGGED....\n");
      globalFile.close();
      id = 1;
      delay(1000);
    }
    if(MC->current_page == receiveStandort)
    {
      MC->prompt = StartFunc;
      M5.Lcd.clear();
      M5.Lcd.printf("DATA LOGGED....\n");
      globalFile.close();
      id = 1;
      delay(1000);
    }
    if(MC->current_page == Sender_ReceiverG)
    {
      MC->prompt = "initial";
    }
    if(MC->current_page == Byteref || MC->current_page == Byterefx || MC->current_page == start_menuG || MC->current_page == Sender_ReceiverG)
    {
      M5.Lcd.clear();
     
      Serial.printf("PLEASE RESET\n");
      M5.Lcd.setTextColor(TFT_RED);
      M5.lcd.setCursor(0,25);
      M5.lcd.setTextSize(3);
      M5.Lcd.print("PLEASE RESET");
      delay(5000);
      while(1);
    }

   
    Serial.printf("VALUE SET\n");
    MC->display(MC->current_page->Line);
    Serial.printf("BTNC LEEEEFT\n");
  }

}