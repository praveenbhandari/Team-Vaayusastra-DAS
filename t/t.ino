int pinn=4;
int bb=0;
////int count=0;
void setup() {
//  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(9600);
  Serial.write("someth9in\n");
  pinMode(pinn, OUTPUT);
}
//
//// the loop function runs over and over again forever
void loop() {
  analogWrite(pinn,200);
////  count=11;
////digitalWrite(pinn,0);
while(Serial.available()){
 bb=Serial.parseInt();
Serial.print(bb);

analogWrite(pinn,bb);
//if(bb == '1' || bb == 'h'){
//Serial.write("On");  
//digitalWrite(pinn,HIGH);
//delay(100);
//}
//if(bb == '0' || bb == 'l'){
//Serial.write("OFF"); 
//digitalWrite(pinn,LOW);  
delay(100);
//}

//analogWrite(pinn,200);

}
////Serial.write("nulll\n");
}
