// C++ code
//
int pp=5;
void setup()
{
  Serial.begin(9600);
  pinMode(A1, INPUT);
    pinMode(pp, OUTPUT);
}

void loop()
{
  double some=analogRead(A0);
  double datt= (((some * 5 )/1024)-0.5)*100;
  delay(100);
 Serial.write("\n");
 Serial.print(datt);
  
  if(datt <= 25){
  digitalWrite(pp,LOW);
  }
  else if( datt > 25 && datt < 40){
  int sss= map(datt,25,40,32,255);
  analogWrite(pp,sss);
  delay(100);
  }
  else if(datt > 40){
  digitalWrite(pp,HIGH);
  }
  
  
  
}