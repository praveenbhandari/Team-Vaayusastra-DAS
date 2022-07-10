/*
  Using the BNO080 IMU
  By: Nathan Seidle
  SparkFun Electronics
  Date: December 21st, 2017
  SparkFun code, firmware, and software is released under the MIT License.
  Please see LICENSE.md for further details.

  Feel like supporting our work? Buy a board from SparkFun!
  https://www.sparkfun.com/products/14586

  This example shows how to output the parts of the calibrated gyro.

  It takes about 1ms at 400kHz I2C to read a record from the sensor, but we are polling the sensor continually
  between updates from the sensor. Use the interrupt pin on the BNO080 breakout to avoid polling.

  Hardware Connections:
  Attach the Qwiic Shield to your Arduino/Photon/ESP32 or other
  Plug the sensor onto the shield
  Serial.print it out at 115200 baud to serial monitor.
*/

#include <Wire.h>

#include "SparkFun_BNO080_Arduino_Library.h" // Click here to get the library: http://librarymanager/All#SparkFun_BNO080
BNO080 myIMU;

void setup()
{
  Serial.begin(115200);
//  Serial.println();
  //Serial.println("BNO080 Read Example");

  Wire.begin();

  myIMU.begin();

  Wire.setClock(400000); //Increase I2C data rate to 400kHz

  myIMU.enableGyro(100); //Send data update every 50ms
  myIMU.enableMagnetometer(100);

 // Serial.println(F("Gyro enabled"));
  //Serial.println(F("Output in form x, y, z, in radians per second"));
}

void loop()
{
  //Look for reports from the IMU
  if (myIMU.dataAvailable() == true)
  {
    float x = myIMU.getGyroX();
    float y = myIMU.getGyroY();
    float z = myIMU.getGyroZ();
    float magX = myIMU.getMagX();
    float magY = myIMU.getMagY();
    float magZ = myIMU.getMagZ();
    float heading = atan2(magY, magX)*180/PI ;
//    if (magY > 0) { heading = 90 - atan(magX/magY); }
//    else if (magY < 0) { heading = 270 - atan(magX/magY); }
//    else if (magY == 0 && magX < 0) { heading = 180; }
//    else if (magY == 0 && magX > 0) { heading = 0; }
//    Serial.print(x*180/PI, 2);
//    Serial.print(F(","));
//    Serial.print(y*180/PI, 2);
//    Serial.print(F(","));
//    Serial.print(z*180/PI, 2);
//    Serial.print(F(","));
    Serial.print(heading,2);

    Serial.println();
  }
}
