#include <ESP32Servo.h>

const int hallPin = 5;
const int pink_servoPin = 18; //PINK TOP ONE
const int blue_servoPin = 16;
const int red_servoPin = 15;

Servo pink_servo;
Servo blue_servo;
Servo red_servo;

int lastHallState = HIGH;
bool rest_pos = true;

void setup() {
  pinMode(hallPin, INPUT);
  
  pink_servo.attach(pink_servoPin);
  blue_servo.attach(blue_servoPin);
  red_servo.attach(red_servoPin);

  // Rest position
  delay(500);
  // Old values: Blue=180, Pink=164, Red=82
  // New values: Blue=180, Pink = 162, Red = 84
  blue_servo.write(180);
  delay(500);
  pink_servo.write(161);
  delay(500);
  red_servo.write(84);
  
  Serial.begin(115200);
}

void loop() {
  int currentHallState = digitalRead(hallPin);
  
  if (lastHallState == HIGH && currentHallState == LOW) {
    
    // Grab the record
    for(int pos = 180; pos >= 101; pos-=1){
      blue_servo.write(pos);
      delay(50);
    }

    // Lift the record 
    red_servo.write(80);
    delay(500);
    pink_servo.write(160);
    delay(500);

    delay(200);
    red_servo.write(70);
    delay(200);
    pink_servo.write(150);
    delay(200);
    red_servo.write(60);
    delay(200);
    pink_servo.write(130);
    delay(200);
    red_servo.write(50); //flipping height reached
    delay(200);

    // Flip the record and reseat
    for(int pos = 130; pos >= 50; pos--){
      pink_servo.write(pos);
      delay(20);
    }
    delay(500);
    for(int pos = 50; pos <= 70; pos++){
      red_servo.write(pos);
      delay(20);
    }
    delay(500);
    for(int pos = 50; pos >= 36; pos--){
      pink_servo.write(pos);
      delay(50);
    }
    delay(500);
    
    // Realign, drop, and move away

    for(int pos = 101; pos >= 100; pos-=1){
      blue_servo.write(pos);
      delay(500);
    }
    delay(500);
    
    for(int pos = 70; pos <= 84; pos++){
      red_servo.write(pos);
      delay(20);
    }
    delay(500);

    // Restore to rest

    for(int pos = 100; pos >= 40; pos-=1){
      blue_servo.write(pos);
      delay(20);
    }

    for(int pos = 84; pos >=50; pos--){
      red_servo.write(pos);
      delay(20);
    }

    for(int pos = 40; pos <= 101; pos++){
      blue_servo.write(pos);
      delay(20);
    }

    // Flip back
    for(int pos = 36; pos <= 166; pos++){
      pink_servo.write(pos);
      delay(20);
    }
    delay(500);
    blue_servo.write(180);
    delay(500);
    red_servo.write(84);
  }
  else {
    delay(100);
  }
  lastHallState = currentHallState;
  delay(10);
}
