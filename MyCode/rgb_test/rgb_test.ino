int rpin = 8;
int gpin = 9;
int bpin = 10;

void setup() {
  pinMode(rpin, OUTPUT);
  pinMode(gpin, OUTPUT);
  pinMode(bpin, OUTPUT);

}

void loop() {
  setColor(255, 0, 0);
  delay(1000);
  setColor(0, 255, 0);
  delay(1000);
  setColor(0, 0, 255);
  delay(1000);
  setColor(255, 255, 0);
  delay(1000);
  setColor(255, 0, 255);
  delay(1000);
  setColor(0, 255, 255);
  delay(1000);
  setColor(0x48, 255, 0x48);
  delay(1000);

}

void setColor(int r, int g, int b) {
  analogWrite(rpin, r);
  analogWrite(gpin, g);
  analogWrite(bpin, b);
}
