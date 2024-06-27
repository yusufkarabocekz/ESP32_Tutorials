#include <Wire.h>
#include <Adafruit_BMP085.h>

Adafruit_BMP085 bmp;

void setup() 
{
  Serial.begin(115200);
  if(bmp.begin() != 1)
  {
    Serial.println("BMP180 sensor failed to start");
    while(1)
    {
      
    }
  }
    
}

void loop() {
  Serial.print("Temperature: ");
  Serial.print(bmp.readTemperature());

  Serial.print(" // Pressure: ");
  Serial.print(bmp.readPressure());

  Serial.print(" // Altitude: ");
  Serial.println(bmp.readAltitude());

  Serial.println(" ");

  delay(500);

}
