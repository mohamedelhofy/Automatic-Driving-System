// you can enable debug logging to Serial at 115200
//#define REMOTEXY__DEBUGLOG    
#include <HardwareSerial.h>
HardwareSerial SerialPort(2);





// RemoteXY select connection mode and include library 
#define REMOTEXY_MODE__WIFI_POINT

#include <WiFi.h>

// RemoteXY connection settings 
#define REMOTEXY_WIFI_SSID "RemoteXY"
#define REMOTEXY_WIFI_PASSWORD ""
#define REMOTEXY_SERVER_PORT 6377
#define REMOTEXY_ACCESS_PASSWORD "1234"


#include <RemoteXY.h>

// RemoteXY GUI configuration  
#pragma pack(push, 1)  
uint8_t RemoteXY_CONF[] =   // 97 bytes
  { 255,5,0,0,0,90,0,19,0,0,0,73,84,73,50,0,31,1,106,200,
  1,1,5,0,1,44,100,24,24,0,2,8,85,80,0,1,44,165,24,24,
  0,2,8,68,79,87,78,0,1,13,134,24,24,0,2,8,76,69,70,84,
  0,1,74,134,24,24,0,2,8,82,73,71,72,84,0,2,31,31,44,22,
  0,2,26,31,31,77,97,110,117,97,108,0,65,117,116,111,0 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  uint8_t button_01; // =1 if button pressed, else =0, from 0 to 1
  uint8_t button_02; // =1 if button pressed, else =0, from 0 to 1
  uint8_t button_03; // =1 if button pressed, else =0, from 0 to 1
  uint8_t button_04; // =1 if button pressed, else =0, from 0 to 1
  uint8_t switch_01; // =1 if switch ON and =0 if OFF, from 0 to 1

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0

} RemoteXY;   
#pragma pack(pop)
 


// ================== Pins ==================
#define LED_PIN 2

// ================== Variables ==================
int lastState_x = -1;   // store last button state
int lastState_y = -1;
int lastState_F = -1;
int lastState_B = -1;
int lastState_L = -1;
int lastState_R = -1;
int lastState_Switch = -1;

// ================== Setup ==================
void setup() 
{
  RemoteXY_Init ();
  pinMode(LED_PIN, OUTPUT);

  // UART2: TX=17, RX=16
  SerialPort.begin(9600, SERIAL_8N1, 16, 17);
}

// ================== Loop ==================
void loop() 
{ 
  RemoteXY_Handler ();

  
  int btnState_F = RemoteXY.button_01;
  int btnState_B = RemoteXY.button_02;
  int btnState_L = RemoteXY.button_03;
  int btnState_R = RemoteXY.button_04;
  int btnstate_Switch = RemoteXY.switch_01;
  //int btnState_S = RemoteXY.button_05;


    if ( btnState_R == 1) {
      digitalWrite(LED_PIN, HIGH);
      SerialPort.print("R");   // Right
    }
    else if ( btnState_L == 1)
    {
      digitalWrite(LED_PIN, HIGH);
      SerialPort.print("L");  // Left
    }

    else if (  btnState_F == 1) {
      digitalWrite(LED_PIN, HIGH);
      SerialPort.print("F");   // Forward
    }
    else if ( btnState_B == 1)
    {
      digitalWrite(LED_PIN, HIGH);
      SerialPort.print("B");  // Backward
    }
    else{
      digitalWrite(LED_PIN, LOW);
      SerialPort.print("S");   // Stop
    }
    if (btnstate_Switch == 1)
    {
      digitalWrite(LED_PIN, HIGH);
      SerialPort.print("M");
    }
    else if (btnstate_Switch == 0)
    {
      digitalWrite(LED_PIN, LOW);
      SerialPort.print("A");
    }


    lastState_F = btnState_F;
    lastState_B = btnState_B;
    lastState_L = btnState_L;
    lastState_R = btnState_R;
    lastState_Switch = btnstate_Switch;
    //lastState_S = btnState_S;

    RemoteXY_delay(100); // update every 100 ms
  }