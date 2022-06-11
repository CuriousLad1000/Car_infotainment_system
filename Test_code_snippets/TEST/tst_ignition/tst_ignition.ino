#include <SoftwareSerial.h>
#include <Nextion.h>

SoftwareSerial nextion(A4, A3);
Nextion myNextion(nextion, 9600);

void setup() {
  Serial.begin(9600);
  myNextion.init();
  pinMode(13, OUTPUT);

}

void loop() {

  String message = myNextion.listen(); //check for message
  if (message == "65 0 8 1 ffff ffff ffff")
  {
    Serial.println("Start");
    digitalWrite(13, HIGH);
  }
  if (message == "65 0 8 0 ffff ffff ffff")
  {
    Serial.println("STOP");
    digitalWrite(13, LOW);
  }
}

