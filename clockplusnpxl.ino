#include <PicoEspTime.h>
#include <Adafruit_NeoPixel.h>

PicoEspTime rtc;

uint32_t lastTime;

#define PIN 6
#define NUMPIXELS 8
// 130 pins for bypass (one led is out), 131 total (really there are 132, but led 0)

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 1000

void setup() {
  Serial.begin(115200);
  rtc.adjust(1, 26, 00, 2023, 11, 14);  // EXAMPLE: 01:26:21 03 Jun 2022 (SETS THE TIME WITH DATE VALUES)
                                        // rtc.adjust(1654219721); // Friday, June 03 2022 01:28:41 (SETS THE TIME WITH UNIX EPOCH TIME)
  pixels.begin();                       // initialize neopixel object
}

void loop() {
  if (millis() - lastTime >= 1000) {
    rtc.read();
    PrintTime();
    lastTime = millis();
  }

  pixels.clear();  // all pixels off

  for (int i = 0; i < NUMPIXELS; i++) {
    if(rtc.second >= 30) {
    pixels.setPixelColor(i, pixels.Color(255, 0, 0));  //(r,g,b), 0-255
    pixels.show();
    }
    if(rtc.second < 30) {
      pixels.setPixelColor(i, pixels.Color(0,255,0));
      pixels.show();
    }
  }
}
void PrintTime() {
  Serial.println(rtc.getTime("%A, %B %d %Y %H:%M:%S"));  // (String) returns time with specified format
                                                         // formating options  https://www.cplusplus.com/reference/ctime/strftime/

  Serial.println("");
  Serial.println(rtc.getEpoch());  //  (long)    1647216003
  Serial.println(rtc.second);      //  (int)     30    (0-59)
  Serial.println(rtc.minute);      //  (int)     58    (0-59)
  Serial.println(rtc.hour);        //  (int)     0     (0-23)
  Serial.println(rtc.dayOfMonth);  //  (int)     14    (1-31)
  Serial.println(rtc.month);       //  (int)     3     (1-12)
  Serial.println(rtc.year);        //  (int)     2022
  Serial.println(rtc.dayOfWeek);   //  (int)     1     (0-6)
  Serial.println("");
}
