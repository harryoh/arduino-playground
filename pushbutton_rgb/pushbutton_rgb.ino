int redLedPin = 9;
int greenLedPin = 10;
int blueLedPin = 11;

int redButtonPin = 7;
int greenButtonPin = 6;
int blueButtonPin = 5;

int red = 0;
int blue = 0;
int green = 0;

void setup() {
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT);
  pinMode(redButtonPin, INPUT_PULLUP);
  pinMode(greenButtonPin, INPUT_PULLUP);
  pinMode(blueButtonPin, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(redButtonPin) == LOW) {
    red++;
    if (red > 255) red = 0;
  }
  if (digitalRead(greenButtonPin) == LOW) {
    green++;
    if (green > 255) green = 0;
  }
  if (digitalRead(blueButtonPin) == LOW) {
    blue++;
    if (blue > 255) blue = 0;
  }
  analogWrite(redLedPin, red);
  analogWrite(greenLedPin, green);
  analogWrite(blueLedPin, blue);
  delay(10);
}
