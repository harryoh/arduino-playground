int speakerPin = 12;
int photocellPin = 0;

void setup() {
}

void loop() {
  int reading = analogRead(photocellPin);
  int pitch = 100 + reading / 2;
  tone(speakerPin, pitch);
}
