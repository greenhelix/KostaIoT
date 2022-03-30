
#define echo 6
#define trig 7
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); 

void setup(){
    Serial.begin(9600);
    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);
    lcd.init();  // LCD 초기화
    lcd.backlight();  // LCD 백라이트 함수
}


void loop(){
    Serial.print("Check the value ! ");
    Serial.print( read_ultrasonic());
    Serial.print("cm");
}

int read_ultrasonic(void){
    float return_time, howlong;

    digitalWrite(trig, HIGH);
    delay(5);
    digitalWrite(trig, LOW);
    return_time = pulseIn(echo, HIGH);
    howlong = ((float)(340*return_time)/10000)/2;
    lcd.setCursor(0,1);
    lcd.print(howlong);
    return howlong;
}
