#include <SoftwareSerial.h>
#include <Nextion.h>
#include "DHT.h"
#define DHTTYPE DHT22   // DHT 22  (AM2302)
#include <OneWire.h>
#include <DallasTemperature.h>

//===============================  PIN MAPPING ======================================================

//================= RELAYS ========================
int RelBoard1_Ch1_Ch2_AUX = 2;
int RelBoard1_Ch3_Ch4_USBPowerCUT = 3;
int RelBoard2_Ch1_FAN = 4;
int RelBoard2_Ch2_IGN = 5;
int RelBoard2_Ch3_FogHALO = 6;
int RelBoard2_Ch4_FogMain = 7;
//===================== PING ============================
const int PING_L_trigPin = 9;
const int PING_L_echoPin = 8;
const int PING_R_trigPin = 11;
const int PING_R_echoPin = 10;
#define max_distance 250
//======================= RESET ===================================
int RST = 12;
//======================== Temperature Sensors=========================================

//===================== DS18b20(SyStem Temp) ========================
int TS_ds_sys = A1;
OneWire oneWire1(TS_ds_sys);
DallasTemperature sensors1(&oneWire1);
//================== DS18b20(Car Back Temp) ========================
int TS_ds_CarBK = A0;
OneWire oneWire2(TS_ds_CarBK);
DallasTemperature sensors2(&oneWire2);

//================== DHT22 (Dash Temp) ========================
int TS_DHT_dash = A2;
DHT dht(TS_DHT_dash, DHTTYPE);
//========================= LCD =============================================
int LCD_TX = A3;
int LCD_RX = A4;
SoftwareSerial nextion(LCD_TX, LCD_RX);
//========================== Buzzer ==================================================
int buzz = A5;
int buzzen;

//========================================================================================================
int fas;

Nextion myNextion(nextion, 9600); //create a Nextion object named myNextion using the nextion serial port @ 9600bps

int FogHalo_sw;
int FogHead_sw;
int AUX_sw;
int Fan_sw;
int Ping_sw;
int Temp_ctrl_sw;
int Temp_lt_val;
int rest_sw;
int Ignition_sw;


void setup()
{
  digitalWrite(RST, HIGH);
//  Serial.begin(9600);
  myNextion.init();
  dht.begin();
  sensors1.begin();  // for ds18b20
  sensors2.begin();  // for ds18b20

  pinMode(RelBoard1_Ch1_Ch2_AUX, OUTPUT);
  pinMode(RelBoard1_Ch3_Ch4_USBPowerCUT, OUTPUT);
  pinMode(RelBoard2_Ch1_FAN, OUTPUT);
  pinMode(RelBoard2_Ch2_IGN, OUTPUT);
  pinMode(RelBoard2_Ch3_FogHALO, OUTPUT);
  pinMode(RelBoard2_Ch4_FogMain, OUTPUT);
  pinMode(PING_L_trigPin, OUTPUT);
  pinMode(PING_L_echoPin, INPUT);
  pinMode(PING_R_trigPin, OUTPUT);
  pinMode(PING_R_echoPin, INPUT);
  pinMode(RST, OUTPUT);
  pinMode(buzz, OUTPUT);

  digitalWrite(RelBoard2_Ch1_FAN, HIGH);
  digitalWrite(RelBoard1_Ch1_Ch2_AUX, HIGH);
  digitalWrite(RelBoard1_Ch3_Ch4_USBPowerCUT, LOW);  //Enable system
  digitalWrite(RelBoard2_Ch2_IGN, HIGH);
  digitalWrite(RelBoard2_Ch3_FogHALO, HIGH);
  digitalWrite(RelBoard2_Ch4_FogMain, HIGH);

}

