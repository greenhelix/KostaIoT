#include<IRremote.h>
int RECV_PIN = 2; 
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup(){ 
    Serial.begin(9600);
    irrecv.enableIRIn();

}
// 16진수 리모컨 키값
void loop(){
    if(irrecv.decode(&results)){
        if(results.decode_type == NEC){
            Serial.print("PUSH KEY ID: ");
            Serial.println(results.value);
            switch (results.value)
            {
            case 16769055:
                Serial.println("Press '-'");
                break;
            case 16750695:
                Serial.println("Press '+100'");
                break;
            case 16756815:
                Serial.println("Press '+200'");
                break;
            case 16738455:
                Serial.println("Press '0'");
                break;
            case 16724175: // Key 1
                Serial.println("Press '1'"); // 시리얼통신으로 데이터 출력 "Press '1'"
                break;
            case 16718055: // Key 2
                Serial.println("Press '2'"); // 시리얼통신으로 데이터 출력 "Press '2'"
                break;
            case 16743045: // Key 3
                Serial.println("Press '3'"); // 시리얼통신으로 데이터 출력 "Press '3'"
                break;
            case 16716015: // Key 4
                Serial.println("Press '4'"); // 시리얼통신으로 데이터 출력 "Press '4'"
                break;
            case 16726215: // Key 5
                Serial.println("Press '5'"); // 시리얼통신으로 데이터 출력 "Press '5'"
                break;
            case 16734885: // Key 6
                Serial.println("Press '6'"); // 시리얼통신으로 데이터 출력 "Press '6'"
                break;
            case 16728765: // Key 7
                Serial.println("Press '7'"); // 시리얼통신으로 데이터 출력 "Press '7'"
                break;
            case 16730805: // Key 8
                Serial.println("Press '8'"); // 시리얼통신으로 데이터 출력 "Press '8'"
                break;
            case 16732845: // Key 9
                Serial.println("Press '9'"); // 시리얼통신으로 데이터 출력 "Press '9'"
                break;
            default:
                break;
            }   
        }
        irrecv.resume();
    }
}