
int val1;
int val2;
int count1 = 0;
int count2 = 0;
int in;
int out;
//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////

// RemoteXY select connection mode and include library 
#define REMOTEXY_MODE__ESP8266WIFI_LIB_CLOUD
#include <ESP8266WiFi.h>

#include <RemoteXY.h>

// RemoteXY connection settings 
#define REMOTEXY_WIFI_SSID "HomeBroadband2"
#define REMOTEXY_WIFI_PASSWORD "0143226216"
#define REMOTEXY_CLOUD_SERVER "cloud.remotexy.com"
#define REMOTEXY_CLOUD_PORT 6376
#define REMOTEXY_CLOUD_TOKEN "ed4dd648df885adb09af0d20a33b447b"
#define REMOTEXY_ACCESS_PASSWORD "1234"

// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =
  { 255,0,0,22,0,64,0,10,13,0,
  67,5,46,14,33,8,2,26,11,67,
  5,47,37,32,7,2,26,11,129,0,
  11,15,18,6,24,105,110,0,129,0,
  10,38,18,6,24,111,117,116,0,129,
  0,28,3,42,6,109,112,105,112,111,
  108,101,32,99,111,117,110,116,101,114,
  0 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // output variables
  char text_in[11];  // string UTF8 end zero 
  char text_out[11];  // string UTF8 end zero 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop)

/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////



void setup() 
{
  RemoteXY_Init (); 
  Serial.begin(115200);
pinMode(D6,INPUT); 
pinMode(D2,INPUT); 

Serial.println("\nWIFI IS CONNECTED");
Serial.println(WiFi.localIP());
  
  // TODO you setup code
  
}

void loop() 
{ 
  RemoteXY_Handler ();
  int val= digitalRead(D6);
  int va2= digitalRead(D5);
if(val == LOW ){
 
 in = count1++;
 
 
  Serial.print("in");
  Serial.println(in);
  delay(2000);
 }
if(va2 == LOW) {

  
 out = count2++;
 

  Serial.print("out");
  Serial.println(out);
  delay(2000);
}
  
dtostrf(in,0,1,RemoteXY.text_in);
dtostrf(out,0,1,RemoteXY.text_out);
  
  // TODO you loop code
  // use the RemoteXY structure for data transfer
  // do not call delay() 


}
