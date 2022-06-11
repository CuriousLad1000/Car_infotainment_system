/*

Ricardo Mena C
ricardo@crcibernetica.com
http://crcibernetica.com

  This example code is in public domain

*/

#include <SoftwareSerial.h>
#include <Nextion.h>

SoftwareSerial nextion(A3, A4);// Nextion TX to pin A3 and RX to pin A4 of Arduino

Nextion myNextion(nextion, 9600); //create a Nextion object named myNextion using the nextion serial port @ 9600bps

void setup() {
  Serial.begin(9600);
  myNextion.init();

}

void loop() {
  String message = myNextion.listen(); //check for message
  if(message != ""){ // if a message is received...
    Serial.println(message); //...print it out
  }

  
}
