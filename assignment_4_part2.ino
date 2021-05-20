// assignment 4 question 2&3

#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run make menuconfig to and enable it
#endif

BluetoothSerial SerialBT;
int selected;
char supply;

const char turnON ='O';
const char turnOFF ='F';
const int LED = 15;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32"); 
  Serial.println("The device started, now you can pair it with bluetooth!");
  Serial.println("To turn ON WATER SUPPLY CHOOSE: O");  
  Serial.println("To turn OFF WATER SUPPLY CHOOSE: F"); 
  pinMode(LED, OUTPUT);
 
}

void loop() {
    supply =(char)SerialBT.read();

  if (Serial.available()) {
    SerialBT.write(Serial.read());
