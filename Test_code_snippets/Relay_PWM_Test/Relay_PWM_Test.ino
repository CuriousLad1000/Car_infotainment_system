int Rel1 = 14;
int Rel2 = 15;
int Rel3 = 16;
int Rel4 = 17;
void setup()
{
  // put your setup code here, to run once:
  pinMode(Rel1, OUTPUT);
  pinMode(Rel2, OUTPUT);
  pinMode(Rel3, OUTPUT);
  pinMode(Rel4, OUTPUT);
}

void loop()
{
  digitalWrite(Rel1, LOW);   //ACTIVATES AT LOW PULSE
  digitalWrite(Rel2, LOW);   //ACTIVATES AT LOW PULSE
  digitalWrite(Rel3, LOW);   //ACTIVATES AT LOW PULSE
  digitalWrite(Rel4, LOW);   //ACTIVATES AT LOW PULSE
  delay(300);
  digitalWrite(Rel1, HIGH); //  DE-ACTIVATES AT HIGH PULSE
  digitalWrite(Rel2, HIGH); //  DE-ACTIVATES AT HIGH PULSE
  digitalWrite(Rel3, HIGH); //  DE-ACTIVATES AT HIGH PULSE
  digitalWrite(Rel4, HIGH); //  DE-ACTIVATES AT HIGH PULSE
  delay(300);
}