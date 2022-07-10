// C++ code
//
#include<Servo.h>
int sensorValue;
//int fan = ;
int fanSpeed;
Servo ser;

void setup()
{
  Serial.begin(9600);
ser.attach(9);
  pinMode(A0, INPUT);
  //servo_9.attach(9, 500, 2500);
}

void loop()
{
  sensorValue = analogRead(A0);
//  fanSpeed = map(sensorValue, 0, 1023, 0, 180);
//  analogWrite(fan, fanSpeed);
  delay(10); // Delay a little bit to improve simulation performance
  int pwmm=map(sensorValue,0,1023,1100,1900);
  ser.writeMicroseconds(pwmm);
}
