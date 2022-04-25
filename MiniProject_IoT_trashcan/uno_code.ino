#include <Servo.h>

Servo SV; // 모터 객체 생성

int pos = 0; // 모터 각도값 초기화
int TRIG = 2; // 초음파센서 트리거핀
int ECHO = 3; // 초음파센서 에코핀

void setup()
{
    Serial.begin(9600); // 테스트
    SV.attach(4); // 모터 핀
    pinMode(TRIG,OUTPUT);
    pinMode(ECHO,INPUT);
}

void loop()
{
    digitalWrite(TRIG,HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG,LOW);

    long duration = pulseIn(ECHO,HIGH); 
    long distance = (340*duration)/2/10000; // 초음파센서와의 거리 cm로 변환

    if(distance <= 10) // 초음파 센서랑 거리 10cm 이하일경우
        {
        SV.write(5); // 뚜껑 열기
        delay(3000);
        }
    else // 초음파 센서랑 거리 멀어질 경우
        {
        SV.write(85); // 뚜껑 닫기
        }
        delay(1000);
}