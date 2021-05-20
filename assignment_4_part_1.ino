// assignment 4  questions 1&4

#include "BluetoothSerial.h"
int trigpin=4;
int echopin=5;
BluetoothSerial SerialBT;
void setup() {
  // put your setup code here, to run once:
 pinMode(2,OUTPUT);
Serial.begin(115200);
  Serial.println("data");
  delay(3000);
  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.println("The device has started, now you can pair it with bluetooth!");
pinMode(echopin,INPUT);
pinMode(trigpin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
   if (Serial.available()) {
    SerialBT.write(Serial.read());
  }
  if (SerialBT.available()) {
    Serial.write(SerialBT.read());
  }
digitalWrite(trigpin,HIGH);
delay(1000);
digitalWrite(trigpin,LOW);
