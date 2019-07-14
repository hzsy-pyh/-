//hc_sr04.ino
// (c) BotBook.com - Karvinen, Karvinen, Valtokari  

int trigPin = 8;
int echoPin = 7;
float v=331.5+0.6*20; // m/s 

void setup()
{
  Serial.begin(9600);
  pinMode (trigPin,OUTPUT);
  pinMode (echoPin,INPUT);
}

float distanceM(){
  // send sound pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(3); // <3>
  digitalWrite(trigPin, HIGH);
  digitalWrite(trigPin, LOW);

float tUs=pulseIn(echoPin,HIGH);
float t=tUs/1000.0/1000.0/2;
float d=t*v;
return d*100;
}
 void loop()
 {
   int d=distanceM();
   Serial.println(d,DEC);
   delay(500); 
 }
