
#include <SoftwareSerial.h>

int Soft_RX = 1;
int Soft_TX = 0;
int Reverse_Int = 6;



SoftwareSerial mySerial(Soft_RX, Soft_TX); // RX, TX
void setup()
{
  pinMode(Reverse_Int, OUTPUT);
  mySerial.begin(9600);
}

void loop()
{

  digitalWrite(Reverse_Int, LOW);
  if (digitalRead(Reverse_Int) == HIGH)
  {
    mySerial.flush();
    mySerial.print(char(48));
    while (digitalRead(Reverse_Int) == HIGH)
    {
      //delay(200);
      //=============BLINK LED CODE ==================================

      //=======================TEMPERATURE SENSOR =======================================

      //Temp_sens = analogRead(Temp_sens_pin);


    }
  }
  else
  {
    mySerial.flush();
    mySerial.print(0);
    while (digitalRead(Reverse_Int) == LOW)
    {
      //delay(200);
      //=============BLINK LED CODE ==================================

      //=======================TEMPERATURE SENSOR =======================================

      //Temp_sens = analogRead(Temp_sens_pin);

    }
  }
}
