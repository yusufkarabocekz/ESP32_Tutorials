#include "Wire.h"
#include <MPU6050_light.h>

MPU6050 mpu(Wire);

byte status;
long timer = 0;

void setup() {
  Serial.begin(115200);
  Wire.begin();

  status = mpu.begin();
  Serial.print(F("MPU6050 Status: "));
  Serial.println(status);

  while (status != 0) 
  {
    // Stop everything if could not connect to MPU6050 sensor
  }

  Serial.println(F("Calculating offsets, do not move MPU6050"));
  delay(1000);
  mpu.calcOffsets(true, true); // gyro and accel
  Serial.println(F("Done!"));
}

void loop() {
  mpu.update();

  if (millis() - timer > 1000) {
    Serial.print(F("Temperature: "));
    Serial.print(mpu.getTemp());
    Serial.print(" ");

    Serial.print(F("Accel X Y Z: "));
    Serial.print(mpu.getAccX()); Serial.print(" ");
    Serial.print(mpu.getAccY()); Serial.print(" ");
    Serial.print(mpu.getAccZ()); Serial.print(" ");

    Serial.print(" ");

    Serial.print(F("Gyro X Y Z: "));
    Serial.print(mpu.getGyroX()); Serial.print(" ");
    Serial.print(mpu.getGyroY()); Serial.print(" ");
    Serial.print(mpu.getGyroZ()); Serial.print(" ");

    Serial.print(" ");

    Serial.print(F("Angle X Y Z: "));
    Serial.print(mpu.getAngleX()); Serial.print(" ");
    Serial.print(mpu.getAngleY()); Serial.print(" ");
    Serial.print(mpu.getAngleZ()); Serial.println();

    timer = millis();
  }
}
