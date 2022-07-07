#include <BMP388_DEV.h>
#include <Wire.h>
#include "MPU9250.h"


MPU9250 mpu; // You can also use MPU9255 as is
float  temperature, pressure, altitude;            // Create the temperature, pressure and altitude variables
BMP388_DEV bmp388; 


////pitot 
float V_0 = 5.0; // supply voltage to the pressure sensor
float rho = 1.204; // density of air 

// parameters for averaging and offset
int offset = 0;
int offset_size = 10;
int veloc_mean_size = 20;
int zero_span = 2;

int pitotPin=13;
void setup()
{
  Serial.begin(115200);
//  Serial.println();
 // Serial.println("BNO080 Read Example");


  bmp388.begin();                                 // Default initialisation, place the BMP388 into SLEEP_MODE 
 bmp388.setTimeStandby(TIME_STANDBY_40MS);     // Set the standby time to 1.3 seconds
  bmp388.startNormalConversion();                 // Start BMP388 continuous conversion in NORMAL_MODE

  Wire.begin();
  mpu.setup(0x68);


  //pitot 

  for (int ii=0;ii<offset_size;ii++){
    offset += analogRead(pitotPin)-(1023/2);
  }
  offset /= offset_size;
}

void loop()
{




  if (bmp388.getMeasurements(temperature, pressure, altitude)&& mpu.update())
  {


   Serial.print(mpu.getPitch()); Serial.print(" ");
   Serial.print(mpu.getRoll());Serial.print(" ");
   Serial.print(mpu.getYaw()); Serial.print(" ");
    Serial.print(altitude*3.28084, 0);
    Serial.print(" ");

    //pitot

    float adc_avg = 0; float veloc = 0.0;

// average a few ADC readings for stability
  for (int ii=0;ii<veloc_mean_size;ii++){
    adc_avg+= analogRead(pitotPin)-offset;
  }
  adc_avg/=veloc_mean_size;

  // make sure if the ADC reads below 512, then we equate it to a negative velocity
  if (adc_avg>512-zero_span and adc_avg<512+zero_span){
  } else{
    if (adc_avg<512){
      veloc = -sqrt((-10000.0*((adc_avg/1023.0)-0.5))/rho);
    } else{
      veloc = sqrt((10000.0*((adc_avg/1023.0)-0.5))/rho);
    }
  }

  Serial.print(veloc,0);
  Serial.println(" 0");
    
  }


}
