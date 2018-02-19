// A4988を用いたステッピングモーター制御
#include "A4988.h"


#define ENA 6   // Enable　→　Arduinoの6番ピンへ
#define STEP 5  // Step →　Arduinoの5番ピンへ
#define DIR 4   // Direction →　Arduinoの4番ピンへ

A4988 stepper(ENA, STEP, DIR);

void setup() { 
  Serial.begin(9600);

}

void loop() {
  if (Serial.available()) {
    String val = Serial.readString();
    Serial.println("move " + val + "steps");
    stepper.move_steps(val.toInt());
  }
}

/*
void rotate(bool dir, int spd) {
  int deltime = spd;
  
  if (dir) {
    digitalWrite(DIR,HIGH); // Set Dir High　→　回転方向をセット
  } else {
    digitalWrite(DIR,LOW); // Set Dir High　→　回転方向をセット
  }
  for (int i = 0; i < 200; i++) {
    digitalWrite(STEP,HIGH); // 5番ピンをHigh状態へ
    delayMicroseconds(500); // ５００ｍｓ待って
    digitalWrite(STEP,LOW); // 5番ピンをLow状態へ
    delayMicroseconds(deltime); // ５００ｍｓ待って 
  }
}

void move_step(bool dir, int steps) {
  if (dir) {
    digitalWrite(DIR,HIGH); // Set Dir High　→　回転方向をセット
  } else {
    digitalWrite(DIR,LOW); // Set Dir High　→　回転方向をセット
  }
  
  for (int i = 0; i < steps; i++) {
    digitalWrite(STEP,HIGH); // 5番ピンをHigh状態へ
    delayMicroseconds(500); // ５００ｍｓ待って
    digitalWrite(STEP,LOW); // 5番ピンをLow状態へ
    delayMicroseconds(1000); // ５００ｍｓ待って 
  }
}
*/
