#include<Servo.h>
Servo ss;
void setup() {
 
ss.attach(13);
  ss.write(0);
  Serial.begin(9600);
Serial.print("start");
}

void loop() {
 // ss.write(0);
int tt=analogRead(A2);
Serial.print(tt);
Serial.print("->  Analog,    ");
//delay(100);
     int ass=map(tt,6,679,0,180);
  ss.write(ass);
   Serial.print(ass);
  Serial.print("->  Servo\n");
  delay(200);
  
if(tt < 400){
   digitalWrite(10,HIGH);
  // Serial.print("on");
  delay(100);
}
else if(tt >=400){
   digitalWrite(10,LOW);
 //  Serial.print("off");
  delay(100);

}
}