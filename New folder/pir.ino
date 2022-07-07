
int pp=7;
void setup()
{
  Serial.begin(9600);
  pinMode(pp, OUTPUT);
}

void loop()
{
  Serial.write("\n");
  int datt=digitalRead(A0);
  Serial.print(datt);
  delay(100);
  if(datt == 1){
  digitalWrite(pp,1);
  delay(3000);
  digitalWrite(pp,0);
  }
  delay(100);
}