int led0_Pin_blue = 0; 
int led1_Pin_green = 1;
int led2_Pin_yellow = 2;
int led3_Pin_red = 3;


int btn0_Pin_blue = 8;   // 1번째 스위치
int btn1_Pin_green = 9;
int btn2_Pin_yellow = 10;
int btn3_Pin_red = 11;

void setup()  // 초기화
{
    pinMode(led0_Pin_blue, OUTPUT);  // 1번째 LED 핀(Pin) 출력 포트 설정
    pinMode(led1_Pin_green, OUTPUT);
    pinMode(led2_Pin_yellow, OUTPUT);
    pinMode(led3_Pin_red, OUTPUT);    

    pinMode(btn0_Pin_blue, INPUT);  // 1번째 스위치 핀(Pin) 입력 포트 설정
    pinMode(btn1_Pin_green, INPUT);
    pinMode(btn2_Pin_yellow, INPUT);
    pinMode(btn3_Pin_red, INPUT);    
}

void stayFlash(){
    if(digitalRead(btn0_Pin_blue) == 0){
        digitalWrite(led0_Pin_blue, HIGH);
        delay(1);
        digitalWrite(led0_Pin_blue, LOW);
        delay(9);
        
    }
   
}

void sosFlash(){
    if(digitalRead(btn3_Pin_red) == 0){

    }
}

void lcdFlash(){

}


/* 스위치를 누를 시에 LED가 켜지도록 한다 */
void loop()  // 무한 루프
{       
    stayFlash();
}  