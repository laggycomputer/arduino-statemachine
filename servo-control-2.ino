const int manualPin = 10;
const int neutralPin = 11;
const int autoPin = 12;
const int buttonPin = 13;
int state = 1;
int buttonState;
int pressProcessed = false;
//1-3 on state should be man, neutral, and auto
void setup() {
  // put your setup code here, to run once:
  pinMode(manualPin, OUTPUT);
  pinMode(neutralPin, OUTPUT);
  pinMode(autoPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  digitalWrite(manualPin, LOW);
  digitalWrite(neutralPin, LOW);
  digitalWrite(autoPin, LOW);
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
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonPin);
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
    fade(manualPin);    digitalWrite(manualPin, HIGH);
    digitalWrite(autoPin, LOW);

  }
  if (state == 2) {
    fade(neutralPin)
;    digitalWrite(manualPin, LOW);
    digitalWrite(neutralPin, HIGH);
  }
  if (state == 3) {    fade(autoPin);
    digitalWrite(neutralPin, LOW);
    digitalWrite(autoPin, HIGH);
  }
  delay(100);
}
