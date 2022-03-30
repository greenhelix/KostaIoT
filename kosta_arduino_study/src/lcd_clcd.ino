#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
void Clcd_display(long data) // 텍스트 LCD 디스플레이 함수
{
  int j, k, l, m = 0;
  j = (data % 10000) / 1000; //-------1000의자리
  k = (data % 1000) / 100; //-------100의자리
  l = (data % 100) / 10; //-------10의자리
  m = (data % 10);    //-------1의자리

  lcd.setCursor(0, 0); // LCD 문자출력 시작(열,행)라인 설정
  lcd.print("CDS10K LKE LAB"); // 메시지 출력할 내용
  lcd.setCursor(0, 1); // LCD 문자출력 시작(열,행)라인 설정
  lcd.print("CDS10K:"); // 메시지 출력할 내용
  lcd.print(j);   //-------1000의자리
  lcd.print(k);   //-------100의자리
  lcd.print(l);   //-------10의자리
  lcd.print(m);   //-------1의자리
}

void setup(){
    Serial.begin(9600);
    lcd.init();
    lcd.backlight();
    lcd.begin(16, 2);
}

void loop(){
    lcd.setCursor(0,0);
    int value = analogRead(A0);
    Serial.println(value);
    delay(500);
    char buff[10];
    sprintf(buff, "%4d", value);
    lcd.print(buff);
}