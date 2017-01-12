#include <Servo.h>
int m12 =12; //right motor
int m11 =9;
int m21 =6;
int m22=4;
int pwm1=5;
int pwm2=11;
int supply = 10;
 Servo myservo;
int incomingbyte=0;
int servoposition=135;
void setup()
{
  Serial.begin(9600);
myservo.attach(3);
myservo.write(servoposition);
pinMode(m11,OUTPUT);
pinMode(m12,OUTPUT);
pinMode(m21,OUTPUT);
pinMode(m22,OUTPUT);
pinMode(pwm1,OUTPUT);
pinMode(pwm2,OUTPUT);
}
void loop()
{
  if(Serial.available()>0)
  {
  incomingbyte=Serial.read();
  
  switch(incomingbyte)
 {
   case '1':
   servoposition+=1;
   if(servoposition>180)
   {
     servoposition=170;
   }
  break;
   case '2':
   servoposition-=1;
   if(servoposition<0)
   {
     servoposition=0;
   }
  break;
  case '3':
   front();
  break;
  case '4':
  back();
  break;
  case '5':
  stopall();
  break;
 }
 myservo.write(servoposition);
}
}

void back()
{
  digitalWrite(supply,HIGH);
 digitalWrite(m11,LOW);
 digitalWrite(m12,HIGH);
 digitalWrite(m21,LOW);
 digitalWrite(m22, HIGH);
 analogWrite(pwm1,50);
 analogWrite(pwm2,50);   
  
  
}
void front()
{
  digitalWrite(supply,HIGH);
 digitalWrite(m11,HIGH);
 digitalWrite(m12,LOW);
 digitalWrite(m21,HIGH);
 digitalWrite(m22, LOW);
 analogWrite(pwm1,50);
 analogWrite(pwm2,50);   
  
  
}

void stopall()
{
  
 digitalWrite(m11,LOW);
 digitalWrite(m12,LOW);
 digitalWrite(m21,LOW);
 digitalWrite(m22, LOW);
 analogWrite(pwm1,0);
 analogWrite(pwm2,0);   
  
  
}
