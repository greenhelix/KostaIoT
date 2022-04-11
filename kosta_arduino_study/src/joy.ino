#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); 

int joy_x = 0; 
int joy_y = 0;

void display(long data, long data2){
    int j, k, l, m, j2, k2, l2, m2 = 0;
    j = (data % 10000) / 1000; //-------1000의자리
    k = (data % 1000) / 100; //-------100의자리
    l = (data % 100) / 10; //-------10의자리
    m = (data % 10);    //-------1의자리

    j2 = (data2 % 10000) / 1000; //-------1000의자리
    k2 = (data2 % 1000) / 100; //-------100의자리
    l2 = (data2 % 100) / 10; //-------10의자리
    m2 = (data2 % 10);    //-------1의자리

    lcd.setCursor(0, 0);
    lcd.print("X:: ");
    lcd.print(j);
    lcd.print(k);
    lcd.print(l);
    lcd.print(m);

    lcd.setCursor(0, 1);
    lcd.print("Y:: ");
    lcd.print(j2);
    lcd.print(k2);
    lcd.print(l2);
    lcd.print(m2);


}

void setup()  // 초기화
{
  lcd.init();  // LCD 초기화
  lcd.backlight();  // LCD 백라이트 함수
  Serial.begin(9600);
}

void loop(){
    int x = analogRead(joy_x);
    int y = analogRead(joy_y);
    Serial.print("X::");
    Serial.print(x);
    Serial.print("Y::");
    Serial.print(y);
    display(x, 1024-y);
    delay(100);
}