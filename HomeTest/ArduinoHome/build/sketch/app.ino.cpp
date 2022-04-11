#include <Arduino.h>
#line 1 "c:\\GitHub\\KostaIoT\\HomeTest\\ArduinoHome\\app.ino"
#line 1 "c:\\GitHub\\KostaIoT\\HomeTest\\ArduinoHome\\app.ino"
void setup();
#line 6 "c:\\GitHub\\KostaIoT\\HomeTest\\ArduinoHome\\app.ino"
void loop();
#line 1 "c:\\GitHub\\KostaIoT\\HomeTest\\ArduinoHome\\app.ino"
void setup()
{
    pinMode(13, OUTPUT);
}

void loop()
{
    digitalWrite(13, !(digitalRead(13)));
    delay(1500);
}
