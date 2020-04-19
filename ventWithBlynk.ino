#include<SoftwareSerial.h>
SoftwareSerial DebugSerial(2,3); //Rx, Tx 

#define BLYNK_PRINT DebugSerial
#include <BlynkSimpleSerialBLE.h>
char auth[] = "YourAuthCodeHere"; 

double pressure ;

void setup(){
  DebugSerial.begin(9600);
  DebugSerial.println("waiting for connection");
  Blynk.begin(Serial,auth);
  
  Serial.begin(9600);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  digitalWrite(13,!LOW);
  digitalWrite(11,!HIGH);
  delay(1500);
}
void loop(){
  Blynk.run();
  pressure = analogRead(A5);
  Blynk.virtualWrite(V7, pressure);
  digitalWrite(12,!HIGH);
  digitalWrite(11,!LOW);
  digitalWrite(10,HIGH);
  //Serial.println("relay 1");
  delay(3000);
  pressure = analogRead(A5);
  Blynk.virtualWrite(V7, pressure);
  digitalWrite(12,!LOW);
  digitalWrite(11,!HIGH);
  digitalWrite(10,LOW);
  //Serial.println("relay 2");
  delay(1500);
}
