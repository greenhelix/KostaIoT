#include <Stepper.h> // 스테핑모터 라이브러리 헤더파일 선언
const int stepsPerRevolution = 2048;
// 2048:한바퀴(360도), 1024:반바퀴(180도)...
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11); // 디지털 핀 8,10,9,11번 핀으로 지정
// 모터 드라이브에 연결된 핀 IN4, IN2, IN3, IN1
void setup() { // 초기화
    myStepper.setSpeed(14); // 모터의 속도를 14rpm으로 설정
}
/*
   스테핑모터를 0.5초마다 정방향, 역방향으로 제어하도록 한다
*/
void loop() { // 무한루프
    myStepper.step(stepsPerRevolution); // 시계 반대 방향으로 한바퀴 회전
    delay(500); // 500ms 지연
    myStepper.step(-stepsPerRevolution); // 시계 방향으로 한바퀴 회전
    delay(500); // 500ms 지연
}