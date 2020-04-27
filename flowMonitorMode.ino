#define BLYNK_PRINT Serial
#include<SoftwareSerial.h>
SoftwareSerial DebugSerial(2,3); //Rx, Tx 

#include <BlynkSimpleSerialBLE.h>
char auth[] = "G84e-567363VooNzZoNoq-Sly8XFvA47"; 

float inhalePres ; 
float p1,p2,final_presure;
const int sens_p1 = A1; 
const int sens_p2 = A2;
 //Variables to change
double massFlow = 0; // Mass flow rate calculated from pressure
double volFlow = 0; // Calculated from mass flow rate
double volume = 0; // Integral of flow rate over time
  //Constants
double rho = 1.225; // Density of air in kg/m3
double area_1 =   0.0015904312808798; // Surface area in m2
double area_2 =   0.011309733552923; // Surface area in m2
double dt = 0;

void setup(){
Serial.begin(9600);
DebugSerial.begin(9600);
Blynk.begin(DebugSerial, auth);
  
Serial.println("Waiting for connections...")*/
}

void loop() {
Blynk.run();
  
inhalePres = analogRead(A5);
Blynk.virtualWrite(V7, inhalePres);
delay(50);
p1 = analogRead(sens_p1);
p2 = analogRead(sens_p2);
final_presure = p1 - p2 ;
massFlow = 1000*sqrt((abs(final_presure-36666)*2*rho)/((1/(pow(area_2,2)))-(1/(pow(area_1,2))))); // Massflow of air
volFlow = massFlow/rho; // Volumetric flow of air
volume = volFlow*dt + volume; // Total volume (essentially integrated over time)
dt = 0.001;
delay(1);
Blynk.virtualWrite(V5, volume);
Serial.print("Volume :");
Serial.print(volume);
Serial.println();
}
