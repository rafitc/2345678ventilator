// Blink setup
#define BLYNK_PRINT Serial
#include <SoftwareSerial.h>
SoftwareSerial SwSerial(2, 3); // RX, TX
#include <BlynkSimpleSerialBLE.h>
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "YourAuthToken";


double pres2 ;
double pres1 ;
double prespa;
double massFlow;
double volume =0;
double volFlow = 0;
//const 
double rho = 1.225;
double area_2 = 0.000015904312808798;
double area_1 = 0.00011309733552923;
double dt = 0.001; 

//
double pre;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  SwSerial.begin(9600);
  Blynk.begin(SwSerial, auth);

  Serial.println("Waiting for connections...");
}
void loop(){
  Blynk.run();
  mass();
  Serial.println(volFlow);
  Blynk.virtualWrite(V7, volFlow);
  pre = analogRead(A1);
  Blynk.virtualWrite(V5, pre);
}

void mass() {
  // put your main code here, to run repeatedly:
  pres1 = analogRead(A4);
  pres1 = pres1 - 743;
  pres2 = analogRead(A2);
  pres2 = pres2 - 743;
  if(pres1<0){
    pres1 = 0 ; 
  }
  if(pres2<0){
    pres2 = 0 ;
  }
  /*Serial.print("pres1 ");
  Serial.println(pres1);
  Serial.print(" pres2 ");
  Serial.println(pres2);*/

  prespa = pres2 - pres1;
 // prespa = abs(prespa);
  massFlow = 1000*sqrt((abs(prespa*133.322)*2*rho)/((1/(pow(area_2,2)))-(1/(pow(area_1,2)))));
 volFlow = (massFlow/rho);
 volume = (volFlow*dt) + volume;
 dt=0.001;
 //delay(1);
  delay(1);
  //Serial.print(" volume ");
 // Serial.println(volume);
  }
