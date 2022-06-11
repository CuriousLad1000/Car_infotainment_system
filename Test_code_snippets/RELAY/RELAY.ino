
#include <SoftwareSerial.h>

int Soft_RX = 1;
int Soft_TX = 0;
int Reverse_Int = 8;
int Rel1= 14;


SoftwareSerial mySerial(Soft_RX, Soft_TX); // RX, TX
void setup()
{
  pinMode(Reverse_Int, OUTPUT);
  pinMode(Rel1, OUTPUT);
  mySerial.begin(9600);
}

void loop()
{

  digitalWrite(Reverse_Int, LOW);
  if (digitalRead(Reverse_Int) == HIGH)
  {
    mySerial.print(1);
    while (digitalRead(Reverse_Int) == HIGH)
    {
      digitalWrite(Rel1, LOW);   //ACTIVATES AT LOW PULSE

      //delay(200);
      //=============BLINK LED CODE ==================================

      //=======================TEMPERATURE SENSOR =======================================

      //Temp_sens = analogRead(Temp_sens_pin);


    }
  }
  else
  {
    mySerial.print(0);
    while (digitalRead(Reverse_Int) == LOW)
    {
      digitalWrite(Rel1, HIGH); //  DE-ACTIVATES AT HIGH PULSE
      //delay(200);
      //=============BLINK LED CODE ==================================

      //=======================TEMPERATURE SENSOR =======================================

      //Temp_sens = analogRead(Temp_sens_pin);

    }
  }
}
