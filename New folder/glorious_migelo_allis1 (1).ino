// C++ code
//
int stat;
int togg=0;
 int ppp=13;
void setup()
{
  Serial.begin(9600);
  pinMode(ppp, OUTPUT);
  pinMode(8, INPUT);
  pinMode(11, INPUT);
  
}

void loop()
{
  Serial.print(togg);
//swwit();
  butt();
  delay(100);
}
void butt(){
stat=digitalRead(8);
  
  //Serial.print(digitalRead(11));
  
  if(stat == HIGH && togg == 0){
    togg = 1;
    delay(100);
  } 
  else if( togg == 1 && stat == HIGH ){
    togg = 0;
    delay(100);
  }
 
  
  if(togg == 1){
  Serial.write("HIGH\n");
  digitalWrite(ppp,HIGH);  
  }
  else if(togg == 0){
  digitalWrite(ppp,LOW);
  Serial.write("LOW\n");
  }
  delay(100);

}
void swwit(){
  if(digitalRead(11) == 1){
  togg =1;
  Serial.write("HIGH\n");
 digitalWrite(13,HIGH); 
  }
  else if(digitalRead(11) == 0){
  togg=0;
  Serial.write("LOW\n");
  digitalWrite(13,LOW); 
  }
delay(100);
}
