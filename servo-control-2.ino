#include <Servo.h>
const int manualPin = 10;
const int neutralPin = 11;
const int autoPin = 12;
const int buttonPin = 13;
const int knobPin = A0;
const int servoPin = 9;
int state = 1;
int buttonState;
int pressProcessed = false;
int knobVal;
int spinDir = 1;
int servopos = 0;
Servo servo;
void setup() {
  Serial.begin(9600);
  pinMode(manualPin, OUTPUT);
  pinMode(neutralPin, OUTPUT);
  pinMode(autoPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(knobPin, INPUT);
  digitalWrite(manualPin, LOW);
  digitalWrite(neutralPin, LOW);
  digitalWrite(autoPin, LOW);
  servo.attach(servoPin);
}
void fade(int pin) {
  /*
    for (int fadeValue = 0; fadeValue <= 255; fadeValue += 5) {
    analogWrite(pin, fadeValue);
    delay(15);
    }
    for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
    analogWrite(pin, fadeValue);
    delay(15);
    }
  */
  return;
}
void loop() {
  buttonState = digitalRead(buttonPin);
  knobVal = analogRead(knobPin);
  knobVal = map(knobVal, 0, 1023, 0, 180);
  if (buttonState != digitalRead(buttonPin)) {
    if (buttonState == LOW) {
      state++;
    }
  }
  if (state == 1) {
    fade(manualPin);
    digitalWrite(manualPin, HIGH);
    digitalWrite(autoPin, LOW);
    servopos = knobVal;
    servo.write(servopos);
  }
  if (state == 2) {
    fade(neutralPin);
    digitalWrite(manualPin, LOW);
    digitalWrite(neutralPin, HIGH);
  }
  if (state == 3) {
    fade(autoPin);
    digitalWrite(neutralPin, LOW);
    digitalWrite(autoPin, HIGH);
    if (spinDir == 1) {
      servopos++;
      if (servopos > 180) {
        servopos = 180;
        spinDir = 0;
      }
    }
    if (spinDir == 0) {
      servopos--;
      if (servopos < 0) {
        servopos = 0;
        spinDir = 1;
      }
    }
    servo.write(servopos);
  }
  if (state == 4) {
    state = 1;
  }
  Serial.print("State is ");
  Serial.print(state);
  Serial.print("\n\r");
  delay(10);
}
