
#define LEDPin 13 // Onboard LED
#define LED0 2 
#define LED1 3 
#define LED2 4 
#define LED3 5 
#define LED4 6 
#define LED5 7
#define LED6 8 
#define LED7 9


int maximumRange = 200; // Maximum range needed
int minimumRange = 0; // Minimum range needed

#define triggerpin 14 //connect trigger pin of  ultrasonic sensor to 10th pin of arduino uno
#define echopin 15  //connect echo pin of  ultrasonic sensor to 11th pin of arduino uno
#define tonePin 13    //Tone 

long duration;// establish variables for duration 
long distanceCm, distance;// establish variables for distance



void setup()  
{

  pinMode(triggerpin, OUTPUT);//set trigger pin as output pin
  pinMode(echopin, INPUT);//sets echo pin as input pin
  pinMode(tonePin, OUTPUT); 
  pinMode(LED0, OUTPUT);
  pinMode(LED1, OUTPUT); 
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED7, OUTPUT);
  pinMode(LEDPin, OUTPUT);
  Serial.begin (9600);
}
void loop() // run over and over
{
      
     
  Serial.println("loopstart");
  
  distanceCm=0;
  for(int i=0;i<10;i++)
  {
    digitalWrite(triggerpin,LOW);//sets trigger pin off for 2 microseconds
    delayMicroseconds(2);

    digitalWrite(triggerpin, HIGH);//sets trigger pin on for 10 microseconds
    delayMicroseconds(10);

    digitalWrite(triggerpin,LOW);//sets trigger pin off for 2 microseconds
    delayMicroseconds(2);

    duration = pulseIn(echopin, HIGH); //how much time the echo pin is high
    distance = microsecondsToCentimeters(duration);// microsecondsToCentimeters function is called to convert the time into a distance
    distanceCm=distanceCm+distance;
  }
  distanceCm=distanceCm/10;
 if (distance >= maximumRange || distance <= minimumRange){

    Serial.println("Out of range");
    digitalWrite(LEDPin, HIGH);
    
      digitalWrite(LED0,LOW);
      digitalWrite(LED1,LOW); 
      digitalWrite(LED2,LOW);
      digitalWrite(LED3,LOW);
      digitalWrite(LED4,LOW);
      digitalWrite(LED5,LOW);
      digitalWrite(LED6,LOW);
      digitalWrite(LED7,LOW);
      digitalWrite(tonePin,LOW);
  }
  else {
    Serial.print(distanceCm);
    Serial.println(" cm");



    if(distanceCm<=200.00 && distanceCm>175.00)  

    {
      Serial.println("if1start");
      digitalWrite(LED0,HIGH);
      digitalWrite(LED1,LOW); 
      digitalWrite(LED2,LOW);
      digitalWrite(LED3,LOW);
      digitalWrite(LED4,LOW);
      digitalWrite(LED5,LOW);
      digitalWrite(LED6,LOW);
      digitalWrite(LED7,LOW);
      digitalWrite(tonePin,LOW); 
      delay(100);     
    }

    else if (distanceCm<=175.00 && distanceCm>150.00) 
    { 
      Serial.println("if2start");
      digitalWrite(LED0,HIGH);
      digitalWrite(LED1,HIGH); 
      digitalWrite(LED2,LOW);
      digitalWrite(LED3,LOW);
      digitalWrite(LED4,LOW);
      digitalWrite(LED5,LOW); 
      digitalWrite(LED6,LOW);
      digitalWrite(LED7,LOW);
      digitalWrite(tonePin,LOW);
      delay(100);
    }

    else if (distanceCm<=150.00 && distanceCm>125.00) 
    {
      Serial.println("if3start");
      digitalWrite(LED0,HIGH);
      digitalWrite(LED1,HIGH);
      digitalWrite(LED2,HIGH);
      digitalWrite(LED3,LOW);
      digitalWrite(LED4,LOW);
      digitalWrite(LED5,LOW); 
      digitalWrite(LED6,LOW);
      digitalWrite(LED7,LOW);
      digitalWrite(tonePin,LOW);
      delay(100);
    }

    else if(distanceCm<=125.00 && distanceCm>100.00) 
    {
      Serial.println("if4start");
      digitalWrite(LED0,HIGH);
      digitalWrite(LED1,HIGH); 
      digitalWrite(LED2,HIGH);
      digitalWrite(LED3,HIGH);
      digitalWrite(LED4,LOW);
      digitalWrite(LED5,LOW); 
      digitalWrite(LED6,LOW);
      digitalWrite(LED7,LOW);
      digitalWrite(tonePin,LOW);
      delay(100);
    }

    else if(distanceCm<=100.00 && distanceCm>75.00) 
    {
      Serial.println("if5start");
      digitalWrite(LED0,HIGH);
      digitalWrite(LED1,HIGH); 
      digitalWrite(LED2,HIGH);
      digitalWrite(LED3,HIGH);
      digitalWrite(LED4,HIGH);
      digitalWrite(LED5,LOW); 
      digitalWrite(LED6,LOW);
      digitalWrite(LED7,LOW);
      digitalWrite(tonePin,LOW);
      delay(100);
    }

    else if(distanceCm<=75.00 && distanceCm>50.00) 
    {
      Serial.println("if6start");
      digitalWrite(LED0,HIGH);
      digitalWrite(LED1,HIGH); 
      digitalWrite(LED2,HIGH);
      digitalWrite(LED3,HIGH);
      digitalWrite(LED4,HIGH);
      digitalWrite(LED5,HIGH);
      digitalWrite(LED6,LOW);
      digitalWrite(LED7,LOW);
      digitalWrite(tonePin,LOW);
      delay(100);
    }

    else if(distanceCm<=50.00 && distanceCm>25.00) 
    {
      Serial.println("if7start");
      digitalWrite(LED0,HIGH);
      digitalWrite(LED1,HIGH); 
      digitalWrite(LED2,HIGH);
      digitalWrite(LED3,HIGH);
      digitalWrite(LED4,HIGH);
      digitalWrite(LED5,HIGH); 
      digitalWrite(LED6,HIGH);
      digitalWrite(LED7,LOW);
      digitalWrite(tonePin,LOW);
      delay(100);
    }

    else if(distanceCm<=25.00 && distanceCm>0.00) 
    {
      Serial.println("if8start");
      digitalWrite(LED0,HIGH);
      digitalWrite(LED1,HIGH); 
      digitalWrite(LED2,HIGH);
      digitalWrite(LED3,HIGH);
      digitalWrite(LED4,HIGH);
      digitalWrite(LED5,HIGH); 
      digitalWrite(LED6,HIGH);
      digitalWrite(LED7,HIGH);
      digitalWrite(tonePin,HIGH);
      delay(500);
      
    }

    
  }
  //delay(10);
}









long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2; 
}