void loop()
{
  FogHalo_sw = myNextion.getComponentValue("HOME.cmdfoghalo");
  FogHead_sw = myNextion.getComponentValue("HOME.cmdfogmain");
  AUX_sw = myNextion.getComponentValue("HOME.cmdaux");
  Fan_sw = myNextion.getComponentValue("Temperature.cmdfan");
  Ping_sw = myNextion.getComponentValue("Reverse.enping");
  Temp_ctrl_sw = myNextion.getComponentValue("Settings.Temp_ctrl");
  Temp_lt_val = myNextion.getComponentValue("Settings.tmp_lt");                       //============= Fan Cut off Temperature
  Ignition_sw = myNextion.getComponentValue("Ignition.enstart");
  rest_sw = myNextion.getComponentValue("Settings.reset");
  //=========================================================================================== Reset =============
  if (rest_sw == 1)     // Touch Press event for reset Arduino
  {
    //   Serial.println("Reset ON");
    digitalWrite(RST, LOW);  // Reset Arduino
    while (rest_sw == 1)
    {
      rest_sw = myNextion.getComponentValue("Settings.reset");
    }
  }
  else if (rest_sw == 0)     // Touch Press event for reset Arduino
  {
    //    Serial.println("Reset OFF");
    digitalWrite(RST, HIGH);  // Reset Arduino
    while (rest_sw == 0)
    {
      rest_sw = myNextion.getComponentValue("Settings.reset");
    }
  }

  //=========================================================================================== IGNITION =============
  if (Ignition_sw == 1)     // Touch Press event for reset Arduino
  {
    // Turn Relay ON
    //    Serial.println("Ignition ON");
    while (Ignition_sw == 1)
    {
      Ignition_sw = myNextion.getComponentValue("Ignition.enstart");
      digitalWrite(RelBoard2_Ch2_IGN, LOW);
    }
  }
  else if (Ignition_sw == 0)     // Touch Release event for reset Arduino
  {
    // Turn Relay OFF
    //   Serial.println("Ignition OFF");
    digitalWrite(RelBoard2_Ch2_IGN, HIGH);
    while (Ignition_sw == 0)
    {
      Ignition_sw = myNextion.getComponentValue("Ignition.enstart");
      digitalWrite(RelBoard2_Ch2_IGN, HIGH);
    }
  }
  //=========================================================================================== FOG LAMPS =============

  if (FogHalo_sw == 1)
  {
    // Turn Halo Relay ON
    //   Serial.println("Halo ON");
    digitalWrite(RelBoard2_Ch3_FogHALO, LOW);
  }
  else
  {
    // Turn Halo Relay OFF
    //    Serial.println("Halo OFF");
    digitalWrite(RelBoard2_Ch3_FogHALO, HIGH);
  }

  if (FogHead_sw == 1)
  {
    // Turn Foghead Relay ON
    //   Serial.println("Head ON");
    digitalWrite(RelBoard2_Ch4_FogMain, LOW);
  }
  else
  {
    // Turn Foghead Relay OFF
    //    Serial.println("Head OFF");
    digitalWrite(RelBoard2_Ch4_FogMain, HIGH);
  }
  //============================================================================================ AUX ==========================
  if (AUX_sw == 1)
  {
    // Turn AUX Relay ON
    //    Serial.println("AUX ON");
    digitalWrite(RelBoard1_Ch1_Ch2_AUX, LOW);
  }
  else
  {
    // Turn AUX Relay OFF
    //    Serial.println("AUX OFF");
    digitalWrite(RelBoard1_Ch1_Ch2_AUX, HIGH);
  }
  //============================================================================================= Manual Fan Override =========================
  if (Fan_sw == 1)
  {
    // Turn Fan Relay ON
    //    Serial.println("FAN ON");
    digitalWrite(RelBoard2_Ch1_FAN, LOW);
  }
  else
  {
    if (Temp_ctrl_sw == 1)
    {
      //do nothing
    }
    else
    {
      digitalWrite(RelBoard2_Ch1_FAN, HIGH);
    }

  }
  //============================================================================================== Activate Ping Code ========================
  if (Ping_sw == 1)
  {
    buzzen = myNextion.getComponentValue("Reverse.enbuzz");
    int distanceR =  UsensR();
    int distanceL =  UsensL();
    //int distanceL = 300;
    if (buzzen == 1)
    {
      if ((distanceR <= 200.00 && distanceR > 150.00) || (distanceL <= 200.00 && distanceL > 150.00))
      {
        tone(buzz, 400);
        delay(50);
        noTone(buzz);
      }
      else if ((distanceR <= 150 && distanceR > 100) || (distanceL <= 150 && distanceL > 100))
      {
        tone(buzz, 200);
        delay(100);
        noTone(buzz);
      }
      else if ((distanceR <= 100 && distanceR > 20) || (distanceL <= 100 && distanceL > 20))
      {
        tone(buzz, 300);
        delay(300);
        noTone(buzz);
      }
      else if ((distanceR <= 20 && distanceR > 0) || (distanceL <= 20 && distanceL > 0))
      {
        tone(buzz, 400);
        delay(500);
        noTone(buzz);
      }
    }
  }

  //=============================================================================================== Enable Temperature Controller =======================
  if (Temp_ctrl_sw == 1)
  {
    //  Enter codes for temperature controller here to turn on or off fan automatically


    fas =  TempSys_TX();
    //    Serial.println("Tcon ON");
    if (fas == 1)
    {
      digitalWrite(RelBoard2_Ch1_FAN, LOW); //  FAN ON
      //      Serial.println("fan ON");
    }
    else
    {
      digitalWrite(RelBoard2_Ch1_FAN, HIGH); //  FAN OFF
      //      Serial.println("fan Off");
    }

  }
  else
  {
    fas =  TempSys_TX();
    //    Serial.println("Tcon OFF");
  }
  //======================================================================================================================

}

