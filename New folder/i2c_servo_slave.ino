// C++ code
//slave
#include<Wire.h>
#include<Servo.h>
int rr;
Servo ss;
void setup()
{
  Wire.begin(8);
  Wire.onRequest(reqq); 
  Wire.onReceive(recc);
 // Wire.write("ttest");
  Serial.begin(9600);
  ss.attach(10);
  
}

void loop()
{
  //Wire.onRequest(reqq);
 // Wire.onRequest(reqq);
  //while(Wire.available()){
  //char cas=Wire.read();
  //  Serial.print(cas);
  
 // }
     delay(100);
 }
void reqq(){
  rr=analogRead(A1);
  byte ass = map(rr,0,1023,0,180);
  //rr=map(rr,0,1023,0,180);
  Wire.write(ass);
  //Wire.write("ttest\n");
  Serial.print(ass);
  Serial.write("sent\n");
  delay(100);
  //Serial.write("sent");
}
void recc(int man){
  if(Wire.available()){
  byte asa= Wire.read();
    Serial.print(asa);
    ss.write(asa);
    Serial.print("Receive /n");
    delay(100);
  }

}