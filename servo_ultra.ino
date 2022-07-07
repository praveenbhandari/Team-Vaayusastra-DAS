// C++ code
//
#include<Servo.h>
Servo s;
int read;
int pinn=8;
long dat;
#define pp A4
void setup()
  
{
  Serial.begin(9600);
  s.attach(5);
  pinMode(pp,OUTPUT);
  pinMode(pp,INPUT);
  Serial.print("attached");
}

void loop()
{
  serv();



  
}






void serv(){
read=analogRead(A0);
  Serial.print(read);
  int sread=map(read,0,1023,0,180);
  int lread=map(read,0,1023,0,255);
  s.write(sread);
  delay(100);
  analogWrite(A3,lread);
  delay(100);
  
  
  
  
   
  //int lread=map(read,0,1023,0,255);
  
  //delay(10);
  
  
  //s.write(180);
 // Serial.write("rotate");
  
 // for(int i=0;i<180;i++){
 // s.write(i);
    //Serial.write("++");
  //  delay(10);
 // }
  //for(int i=180;i>=1;i--){
  //s.write(i);
  //  Serial.write("--");
   // delay(10);
  //}
}

void ultra(){
  Serial.print("clearing");
  analogWrite(pp,LOW);
  delay(10);
  analogWrite(pp,HIGH);
  delay(10);
  analogWrite(pp,LOW);
delay(10);
  dat=pulseIn(pp,HIGH);
  Serial.print(dat);
  delay(10);}