int UsensR()
{
  long durationR, distanceR;
  digitalWrite(PING_R_trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(PING_R_trigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(PING_R_trigPin, LOW);
  durationR = pulseIn(PING_R_echoPin, HIGH);
  distanceR = (durationR / 2) / 29.1;
  if (distanceR < max_distance)
  {
    //    Serial.print(distanceR);
    //    Serial.println(" cm");

    String b =  (String(distanceR) + " CM");
    String c =  ("Ping Right:" + String(distanceR) + " CM");
    myNextion.setComponentText("Reverse.pngR", b);
    myNextion.setComponentText("PowerSaver.pwpngR", c);

  }
  else
  {
    String b =  ("Range Out");
    myNextion.setComponentText("Reverse.pngR", b);
    myNextion.setComponentText("PowerSaver.pwpngR", "Ping Right: RO");
    //    Serial.println("Range Out");
  }

  return distanceR;
}


int UsensL()
{
  long durationL, distanceL;
  digitalWrite(PING_L_trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(PING_L_trigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(PING_L_trigPin, LOW);
  durationL = pulseIn(PING_L_echoPin, HIGH);
  distanceL = (durationL / 2) / 29.1;

  if (distanceL < max_distance)
  {
    //    Serial.print(distanceL);
    //    Serial.println(" cm");

    String a =  (String(distanceL) + " CM");
    String d =  ("Ping Left:" + String(distanceL) + " CM");
    myNextion.setComponentText("Reverse.pngL", a);
    myNextion.setComponentText("PowerSaver.pwpngL", d);

  }
  else
  {
    String a =  ("Range Out");
    myNextion.setComponentText("Reverse.pngL", a);
    myNextion.setComponentText("PowerSaver.pwpngL", "Ping Right: RO");
    //    Serial.println("Range Out");

  }
  return distanceL;
}


int TempSys_TX()
{
  int fs = 0;
  //===========Temp_Sens_DS18B20  (System Temperature) ===================================
  sensors1.requestTemperatures(); // Send the command to get temperatures
  float Res1 = sensors1.getTempCByIndex(0);
  int Res1a = (int)Res1;
  String a =  (String(Res1) + " \xb0" + "C");  //xb0 is for degree symbol
  //  Serial.println(a);
  myNextion.setComponentText("Temperature.tmp0", a);
  int scaled_value1 = map(Res1a, 0, 100, 0, 100); // always map value from 0 to 100
  myNextion.setComponentValue("Temperature.prg0", scaled_value1);
  myNextion.setComponentText("PowerSaver.pwsys", a);
//  Serial.println(a);


  //===========Temp_Sens_DS18B20  (Car Back Temperature) ===================================
  sensors2.requestTemperatures(); // Send the command to get temperatures
  float Res2 = sensors2.getTempCByIndex(0);
  int Res2a = (int)Res2;
  String b =  (String(Res2) + " \xb0" + "C");  //xb0 is for degree symbol
  //  Serial.println(b);
  myNextion.setComponentText("Temperature.tmp2", b);
  int scaled_value2 = map(Res2a, 0, 100, 0, 100); // always map value from 0 to 100
  myNextion.setComponentValue("Temperature.prg2", scaled_value2);
  myNextion.setComponentText("PowerSaver.pwbk", b);
//  Serial.println(b);


  //===========Temp_Sens_DHT22  (Dash Humidity and Temperature) ===================================
ret:
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  if (isnan(h) || isnan(t))
  {
    //  return;
    goto ret;
  }
  String c =  (String(t) + " \xb0" + "C");  //xb0 is for degree symbol

  String d =  (String(h) + " %");  //xb0 is for degree symbol

  myNextion.setComponentText("Temperature.tmp1a", c);
  int scaled_value3 = map(t, 0, 100, 0, 100); // always map value from 0 to 100
  myNextion.setComponentValue("Temperature.prg1", scaled_value3);
  myNextion.setComponentText("PowerSaver.pwdash", c);
  myNextion.setComponentText("Temperature.tmp1b", d);
//  Serial.println(c);
//  Serial.println(d);

  if (t > Temp_lt_val)
  {
    // digitalWrite(RelBoard2_Ch1_FAN, LOW); //  FAN ON
    fs = 1;
  }
  else
  {
    //   digitalWrite(RelBoard2_Ch1_FAN, HIGH); // FAN OFF
    fs = 0;
  }
  return fs;
}
