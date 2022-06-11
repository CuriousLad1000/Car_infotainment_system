int char1,char2;
int charflag=0;

void setup() {
  Serial.begin(9600);
  pinMode(13,OUTPUT);
}

void loop() {
 if (Serial.available()>1) 
{
 if (charflag)  
  {
  char2=Serial.read();
  if (char2==0) digitalWrite(13,HIGH);
  else if (char2==0x01) digitalWrite(13,LOW);
  charflag=0;
  }
  else
  {
   char1=Serial.read();
   if(char1==0x65) charflag=1;
  }
}
}
