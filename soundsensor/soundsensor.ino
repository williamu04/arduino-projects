int pinSensor = A5;
const int pinRelay = 7;
const int pinLED = 13;

int nilaiSensor = 0;
 
void setup(){
  Serial.begin (2400);
  pinMode (pinRelay, OUTPUT);
  pinMode (pinLED, OUTPUT);
  digitalWrite(pinRelay,LOW);
}
 
void loop() {
  nilaiSensor = analogRead(pinSensor);
  Serial.print ("Sensor = "); 
  Serial.println(nilaiSensor);
  if (nilaiSensor > 65){
    while(true){
      digitalWrite(pinRelay, HIGH);
      digitalWrite(pinLED, HIGH);
      nilaiSensor = analogRead(pinSensor);
      if (nilaiSensor > 65){
        break;
      }
    }
  }
  else {
    digitalWrite(pinRelay, LOW);
    digitalWrite(pinLED, LOW);
  }
}