char character;  // 전역변수로 선언.

void setup(){
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(9600);  // 시리얼 통신 시작 boud rate 9600 을 가장 많이 쓴다. 
    Serial.println("Welcome Serial Connect Success");
    
}

void call_A(){
     
        digitalWrite(LED_BUILTIN, HIGH);
        delay(100);
        digitalWrite(LED_BUILTIN, LOW);
        delay(100);
        digitalWrite(LED_BUILTIN, HIGH);
        delay(300);
        digitalWrite(LED_BUILTIN, LOW);
        delay(300);            
        
}

void call_SOS(){
    delay(200);
    for(int i = 0 ; i<3; i++){
        digitalWrite(LED_BUILTIN, HIGH);
        delay(100);
        digitalWrite(LED_BUILTIN, LOW);
        delay(100);
    }
    delay(200);
    for(int i = 0 ; i<3; i++){
        digitalWrite(LED_BUILTIN, HIGH);
        delay(300);
        digitalWrite(LED_BUILTIN, LOW);
        delay(300);
    }
    delay(200);
    for(int i = 0 ; i<3; i++){
        digitalWrite(LED_BUILTIN, HIGH);
        delay(100);
        digitalWrite(LED_BUILTIN, LOW);
        delay(100);
    }   
                    
        
}

void loop(){
    if(Serial.available()){ // 받는 입장에서 값이 있다면
        character = Serial.read(); // 읽어들인다.
        Serial.print(character); // 출력한다.

        if(character == 'a'){
            call_A();
        }
        else if(character == 's'){
            int a = 3;
            while(a){                
                call_SOS();
                a--;
            }
            
        }
       
    }
}

// data bits :8  parity:  n  stop bits 1 을 많이 쓴다.