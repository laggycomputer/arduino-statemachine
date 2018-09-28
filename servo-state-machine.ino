const int manualPin=10;
const int neutralPin=11;
const int autoPin=12;
const int buttonPin=13;
int state=1;
int buttonState;
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

void loop() {
  // put your main code here, to run repeatedly:
  buttonState=digitalRead(buttonPin);
  if (buttonState==LOW){
    state++;
    if (state==4){
      state=1;
    }
  }
  if(state==1){
    digitalWrite(manualPin, HIGH);
    digitalWrite(autoPin, LOW);
  }
  if(state==2){
    digitalWrite(manualPin, LOW);
    digitalWrite(neutralPin, HIGH);
   }
  if(state==3){
    digitalWrite(neutralPin, LOW);
    digitalWrite(autoPin, HIGH);
  }
  delay(100);
}
