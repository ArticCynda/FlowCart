/*
   Electrical Go-cart for testing windmills

   -> reading the gaspedal

   by oliver, lieven, yannick, laurent, ann
   oct 2017
*/
#include <Arduino.h>

const uint8_t pedalPin    = A0;
const uint8_t motor1_pin  = 5; // all PWM
const uint8_t motor2_pin  = 6;
const uint8_t pwmLed1_pin = 9;
const uint8_t pwmLed2_pin = 10;

uint8_t pwmMotor1,
        pwmMotor2,
        pwmLed1,
        pwmLed2;

void setup() {
  pinMode(pedalPin, INPUT);
  pinMode(motor1_pin, OUTPUT);
  pinMode(motor2_pin, OUTPUT);
  pinMode(pwmLed1_pin, OUTPUT);
  pinMode(pwmLed2_pin, OUTPUT);

  Serial.begin(115200);
}

void loop() {
  // read gaspedal
  uint16_t gaspedal = analogRead(pedalPin);

  // map and set variables
  // gaspedal input: min 169 - max 875
  pwmMotor1 = pwmMotor2 = map(gaspedal, 169, 875, 0, 255);
  pwmLed1 = pwmMotor1;
  pwmLed2 = pwmMotor2;

  // pwm Leds of motors & LEDs
  analogWrite(motor1_pin, pwmMotor1);
  analogWrite(motor2_pin, pwmMotor2);
  analogWrite(pwmLed1_pin, pwmLed1);
  analogWrite(pwmLed2_pin, pwmLed2);

  // debug
  Serial.println(pwmMotor1);
  Serial.println(pwmMotor2);
}
