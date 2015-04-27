int ledPin = 5;
int buttonApin = 9;
int buttonBpin = 8;
 
void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonApin, INPUT_PULLUP);
  pinMode(buttonBpin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(buttonApin) == LOW) {
    digitalWrite(ledPin, HIGH);
    Serial.println("Push A Button");
  }
  if (digitalRead(buttonBpin) == LOW) {
    digitalWrite(ledPin, LOW);
    Serial.println("Push B Button");
  }
}
