#include <analogWrite.h>
#include <ESP32PWM.h>
#include <WiFi.h>

const char* ssid     = "bulletTeam";
const char* password = "shooting";
char mesg[8] = "1";
int cnt = 0;
int avr_light =0,sum_light=0;

int Light;

void setup()
{
    Serial.begin(9600);
    delay(10);
    
}

void loop()
{
    Light = analogRead(33); 

    WiFiClient client;

    Serial.print("LIGHT::");
    Serial.println(Light);

    if(0 < Light && Light > 710) 
    {   
        cnt++;
        sum_light = (sum_light + Light);
        avr_light = sum_light / cnt;
        if(cnt > 50 && avr_light > 710){
            WiFi.begin(ssid, password);

            while(WiFi.status() != WL_CONNECTED){
                delay(500);
                Serial.print(".");
            } 

            if(!client.connect("10.3.141.194", 5100)){       
                Serial.println("TCP wifi connect FAIL");
                delay(1000);
                return;
            }
                   
            client.write(mesg); 
            cnt = 0; 
            sum_light=0;
            client.stop();
            WiFi.disconnect();
            ESP.restart();
        }
        else if(cnt > 50 && avr_light < 710){
            cnt = 0; 
            sum_light=0;
        }

        delay(100);
        
    }
    
}
