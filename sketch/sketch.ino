const int TrigPin = 2; //超声波trig引脚
const int EchoPin = 3; //超声波echo引脚
float cm=0.0; //障碍距离
float warringLine=20.0;//警报距离
const int tonePin = 6 ;//蜂鸣器tone引脚

void setup(){ 
  Serial.begin(9600);
  pinMode(TrigPin, OUTPUT); 
  pinMode(EchoPin, INPUT);
  pinMode(tonePin, OUTPUT); 
  
}
void loop(){ 
  while(true){
  digitalWrite(TrigPin, LOW); //低高低电平发一个短时间脉冲去TrigPin 
  delayMicroseconds(2); 
  digitalWrite(TrigPin, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(TrigPin, LOW);
cm = pulseIn(EchoPin, HIGH) / 58; //将回波时间换算成cm
cm = (int(cm * 100)) / 100; //保留两位小数 
 Serial.println(cm);
if(cm < warringLine){
 
   digitalWrite(tonePin, LOW);//串口输出蜂鸣
  delay(10);
  }
  else{
    digitalWrite(tonePin, HIGH); 
  delay(10);
    }

delay(10); 
}
}
