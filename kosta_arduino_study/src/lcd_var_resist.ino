#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup(){
    Serial.begin(9600);
    lcd.init();
    lcd.backlight();
}

void loop(){
    // analogRead(pin) 이다. 
    int senseorValue = analogRead(A0);
    // 우노:  5V -> A0 ~A5 : 10bit 로 되어있다. 
    // 각 아두이노별로 다르다. 
    Serial.print("[LKELAB] value : ");
    Serial.println(senseorValue);

    lcd.home();
    lcd.noBlink();
    lcd.noCursor();
    lcd.print("Potentiometer");
    resistor(senseorValue);
    
}

void resistor(int v){
    int show[4]; 

    show[0] = (v%10000)/1000;
    show[1] = (v%1000)/100;
    show[2] = (v%100)/10;
    show[3] = (v%10);

    for(int i = 0; i < 4; i++){
        lcd.setCursor(i+5,1);
        lcd.print(show[i]);
    }
}