//#include <Servo.h>
const int manualPin = 10;
const int neutralPin = 11;
const int autoPin = 12;
const int buttonPin = 13;
const int knobPin = "A0";
//const int servoPin=0;
int state = 1;
int buttonState;
int pressProcessed = false;
int knobVal;
//Servo servo;
void setup() {
  pinMode(manualPin, OUTPUT);
  pinMode(neutralPin, OUTPUT);
  pinMode(autoPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(knobPin, INPUT);
  digitalWrite(manualPin, LOW);
  digitalWrite(neutralPin, LOW);
  digitalWrite(autoPin, LOW);
  //servo.attach(servoPin);
}
void fade(int pin) {
  for (int fadeValue = 0; fadeValue <= 255; fadeValue += 5) {
    analogWrite(pin, fadeValue);
    delay(15);
  }
  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
    analogWrite(pin, fadeValue);
    delay(15);
  }
}
void loop() {
  buttonState = digitalRead(buttonPin);
  knobVal=analogRead(knobPin);
  knobVal = map(knobVal, 0, 1023, 0, 180);
  if (buttonState == LOW) {
    if (pressProcessed == false) {
      state++;
      if (state == 4) {
        state = 1;
      }
      pressProcessed = true;
    }
  }
  else {
    pressProcessed = false;
  }
  if (state == 1) {
    fade(manualPin);
    digitalWrite(manualPin, HIGH);
    digitalWrite(autoPin, LOW);
    //servo.write(knobVal);
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
    /*servo.write(180);
    delay(100);
    servo.write(0);
    */
  }
  delay(100);
}
