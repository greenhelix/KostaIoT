/* I2C 통신을 위해 Wire.h 헤더 파일을 include 한다. */ 
#include<Wire.h> 
const int MPU_addr = 0x68; // I2C address of the MPU-6050 
int16_t AcX, AcY, AcZ, Tmp, GyX, GyY, GyZ; 
void setup() // 초기화 
{ 
    Wire.begin(); 
    Wire.beginTransmission(MPU_addr); 
    Wire.write(0x6B);          // PWR_MGMT_1 register 
    Wire.write(0);            // set to zero (wakes up the MPU-6050) 
    Wire.endTransmission(true); 
    Serial.begin(9600); // 시리얼 통신 사용, 통신 보레이트 9600bps 설정 
} 
/* 자이로 센서 모듈은 3 축(X, Y, Z) 자이로(회전)와 3 축 가속도를 측정하며,  이를 이용하여 각도를 측정할 수 있다. 
 측정 된 데이터 값은 시리얼 통신을 통하여 PC 에서 확인 할 수 있다. */ 
void loop() // 무한 루프 
{ 
    Wire.beginTransmission(MPU_addr); 
    Wire.write(0x3B);           // starting with register 0x3B (ACCEL_XOUT_H) 
    Wire.endTransmission(false); 
    Wire.requestFrom(MPU_addr, 14, true); // request a total of 14 registers 
    AcX = Wire.read() << 8 | Wire.read(); 
    // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L) 
    AcY = Wire.read() << 8 | Wire.read(); // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L) 
    AcZ = Wire.read() << 8 | Wire.read(); // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L) 
    Tmp = Wire.read() << 8 | Wire.read(); // 0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L) 
    GyX = Wire.read() << 8 | Wire.read(); // 0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L) 
    GyY = Wire.read() << 8 | Wire.read(); // 0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)  
    GyZ = Wire.read() << 8 | Wire.read(); // 0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L) 
    Serial.println(F("MPU-6050")); 
    Serial.print(F("  accel x,y,z: ")); 
    Serial.print(" AcX = "); Serial.print(AcX);  // 가속도 X 축 값 
    Serial.print("  | AcY = "); Serial.print(AcY); // 가속도 Y 축 값 
    Serial.print("  | AcZ = "); Serial.print(AcZ); // 가속도 Z 축 값 
    Serial.print(F("temperature: ")); 
    Serial.print("  | Tmp = "); Serial.print(Tmp / 340.00 + 36.53); 
    // equation for temperature in degrees C from datasheet 
    Serial.print(F(" gyro x,y,z : ")); 
    Serial.print("  | GyX = "); Serial.print(GyX);  // 자이로 X 축 값 
    Serial.print("  | GyY = "); Serial.print(GyY);  // 자이로 Y 축 값  
    Serial.print("  | GyZ = "); Serial.println(GyZ); // 자이로 Z 축 값  
    delay(333); 
}