int RelBoard1_Ch1_Ch2_AUX = 2;
int RelBoard1_Ch3_Ch4_USBPowerCUT = 3;
int RelBoard2_Ch1_FAN = 4;
int RelBoard2_Ch2_IGN = 5;
int RelBoard2_Ch3_FogHALO = 6;
int RelBoard2_Ch4_FogMain = 7;

void setup()
{
  // put your setup code here, to run once:
  pinMode(RelBoard1_Ch1_Ch2_AUX, OUTPUT);
  pinMode(RelBoard1_Ch3_Ch4_USBPowerCUT, OUTPUT);
  pinMode(RelBoard2_Ch1_FAN, OUTPUT);
  pinMode(RelBoard2_Ch2_IGN, OUTPUT);
  pinMode(RelBoard2_Ch3_FogHALO, OUTPUT);
  pinMode(RelBoard2_Ch4_FogMain, OUTPUT);
}


void loop()
{
//  digitalWrite(RelBoard1_Ch1_Ch2_AUX, LOW);   //ACTIVATES AT LOW PULSE
  digitalWrite(RelBoard1_Ch3_Ch4_USBPowerCUT, LOW);   //ACTIVATES AT LOW PULSE
//  digitalWrite(RelBoard2_Ch1_FAN, LOW);   //ACTIVATES AT LOW PULSE
//  digitalWrite(RelBoard2_Ch2_IGN, LOW);   //ACTIVATES AT LOW PULSE
  digitalWrite(RelBoard2_Ch3_FogHALO, LOW);   //ACTIVATES AT LOW PULSE
  digitalWrite(RelBoard2_Ch4_FogMain, LOW);   //ACTIVATES AT LOW PULSE
//  delay(3000);
  digitalWrite(RelBoard1_Ch1_Ch2_AUX, HIGH); //  DE-ACTIVATES AT HIGH PULSE
//  digitalWrite(RelBoard1_Ch3_Ch4_USBPowerCUT, HIGH); //  DE-ACTIVATES AT HIGH PULSE
  digitalWrite(RelBoard2_Ch2_IGN, HIGH); //  DE-ACTIVATES AT HIGH PULSE
//  digitalWrite(RelBoard2_Ch3_FogHALO, HIGH); //  DE-ACTIVATES AT HIGH PULSE
  digitalWrite(RelBoard2_Ch1_FAN, HIGH); //  DE-ACTIVATES AT HIGH PULSE
//  digitalWrite(RelBoard2_Ch4_FogMain, HIGH); //  DE-ACTIVATES AT HIGH PULSE
//  delay(3000);
}
