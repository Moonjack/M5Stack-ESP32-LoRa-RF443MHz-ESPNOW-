/*
#include "LoRa_E22.h"
class Lora  {
public:
void init();
void send(String byte);
bool  receive();

};
*/
#ifndef Lora_H
#define Lora_H
#include "FuncModule.h"
class Lora : public FuncModule {

public:
//virtual void init(); 
virtual void initSender();
void init();
void send(byte * byte,size_t size, uint8_t * savebytes);
int receive(int len, byte *receiveBytepar);

};
#endif