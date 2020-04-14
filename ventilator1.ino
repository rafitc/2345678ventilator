//
 double pressure = 0;
 float set= 5;
 int relay = 10;
 int i = 100;
 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(relay,OUTPUT);
  while(Serial.available()){
    
  }
  String ins = Serial.readString();
  float ins1 = toFloat(ins);
  delay(1000);
  while(Serial.available()){
    
  }
  String esp = Serial.readString();
  float esp1 = toFloat(esp);
  delay(1000);
  while(Serial.available()){
    
  }
  String rate = Serial.readString();
  float rate1 = toInt(rate);
  delay(1000);
  
  preCalib();

}

void loop() {
  digitalWrite(relay,1);
  delay(i-10);
  digitalWrite(relay,0);
  delay(insrate);
}

void rise(){
  digitalWrite(relay,HIGH);
  delay(i);
  pressure = analogRead(A5);
  if(pressure>=set){
    digitalWrite(relay,LOW);
    return 0; 
  }
  else if(pressure<set){
    Serial.println("P lower");
  }
  digitalWrite(relay, LOW);
}

void preCalib(){
  while(pressure>set){
    i=i+100;
      digitalWrite(relay, HIGH);
      delay(i);
      pressure = analogRead(A5);
      digitalWrite(relay, LOW);
       
  } 
}

void ratefinder(){
  float rate1 = 60/rate;
  float insptime = (ins/(ins+esp))*(rate1);
  float esptime = (esp/(ins+esp))*(rate1);
  
}
