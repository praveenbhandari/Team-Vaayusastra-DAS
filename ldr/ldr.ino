void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial.print("start");
}

void loop() {
  // put your main code here, to run repeatedly:
 
int tt=analogRead(A2);
Serial.print(tt);
Serial.print("\n");
delay(100);
if(tt < 100){
   digitalWrite(10,HIGH);
   Serial.print("on");
}
else if(tt >=100){
   digitalWrite(4,LOW);
   Serial.print("off");
  }

}
