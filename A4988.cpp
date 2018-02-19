#include "A4988.h"

A4988::A4988(int pin_enable, int pin_step, int pin_direction) {
  pinMode(pin_enable, OUTPUT);
  pinMode(pin_step,OUTPUT);
  pinMode(pin_direction,OUTPUT);
  digitalWrite(pin_enable,LOW);
  _pin_enable    = pin_enable;
  _pin_step      = pin_step;
  _pin_direction = pin_direction;

  _deltime = 500;
}

void A4988::setdeltime(int deltime) {
  _deltime = deltime;
}

void A4988::move_steps(int steps) {
  if (steps > 0) {
    digitalWrite(_pin_direction, HIGH); // Set Dir High　→　回転方向をセット
  } else if (steps < 0) {
    digitalWrite(_pin_direction, LOW); // Set Dir High　→　回転方向をセット
  } else {
    return;
  }
  
  for (int i = 0; i < abs(steps); i++) {
    digitalWrite(_pin_step,HIGH); // 5番ピンをHigh状態へ
    delayMicroseconds(500); // ５００ｍｓ待って
    digitalWrite(_pin_step,LOW); // 5番ピンをLow状態へ
    delayMicroseconds(_deltime); // ５００ｍｓ待って 
  }
}

