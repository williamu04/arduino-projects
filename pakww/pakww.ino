#include <EEPROM.h>

int pinSensor = A5;
const int pinRelay = 7;

int nilaiSensor = 0;

void setup() {
  Serial.begin(9600);
  pinMode(pinRelay, OUTPUT);
  digitalWrite(pinRelay, HIGH);
}

void loop() {
  nilaiSensor = analogRead(pinSensor);
  Serial.print("Sensor =");
  Serial.println(nilaiSensor);
  if(nilaiSensor > 200) {
    delay(500);
  }

  while(true) {
    digitalWrite(pinRelay, LOW);
    nilaiSensor = analogRead(pinSensor);
    if(nilaiSensor > 200) {
      break;
      delay(500);
    } else {
      digitalWrite(pinRelay, HIGH);
    }
  }
}