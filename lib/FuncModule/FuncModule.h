#ifndef FuncModule_H
#define FuncModule_H
class FuncModule {

public:
virtual void initSender()=0;
virtual void init()=0;
//virtual void send(byte * byte, size_t size, byte * savepointer)=0;
virtual void send(byte * byte, size_t size, uint8_t * savebytes) = 0;
virtual int receive(int len, byte *receiveBytepar)=0;
};
#endif