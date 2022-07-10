#include<SoftwareSerial.h>

int led = 2;
int received = 0;
int i;

//For communicating with zigbee
SoftwareSerial zigbee(13,12);

void setup()
{
    Serial.begin(9600);
    zigbee.begin(9600);
    pinMode(led, OUTPUT);

}

void loop()
{
    //check if the data is received 
    if (zigbee.available() > 0)
    {
        received = zigbee.read();
        //if the data is 0, turn off the LED
        if (received == '0')
        {
            Serial.println("Turning off LED");
            digitalWrite(led, LOW);
        }
        //if the data is 1, turn on the LED
        else if (received == '1')
        {
            Serial.println("Turning on LED");
            digitalWrite(led, HIGH);
        }
    }
}
