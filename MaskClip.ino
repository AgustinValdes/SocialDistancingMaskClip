#include <dht.h>
#define trigPin 3
#define echoPin 2
#define DHT11_PIN 4
const int flash = 5;
const int beep = 6;
const int byPassButton = 7;
int buttonState = 0;
int state = 0;
const int maxDistance = 400; //cms
const int minDistance = 2; //cms
dht DHT;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(flash, OUTPUT);
  pinMode(beep, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(byPassButton, INPUT_PULLUP);

}

void loop() {
  // put your main code here, to run repeatedly:
  if (state == 0){
    //Button Read
    int buttonState = digitalRead(byPassButton);
    //Variable Set-up for Distance Calculations
    float duration, distance;
    float speed;
    //Send pulses of sound and await for response
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);
    speed = 331.4 + (0.606 * DHT.temperature) + (0.0124 * DHT.humidity);
    distance = (duration/2) * (speed / 10000); // Distance in centimeters

    Serial.print("Distance:");
    Serial.println(distance);
    delay(100);
    if (distance <= minDistance || distance >= maxDistance){
      Serial.print("Out of range");
      digitalWrite(flash, LOW);
      state = 0;
    }
    else if(buttonState == HIGH){ //not really sure what to do here
      digitalWrite(flash, LOW);
      analogWrite(beep, 0);
      delay(30000);
    }
    else{
      Serial.print("Distance:");
      Serial.println(distance);
      delay(100);
      if (distance <= 183){
        digitalWrite(flash, HIGH);
        analogWrite(beep, 1);
        delay(50);
        analogWrite(beep,0);
        state = 0; 
      }
      else{
        digitalWrite(flash, LOW);
        state = 0;
      }
    }
  delay(100);  
  }
}
