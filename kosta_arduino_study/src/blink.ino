void setup(){
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop(){
    
    for(int i = 0; i< 3; i++){
        digitalWrite(LED_BUILTIN, HIGH);
        delay(100);
        digitalWrite(LED_BUILTIN, LOW);
        delay(100);
    }

    for(int i = 0; i< 3; i++){
        digitalWrite(LED_BUILTIN, HIGH);
        delay(500);
        digitalWrite(LED_BUILTIN, LOW);
        delay(500);
    }

    delay(2000);
}
