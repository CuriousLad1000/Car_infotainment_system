#include <SoftwareSerial.h>
#include <Nextion.h>

SoftwareSerial nextion(A4, A3);

Nextion myNextion(nextion, 9600); //create a Nextion object named myNextion using the nextion serial port @ 9600bps
int x = 129;
int width = 211;
int height = 30;
int y1 = 48;
int y2 = 105;
int y3 = 165;


void setup() {
  Serial.begin(9600);
  myNextion.init();

}

void loop() {

  for (int i = 0; i <= 100; i++)
  {
    int j = i;
    String a =  (String(j) + " \xb0" + "C");  //xb0 is for degree symbol
    Serial.println(a); //...print it out

    myNextion.setComponentText("Temperature.tmp0", a);
    int scaled_value = map(j, 0, 100, 0, 100); // always map value from 0 to 100
    myNextion.updateProgressBar(x, y1, width, height, scaled_value, 0, 1); // update the progress bar
    myNextion.updateProgressBar(x, y2, width, height, scaled_value, 0, 1); // update the progress bar
    myNextion.updateProgressBar(x, y3, width, height, scaled_value, 0, 1); // update the progress bar

    delay(10);

  }

}

