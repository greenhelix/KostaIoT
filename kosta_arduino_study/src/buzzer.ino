int Buzzer = 8;   // Data Pin 8을 Buzzer 제어 핀으로 선언

void setup() {
  pinMode(Buzzer, OUTPUT);   // Buzzer 제어 핀(GPIO Pin 8)을 출력으로 설정
}

void loop() {
    tone(Buzzer, 659); //미
    delay(500);
    tone(Buzzer, 698); //파
    delay(250);
    tone(Buzzer, 698); //파
    delay(500);

    tone(Buzzer, 523); //도 
    delay(750);

    tone(Buzzer, 523); //도
    delay(750);

    tone(Buzzer, 440); //4옥 라
    delay(250);

    tone(Buzzer, 659); //미
    delay(250);

    tone(Buzzer, 698); //파
    delay(125);

    tone(Buzzer, 698); //파
    delay(250);

    tone(Buzzer, 523); //도 
    delay(250);

    tone(Buzzer, 174); //3옥 파
    delay(125);

    tone(Buzzer, 659); //미
    delay(250);

    tone(Buzzer, 698); //파
    delay(125);

    tone(Buzzer, 698); //파
    delay(250);

    tone(Buzzer, 523); //도
    delay(500);

}