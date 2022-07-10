#include <Wire.h>
int ledPin = 10;
static_assert(LOW == 0, "Expecting Low to be 0");

void setup ()
{
  Wire.begin(0x8);
  Wire.onReceive(receiveEvent); //
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW); //turn it off
}

void loop () {
  delay(100);
}

void receiveEvent(int howMany) {
  while (Wire.available()){
    char c = Wire.read();
    digitalWrite(ledPin, c);
  }
}
