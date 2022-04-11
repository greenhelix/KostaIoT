// 0에서 9까지 숫자 표현을 위한
// 세그먼트 a, b, c, d, e, f, g, dp의 패턴
byte patterns[] = {
  0xFC, 0x60, 0xDA, 0xF2, 0x66, 0xB6, 0xBE, 0xE4, 0xFE, 0xE6
};
//                 ‘a, b, c, d, e, f, g, dp’ 순서
int segment_pin[] = {2, 3, 4, 5, 6, 7, 8, 9};

void setup() {

  for (int i = 0; i < 8; i++) { 
    pinMode(segment_pin[i], OUTPUT);
  }
}

void loop() {

  for (int no = 0; no < 10; no++) {
    for (int pos = 1; pos <= 4; pos++) {
      show_digit(pos, no); // ‘pos’ 자리에 숫자 ‘no’를 표시
      delay(200);
    }
  }
}

// 해당 자리에 숫자 하나를 표시하는 함수
void show_digit(int pos, int number) { // (위치, 출력할 숫자)


  for (int i = 0; i < 8; i++) {
    boolean on_off = bitRead(patterns[number], 7 - i);
    digitalWrite(segment_pin[i], on_off);
  }
}