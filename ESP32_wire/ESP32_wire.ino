#include "Wire.h"

#define iaqaddress 0x5A

uint8_t a;
uint8_t b;
uint8_t c;

void setup()
{
  Serial.begin(115200);
 
  Wire.begin();

  Wire.beginTransmission(iaqaddress);
  Wire.write(0xB5); // Write reset command
  Wire.endTransmission();
  delay(15);  // Default = 15ms
 
}

void loop()
{     

 Wire.requestFrom(iaqaddress, 3);
  delay(1000);
   
  a = Wire.read();
  b = Wire.read();
  c = Wire.read();

   Serial.println("Hello");
   Serial.println(a,HEX);
   Serial.println(b,HEX);
   Serial.println(c,HEX);

}
