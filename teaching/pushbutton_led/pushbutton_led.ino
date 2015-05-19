int ledApin = 9;
int ledBpin = 10;
int ledCpin = 11;

int btnApin = 2;
int btnBpin = 3;
int btnCpin = 4;
int btnDpin = 5;

int red = 0;
int blue = 0;
int green = 0;

void setup() {
  pinMode(ledApin, OUTPUT);
  pinMode(ledBpin, OUTPUT);
  pinMode(ledCpin, OUTPUT);
  pinMode(btnApin, INPUT_PULLUP);
  pinMode(btnBpin, INPUT_PULLUP);
  pinMode(btnCpin, INPUT_PULLUP);
  pinMode(btnDpin, INPUT_PULLUP);
}
/*
void loop() {
  if (digitalRead(btnApin) == LOW) {
    digitalWrite(ledApin, HIGH);
  }
  if (digitalRead(btnBpin) == LOW) {
    digitalWrite(ledBpin, HIGH);
  }
  if (digitalRead(btnCpin) == LOW) {
    digitalWrite(ledCpin, HIGH);
  }
  if (digitalRead(btnDpin) == LOW) {
    digitalWrite(ledApin, LOW);
    digitalWrite(ledBpin, LOW);
    digitalWrite(ledCpin, LOW);
  }
}
*/

int onoff = false;
int stat = 0;

void loop() {
  if (digitalRead(btnApin) == LOW) {
    onoff = false;
    analogWrite(ledApin, 255);
    analogWrite(ledBpin, 0);
    analogWrite(ledCpin, 0);
  }
  if (digitalRead(btnBpin) == LOW) {
    onoff = false;
    analogWrite(ledApin, 200);
    analogWrite(ledBpin, 70);
    analogWrite(ledCpin, 0);
  }
  if (digitalRead(btnCpin) == LOW) {
    onoff = false;
    analogWrite(ledApin, 0);
    analogWrite(ledBpin, 255);
    analogWrite(ledCpin, 0);
  }
  if (digitalRead(btnDpin) == LOW) {
    onoff = true;
    analogWrite(ledApin, 0);
    analogWrite(ledBpin, 0);
    analogWrite(ledCpin, 0);
  }
  if (onoff == true) {
    analogWrite(ledApin, 0);
    analogWrite(ledBpin, stat);
    analogWrite(ledCpin, 0);
    delay(1000);
    if (stat == 0) stat = 255;
    else stat = 0;
  }
 
  delay(10);
}

