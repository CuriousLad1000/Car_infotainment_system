//========== HEADERS==================
#include <LiquidCrystal.h>
#include <NewPing.h>
#include "DHT.h"
#define DHTTYPE DHT22   // DHT 22  (AM2302)
#include <SoftwareSerial.h>

//==========  LCD  =================================================
int RS = 12;
int En = 11;
int D4 = 5;
int D5 = 4;
int D6 = 3;
int D7 = 2;
LiquidCrystal lcd(RS, En, D4, D5, D6, D7);

//============ RELAY ===========================================
int Rel_fan = 14;
int Rel_pow_tab = 15;
int Rel_switch_tab = 16;


//======== BLUETOOTH REVERSE SIGNAL ============================
int Soft_RX = 1;
int Soft_TX = 0;
int Reverse_Int = 8;
SoftwareSerial mySerial(Soft_RX, Soft_TX); // RX, TX

//================== ULTRA SONIC ================================
const int trigPin = 18;
const int echoPin = 17;
int BuzPin_vcc = 19;

long microsecondsToCentimeters(long microseconds)
{
  return microseconds / 29 / 2;
}

void ultra()
{
  digitalWrite(BuzPin_vcc, LOW);
  //  digitalWrite(BuzPin_gnd, LOW);
  long duration, inches, cm;
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

  cm = microsecondsToCentimeters(duration);
  lcd.setCursor(0, 1);
  lcd.print("Distance: ");
  lcd.setCursor(9, 1);
  lcd.print(cm);
  lcd.print("   ");
  lcd.setCursor(12, 1);
  lcd.print("cm");
  if (cm >= 2 && cm <= 10)
  {
    digitalWrite(BuzPin_vcc, HIGH);
    delay(1000);
    digitalWrite(BuzPin_vcc, LOW);
  }
}

//===========Temp_Sens_DHT22 ===================================
int Temp_sens_pin = 9;
int fan_stat = 0;
float Temp_LT = 31.00;                    //  temperature in deg Celcius above which fan activates
DHT dht(Temp_sens_pin, DHTTYPE);

void Temp_sens()
{
  delay(1000);
  float t = dht.readTemperature();
  digitalWrite(Rel_pow_tab, LOW); //  CHARGING TAB ON
  if (t > Temp_LT)
  {
    digitalWrite(BuzPin_vcc, HIGH);
    delay(500);
    digitalWrite(BuzPin_vcc, LOW);
    delay(100);
    fan_stat = 1;
    digitalWrite(Rel_fan, LOW); //  FAN ON
  }
  else
  {
    fan_stat = 0;
    digitalWrite(Rel_fan, HIGH); // FAN OFF
  }
  Temp_disp();
}

void Temp_disp()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (isnan(h) || isnan(t))
  {
    return;
  }
  float hic = dht.computeHeatIndex(t, h, false); // Compute heat index in Celsius (isFahreheit = false)
  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(t);
  lcd.setCursor(6, 0);
  lcd.print((char)223);
  lcd.print("C");
  lcd.setCursor(9, 0);
  lcd.print("H:");
  lcd.print(h);
  lcd.setCursor(15, 0);
  lcd.print("%");
  lcd.setCursor(0, 1);
  lcd.print("Fan:");
  if (fan_stat == 0)
  {
    lcd.print("OFF");
  }
  else
  {
    lcd.print("ON");
    lcd.setCursor(6, 1);
    lcd.print(" ");
  }
  lcd.setCursor(8, 1);
  lcd.print("Hi:");
  lcd.print(hic);
  lcd.setCursor(15, 1);
  lcd.print((char)223);
  lcd.print("C");
}
//========================================= Tenp and Power Control =====================================================================
void Temp_init()
{
  delay(2000);
  float t = dht.readTemperature();
  if (t > Temp_LT)
  {
    fan_stat = 1;
    digitalWrite(Rel_pow_tab, HIGH); // CHARGING TAB OFF
    digitalWrite(Rel_fan, LOW); //  FAN ON
    digitalWrite(Rel_switch_tab, HIGH); // DO NOT POWER ON TAB
  }
  else
  {
    fan_stat = 0;
    digitalWrite(Rel_pow_tab, LOW); //  CHARGING TAB ON
    digitalWrite(Rel_fan, HIGH); // FAN OFF

    digitalWrite(Rel_switch_tab, LOW); // POWER ON TAB
    delay(2000);                       // POWER ON TAB
    digitalWrite(Rel_switch_tab, HIGH); // POWER ON TAB
  }
  Temp_disp();
}



//===========================  SETUP  ===================================================================  SETUP  ====================  SETUP  ===============================
void setup()
{
  pinMode(Rel_fan, OUTPUT);
  pinMode(Rel_pow_tab, OUTPUT);
  pinMode(Rel_switch_tab, OUTPUT);
  pinMode(BuzPin_vcc, OUTPUT);
  pinMode(Reverse_Int, OUTPUT);
  digitalWrite(Reverse_Int, LOW);
  mySerial.begin(9600);
  lcd.begin(16, 2); // set up the LCD's number of columns and rows:
  dht.begin();
  Temp_init();
}

//===========================  LOOP  ===================================================================  LOOP  ====================  LOOP  ===============================
void loop()
{
  if (digitalRead(Reverse_Int) == HIGH)
  {
    mySerial.print(1);
    while (digitalRead(Reverse_Int) == HIGH)
    {
      Temp_sens();
      ultra();
    }
  }
  else
  {
    mySerial.print(0);
    while (digitalRead(Reverse_Int) == LOW)
    {
      Temp_sens();
    }
  }
}

