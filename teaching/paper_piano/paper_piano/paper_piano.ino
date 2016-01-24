#include<CapacitiveSensor.h>

CapacitiveSensor sensor_2_3 = CapacitiveSensor(2, 3);
CapacitiveSensor sensor_2_4 = CapacitiveSensor(2, 4);
CapacitiveSensor sensor_2_5 = CapacitiveSensor(2, 5);

CapacitiveSensor sensor_8_9 = CapacitiveSensor(8, 9);
CapacitiveSensor sensor_8_10 = CapacitiveSensor(8, 10);

int th = 5;
int LED = 13;
bool flag;
int Do, Re, Mi, Fa, Sol;
String msg;

byte ch = '9';

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop() {
  if (sensor_2_3.capacitiveSensor(30) > th) Do = 1;
  else Do = 0;

  if (sensor_2_4.capacitiveSensor(30) > th) Re = 1;
  else Re = 0;

  if (sensor_2_5.capacitiveSensor(30) > th) Mi = 1;
  else Mi = 0;

  if (sensor_8_9.capacitiveSensor(30) > th) Fa = 1;
  else Fa = 0;

  if (sensor_8_10.capacitiveSensor(30) > th) Sol = 1;
  else Sol = 0;

  if (Do || Re || Mi || Fa || Sol) {
    msg = String(Do) + String(Re) + String(Mi) + String(Fa) + String(Sol);
    digitalWrite(LED, HIGH);
    Serial.println(msg);
  } else {
    digitalWrite(LED, LOW);
  }

  delay(15);
}
