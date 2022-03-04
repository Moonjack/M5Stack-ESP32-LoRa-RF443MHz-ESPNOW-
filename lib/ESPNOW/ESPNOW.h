#include <FuncModule.h>
#include <esp_now.h>

class ESPNOW : public FuncModule{

  public:
  bool receiveStatus;
  bool senderStatus;
  bool  outputGate = true;
  String logger;
  unsigned long seconds;
  unsigned long hours;
  unsigned long minutes;
  void setReference(ESPNOW * a);
  virtual void init();
 void initSender();
  void initESPNOW(esp_now_peer_info * a,uint8_t * broadcastAddress);
  int receive(int len, byte *receiveBytepar);
 static void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status);
 static void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len);
  void send(uint8_t * address, size_t size, uint8_t * data);
};