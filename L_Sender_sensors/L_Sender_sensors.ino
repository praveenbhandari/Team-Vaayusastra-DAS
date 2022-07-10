  #include <SPI.h>
#include <LoRa.h>
#include <Wire.h>
#include <BMP388_DEV.h>  

#include "SparkFun_BNO080_Arduino_Library.h" // Click here to get the library: http://librarymanager/All#SparkFun_BNO080
BNO080 myIMU;
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

 
#define ss 5
#define rst 14
#define dio0 2
int counter = 0;
float roll,pitch,yaw;
 
void setup() 
{
  Serial.begin(115200);
  Serial.println("LoRa Sender");
  LoRa.setPins(ss, rst, dio0);
    if (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");
    delay(1000); 
    while (1);
  }
  LoRa.setSpreadingFactor(12);           // ranges from 6-12,default 7 see API docs
   LoRa.setSignalBandwidth(62.5E3);           // for -139dB (page - 112)
   LoRa.setCodingRate4(8);
     LoRa.setSyncWord(0xA5);
    LoRa.setTxPower(20);


    
  bmp388.begin();                                 // Default initialisation, place the BMP388 into SLEEP_MODE 
 bmp388.setTimeStandby(TIME_STANDBY_40MS);     // Set the standby time to 1.3 seconds
  bmp388.startNormalConversion();                 // Start BMP388 continuous conversion in NORMAL_MODE  

  Wire.begin();


 myIMU.begin();

  Wire.setClock(400000); //Increase I2C data rate to 400kHz

  myIMU.enableRotationVector(40); //Send data update every 50ms
   myIMU.enableMagnetometer(40); 

 for (int ii=0;ii<offset_size;ii++){
    offset += analogRead(26)-(1023/2);
  }
  offset /= offset_size;
}
 
void loop() 
{

  if (myIMU.dataAvailable()  && bmp388.getMeasurements(temperature, pressure, altitude))
  {
    roll = (myIMU.getRoll()) * 180.0 / PI; // Convert roll to degrees
    pitch = (myIMU.getPitch()) * 180.0 / PI; // Convert pitch to degrees
    float yaw = (myIMU.getYaw()) * 180.0 / PI; // Convert yaw / heading to degrees
//    float x = myIMU.getMagX();
//    float y = myIMU.getMagY();
//    yaw=atan2(y,x) * 180.0/PI;
    Serial.print(roll, 0);
    Serial.print(F(" "));
    Serial.print(pitch, 0);
    Serial.print(F(" "));
    Serial.print(yaw, 0);
    Serial.print(F(" "));
    Serial.print(altitude*3.28084, 0);
    Serial.print(" ");

    //pitot

    float adc_avg = 0; float veloc = 0.0;
  
// average a few ADC readings for stability
  for (int ii=0;ii<veloc_mean_size;ii++){
    adc_avg+= analogRead(26)-offset;
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
  if(veloc<=0)
  Serial.println("0");
  else
  Serial.println(veloc,0);
    
    
  }
  
  Serial.print("Sending packet: ");
  Serial.print("Roll:\t");
   Serial.print(roll);
  Serial.print("Pitch:\t");
   Serial.print(pitch);
  Serial.print("Yaw:\t");
   Serial.print(yaw);
     Serial.print("Altitude:\t");
   Serial.print(altitude*3.28084);
  Serial.println(counter);
  
  LoRa.beginPacket();
  LoRa.print("X: ,");
  LoRa.print("Y: ,");
  LoRa.print("Z: ,");
  LoRa.println(counter);
//  LoRa.println("");
  LoRa.endPacket();
 
  counter++;
 
//  delay(100);
}
