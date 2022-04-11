
void setup(){
    Serial.begin(9600);
}

void loop(){
    // analogRead(pin) 이다. 
    int senseorValue = analogRead(A0);
    // 우노:  5V -> A0 ~A5 : 10bit 로 되어있다. 
    // 각 아두이노별로 다르다. 
    Serial.print("[LKE LAB] value : ");
    Serial.println(senseorValue);
}