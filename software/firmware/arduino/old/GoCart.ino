/*
   Electrical Go-cart for testing windmills

   -> reading the gaspedal

   by oliver, lieven, yannick, laurent, ann
   oct 2017
*/

const int pedalPin = A0;
const int motor1_pin = 5; // all PWM
const int motor2_pin = 6;
const int pwmLed1_pin = 9;
const int pwmLed2_pin = 10;

int pwmMotor1,
    pwmMotor2,
    pwmLed1,
    pwmLed2;

void setup() {
  pinMode(pedalPin, INPUT);
  pinMode(motor1_pin, OUTPUT);
  pinMode(motor2_pin, OUTPUT);
  pinMode(pwmLed1_pin, OUTPUT);
  pinMode(pwmLed2_pin, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // read gaspedal
  int gaspedal = analogRead(pedalPin);

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
