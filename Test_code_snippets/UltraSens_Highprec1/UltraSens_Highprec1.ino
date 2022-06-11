
#define PING_L_trigPin 11
#define PING_L_echoPin 10
#define max_distance 250

void setup() {

  Serial.begin (9600);
  pinMode(PING_L_trigPin, OUTPUT);
  pinMode(PING_L_echoPin, INPUT);

}

void loop()
{
  UsensL();
}

void UsensL()
{
  long duration, distance;
  digitalWrite(PING_L_trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(PING_L_trigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(PING_L_trigPin, LOW);
  duration = pulseIn(PING_L_echoPin, HIGH);
  distance = (duration / 2) / 29.1;
  //Serial.println(distance);
  if (distance < max_distance)
  {
    Serial.print(distance);
    Serial.println(" cm");
    delay(500);
  }
  else
  {
    Serial.println("Range Out");
  }
  delay(1000);
}

