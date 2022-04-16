#include <Arduino.h>
#line 1 "c:\\GitHub\\KostaIoT\\HomeTest\\ArduinoHome\\gpsTest.ino"
#include <SoftwareSerial.h>
#include <TinyGPS.h>

TinyGPS gps;
SoftwareSerial uart_gps(6, 5);
void getgps(TinyGPS &gps);
#line 7 "c:\\GitHub\\KostaIoT\\HomeTest\\ArduinoHome\\gpsTest.ino"
void setup();
#line 17 "c:\\GitHub\\KostaIoT\\HomeTest\\ArduinoHome\\gpsTest.ino"
void loop();
#line 7 "c:\\GitHub\\KostaIoT\\HomeTest\\ArduinoHome\\gpsTest.ino"
void setup()
{
    Serial.begin(9600);
    uart_gps.begin(9600);
    Serial.println("");
    Serial.println("GPS Shield QuickStart Example Sketch v12");
    Serial.println("       …waiting for lock…           ");
    Serial.println("");
}

void loop()
{
    while (uart_gps.available()) // While there is data on the RX pin…
    {
        int c = uart_gps.read(); // load the data into a variable…
        if (gps.encode(c))       // if there is a new valid sentence…
        {
            getgps(gps); // then grab the data.
        }
    }
}

void getgps(TinyGPS &gps)
{
    float lat, lon;
    Serial.print("Lat/Long:: ");
    Serial.print(lat, 5);
    Serial.print(", ");
    Serial.print(lon, 5);
    delay(1);
}
