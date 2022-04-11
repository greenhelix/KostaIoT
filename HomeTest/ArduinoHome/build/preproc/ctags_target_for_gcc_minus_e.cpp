# 1 "c:\\GitHub\\KostaIoT\\HomeTest\\ArduinoHome\\app.ino"
void setup()
{
    pinMode(13, 0x1);
}

void loop()
{
    digitalWrite(13, !(digitalRead(13)));
    delay(1500);
}
