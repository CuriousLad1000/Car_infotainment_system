
#include <SoftwareSerial.h>

int Soft_RX = 17;
int Soft_TX = 18;
int Reverse_Int = 19;



SoftwareSerial mySerial(Soft_RX, Soft_TX); // RX, TX
void setup()
{
  
  pinMode(Reverse_Int, INPUT);
  mySerial.begin(9600);
  Serial.begin(9600);
}

void loop()
{

  digitalWrite(Reverse_Int, HIGH);
  if (digitalRead(Reverse_Int) == HIGH)
  {
    mySerial.flush();
    mySerial.print(char(48));
    Serial.println("HI");
    //Serial.println(bitRead(PORTD,19));
    while (digitalRead(Reverse_Int) == HIGH)
    {
     
    }
  }
  else
  {
    mySerial.flush();
    mySerial.print(0);
    Serial.println("low");
    //Serial.println(bitRead(PORTD,19));
    while (digitalRead(Reverse_Int) == LOW)
    {
     
    }
  }
}
