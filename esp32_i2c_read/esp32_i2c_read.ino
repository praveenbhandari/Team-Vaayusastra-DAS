 #include <Arduino.h>
#include <Wire.h>
#include <WireSlave.h>

#define SDA_PIN 21
#define SCL_PIN 22
#define I2C_SLAVE_ADDR 0x08

void receiveEvent(int howMany);
char number[50];

void setup()
{
    Serial.begin(115200);
    Serial.println("Setup");
    bool success = WireSlave.begin(SDA_PIN, SCL_PIN, I2C_SLAVE_ADDR);
    if (!success) {
        Serial.println("I2C slave init failed");
        while(1) delay(100);
    }
    else{
      Serial.println("No Error");
      }

    WireSlave.onReceive(receiveEvent);
    WireSlave.onReceive(receiveEvent1);
}

void loop()
{
    // the slave response time is directly related to how often
    // this update() method is called, so avoid using long delays
    // inside loop()
    WireSlave.update();

    // let I2C and other ESP32 peripherals interrupts work
    delay(1);
}

// function that executes whenever a complete and valid packet
// is received from master
// this function is registered as an event, see setup()
void receiveEvent(int by_coun){
  int i=0;
  Serial.println("Received Eventt");
  while(WireSlave.available()){
    number[i]=WireSlave.read();
    Serial.println(number[i]);
    i++;
    }
    number[i]='\0';
    Serial.println(number);
  }


void receiveEvent1(int howMany)
{
  Serial.println("event 1");
    while (1 < WireSlave.available()) // loop through all but the last byte
    {
        char c = WireSlave.read();  // receive byte as a character
        Serial.print(c);            // print the character
    }

    int x = WireSlave.read();   // receive byte as an integer
    Serial.println(x);          // print the integer
}
