#include <Servo.h>

Servo sX;
Servo sY;

String SerData;

void setup() {
  sX.attach(10);
  sY.attach(11);
  Serial.begin(9600);
  Serial.setTimeout(10);
}

void loop() {
  //nothing
}
void SerialEVT(){
  SerData = Serial.readString();

  sX.write(parseX(SerData));
  sY.write(parseY(SerData));
}

int parseX(String data){
  data.remove(data.indexOf("Y"));
  data.remove(data.indexOf("X"), 1);

  return data.toInt();
}
int parseY(String data){
  data.remove(0, data.indexOf("Y") + 1);

  return data.toInt();
}
