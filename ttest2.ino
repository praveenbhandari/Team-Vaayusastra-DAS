// C++ code
//
#include<Wire.h>
#include<Servo.h>
byte rr;
int area;
Servo s;
void setup()
{
  
 Wire.begin();
 // Wire.onReceive(dataaa);
  //Wire.onRequest(datt);
  Serial.begin(9600);
  s.attach(9);
  Serial.write("starting");
}

void loop()
{
//Wire.onReceive(dataaa);
 //dataaa();
 //  Wire.requestFrom(8,6);
 // rr=Wire.read();
 // Serial.print(rr);
  
  
  
  Wire.requestFrom(8,6);
  if(Wire.available()){
   rr=Wire.read();
    Serial.print(rr);
    Serial.print("receive /n");
    s.write(rr);
    delay(100);
  }
  
  //delay(100);
  area=analogRead(A2);
  //Serial.print(area);
  area=map(area,0,1023,0,180);
  Wire.beginTransmission(8);
  Serial.print(area);
 Wire.write(area);
  Serial.write("sent to 8 \n");
  Wire.endTransmission();
  
  delay(100);
  
}



void dataaa(int aa){
 Wire.requestFrom(8,6);
  if(Wire.available()){
   rr=Wire.read();
    Serial.print(rr);
    Serial.print("receive /n");
    s.write(rr);
    delay(100);
  }
  delay(100);}