int valve_1 = 10;
int valve_2 = 11;

void setup(){
  pinMode(valve_2, OUTPUT);
  pinMode(valve_1, OUTPUT);
}
void loop(){
  digitalWrite(valve_1, !HIGH);
  digitalWrite(valve_2, !LOW);
  delay(3000);
  
  digitalWrite(valve_1, !LOW);
  digitalWrite(valve_2, !HIGH);
  delay(1500);
}
