int Switch1_Pin = 0; // 스위치1
int Switch2_Pin = 1; // 스위치2
int Switch3_Pin = 2; // 스위치3

int DIR1 = 3; // L293D DIR1
int DIR2 = 4; // L293D DIR2
int EN1 = 5; // L293D EN1

void Motor_ccw() { // 반시계 방향 회전
  digitalWrite(DIR1, HIGH);       // DIR1 On
  digitalWrite(DIR2, LOW);        // DIR2 Off
  digitalWrite(EN1, HIGH);        // Motor Enable
}
void Motor_cw() // 시계 방향 회전
{
  digitalWrite(DIR1, LOW);       // DIR1 Off
  digitalWrite(DIR2, HIGH);      // DIR2 On
  digitalWrite(EN1, HIGH);       // Motor Enable
}
void Motor_stop() // 회전 정지
{
  digitalWrite(DIR1, HIGH);       // DIR1 On
  digitalWrite(DIR2, HIGH);      // DIR2 On
  digitalWrite(EN1, LOW);       // Motor Disable
}
void setup() // 초기화
{
  Serial.begin(9600);
  pinMode(Switch1_Pin, INPUT);  // 스위치 1번핀 입력포트 설정
  pinMode(Switch2_Pin, INPUT);  // 스위치 2번핀 입력포트 설정
  pinMode(Switch3_Pin, INPUT);  // 스위치 3번핀 입력포트 설정

  pinMode(DIR1, OUTPUT);    // DIR1 핀 출력포트 설정
  pinMode(DIR2, OUTPUT);    // DIR2 핀 출력포트 설정
  pinMode(EN1, OUTPUT);    // EN1 핀 출력포트 설정
}
/*
   스위치를 이용하여 DC모터에 정회전, 역회전, 정지하도록 한다.
*/
void loop() // 무한루프
{
  
  if (digitalRead(Switch1_Pin) == LOW) // 1번째 스위치를 누르면
  {    
    Motor_ccw();
  }
  else if (digitalRead(Switch2_Pin) == LOW) // 2번째 스위치를 누르면
  {    
    Motor_cw();
  }
  else if (digitalRead(Switch3_Pin) == LOW) // 3번째 스위치를 누르면
  {    
    Motor_stop();
  }
  
}