#include <SoftwareSerial.h>
#include <Nextion.h>

SoftwareSerial nextion(A3, A4);

Nextion myNextion(nextion, 9600); //create a Nextion object named myNextion using the nextion serial port @ 9600bps

void setup() {
  Serial.begin(9600);
  myNextion.init();

}

void loop() {

int Halo = myNextion.getComponentValue("HOME.cmdfoghalo");
int Head = myNextion.getComponentValue("HOME.cmdfogmain");
int AUX = myNextion.getComponentValue("HOME.cmdaux");
int Fan = myNextion.getComponentValue("Temperature.cmdfan");
int Temp_ctrl = myNextion.getComponentValue("Settings.Temp_ctrl");
int Temp_lt = myNextion.getComponentValue("Settings.tmp_lt");

Serial.print("Halo: ");
Serial.println(Halo);
Serial.print("Head: ");
Serial.println(Head);
Serial.print("AUX: ");
Serial.println(AUX);
Serial.print("Fan Status: ");
Serial.println(Fan);
Serial.print("Enable Temperature Control: ");
Serial.println(Temp_ctrl);
Serial.print("Temperature LT: ");
Serial.println(Temp_lt);

Serial.println();
delay(1000);
  
}

