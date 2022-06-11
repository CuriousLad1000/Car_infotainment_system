#include <SoftwareSerial.h>
#include <Nextion.h>
#include <NewPing.h>
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
//======================= RESET ===================================
int RST = 12;
//======================== Temperature Sensors=========================================

//===================== DS18b20(SyStem Temp) ========================
int TS_ds_sys = A0;
OneWire oneWire1(TS_ds_sys);
DallasTemperature sensors1(&oneWire1);
//================== DS18b20(Car Back Temp) ========================
int TS_ds_CarBK = A1;
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
//========================================================================================================


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
  Serial.begin(9600);
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
  digitalWrite(RelBoard1_Ch3_Ch4_USBPowerCUT, HIGH);
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
  // reset_sw = myNextion.getComponentValue("Settings.tmp_lt");
  // Ignition_sw = myNextion.getComponentValue("Settings.tmp_lt");

  //=========================================================================================== IGNITION =============
  String RST_message = myNextion.listen(); //check for message
  if (RST_message == "65 4 5 0 ffff ffff ffff")     // Touch Release event for reset Arduino
  {
    // Reset Arduino
    Serial.println("Reset ON");

  }


  //=========================================================================================== IGNITION =============
  String ign_message = myNextion.listen(); //check for message
  if (ign_message == "65 8 3 1 ffff ffff ffff")     // Touch Press event for reset Arduino
  {
    // Turn Relay ON
    Serial.println("Ignition ON");

  }
  if (ign_message == "65 8 3 0 ffff ffff ffff")     // Touch Release event for reset Arduino
  {
    // Turn Relay OFF
    Serial.println("Ignition OFF");

  }

  //=========================================================================================== FOG LAMPS =============

  if (FogHalo_sw == 1)
  {
    // Turn Halo Relay ON
  }
  else
  {
    // Turn Halo Relay OFF
  }

  if (FogHead_sw == 1)
  {
    // Turn Foghead Relay ON
  }
  else
  {
    // Turn Foghead Relay OFF
  }
  //============================================================================================ AUX ==========================
  if (AUX_sw == 1)
  {
    // Turn AUX Relay ON
  }
  else
  {
    // Turn AUX Relay OFF
  }
  //============================================================================================= Manual Fan Override =========================
  if (Fan_sw == 1)
  {
    // Turn Fan Relay ON
  }
  else
  {
    // Turn Fan Relay OFF
  }
  //============================================================================================== Activate Ping Code ========================
  if (Ping_sw == 1)
  {
    // TX Ping data
  }
  else
  {
    // NO TX Ping data
  }
  //=============================================================================================== Enable Temperature Controller =======================
  if (Temp_ctrl_sw == 1)
  {
    //  Enter codes for temperature controller here to turn on or off fan automatically
  }
  else
  {
    // disable Temp Controller (Set temp lt to 200
  }
  //======================================================================================================================


}

void TempSys_TX()
{
  int x = 129;
  int y1 = 48;
  int y2 = 105;
  int y3 = 165;
  int width = 211;
  int height = 30;

  //===========Temp_Sens_DS18B20  (System Temperature) ===================================
  sensors1.requestTemperatures(); // Send the command to get temperatures
  float Res1 = sensors1.getTempCByIndex(0);
  int Res1a = (int)Res1;
  String a =  (String(Res1) + " \xb0" + "C");  //xb0 is for degree symbol
  //  Serial.println(a);
  myNextion.setComponentText("Temperature.tmp0", a);
  int scaled_value1 = map(Res1a, 0, 100, 0, 100); // always map value from 0 to 100
  myNextion.updateProgressBar(x, y1, width, height, scaled_value1, 7, 8); // update the progress bar
  myNextion.setComponentText("PowerSaver.pwsys", a);


  //===========Temp_Sens_DS18B20  (Car Back Temperature) ===================================
  sensors2.requestTemperatures(); // Send the command to get temperatures
  float Res2 = sensors2.getTempCByIndex(0);
  int Res2a = (int)Res2;
  String b =  (String(Res2) + " \xb0" + "C");  //xb0 is for degree symbol
  //  Serial.println(b);
  myNextion.setComponentText("Temperature.tmp2", b);
  int scaled_value2 = map(Res2a, 0, 100, 0, 100); // always map value from 0 to 100
  myNextion.updateProgressBar(x, y2, width, height, scaled_value2, 7, 8); // update the progress bar
  myNextion.setComponentText("PowerSaver.pwdash", b);


  //===========Temp_Sens_DHT22  (Dash Humidity and Temperature) ===================================

  float t = dht.readTemperature();
  float h = dht.readHumidity();
  if (isnan(h) || isnan(t))
  {
    return;
  }
  String c =  (String(t) + " \xb0" + "C");  //xb0 is for degree symbol

  String d =  (String(h) + " %");  //xb0 is for degree symbol

  myNextion.setComponentText("Temperature.tmp1a", c);
  int scaled_value3 = map(t, 0, 100, 0, 100); // always map value from 0 to 100
  myNextion.updateProgressBar(x, y3, width, height, scaled_value3, 7, 8); // update the progress bar
  myNextion.setComponentText("PowerSaver.pwbk", c);
  myNextion.setComponentText("Temperature.tmp1b", d);

  //Serial.println(c);
  //Serial.println(d);

  if (t > Temp_lt_val)
  {
    digitalWrite(RelBoard2_Ch1_FAN, LOW); //  FAN ON
  }
  else
  {
    digitalWrite(RelBoard2_Ch1_FAN, HIGH); // FAN OFF
  }
}
