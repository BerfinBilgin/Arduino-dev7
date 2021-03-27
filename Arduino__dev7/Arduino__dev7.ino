#define REMOTEXY_MODE__ESP8266_HARDSERIAL_POINT

#include <RemoteXY.h>

#define REMOTEXY_SERIAL Serial1
#define REMOTEXY_SERIAL_SPEED 115200
#define REMOTEXY_WIFI_SSID "ödev6"
#define REMOTEXY_WIFI_PASSWORD "123456789"
#define REMOTEXY_SERVER_PORT 6377

 
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =
  { 255,1,0,0,0,11,0,11,13,0,
  4,0,41,10,5,42,2,26 };
  

struct {

   
  int8_t slider_1; 

    
  uint8_t connect_flag;   

} RemoteXY;
#pragma pack(pop)




#include <Servo.h>  

Servo servo1;

void setup() 
{
  RemoteXY_Init ();  
  servo1.attach(9); 
  RemoteXY.slider_1 = 50; 
}

void loop() 
{ 
  RemoteXY_Handler ();
  int ms = RemoteXY.slider_1*20+500; 
  servo1.writeMicroseconds(ms); 
}
