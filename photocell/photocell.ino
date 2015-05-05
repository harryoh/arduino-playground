int lightPin = 0;
int latchPin = 5;
int clockPin = 6;
int dataPin = 4;
 
int leds = 0;
 
void setup() 
{
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT); 
  pinMode(clockPin, OUTPUT);
 }
 
void loop() 
{
  int reading = analogRead(lightPin);
  if (reading < 57) reading = 57;
  int numLEDSLit = reading / 57; //1023 / 9 / 2
  leds = 0;
  for (int i = 0; i < numLEDSLit; i++)
  {
    bitSet(leds, i); 
  }
  updateShiftRegister();
}
 
void updateShiftRegister()
{
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, leds);
  digitalWrite(latchPin, HIGH);
}
