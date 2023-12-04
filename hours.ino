#include <PicoEspTime.h>
#include <Adafruit_NeoPixel.h>
#define PIN 6
#define NUMPIXELS 129
PicoEspTime rtc;
uint32_t lastTime;
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
void PrintTime(void);
void setup() {
  Serial.begin(115200);
  rtc.adjust(23, 34, 55, 2023, 11, 16);
  pixels.begin();
  pixels.clear();
  rtc.read();
  PrintTime();
  lastTime = millis();
  for (int oneh; oneh = 107; oneh < 110) {
    if (((rtc.hour == 1) && (rtc.minute < 35)) || ((rtc.hour == 13) && (rtc.minute < 35)) || ((rtc.hour == 12) && (rtc.minute >= 35)) || ((rtc.hour == 0) && (rtc.minute >= 35))) {
      pixels.setPixelColor(oneh, pixels.Color(255, 0, 0));
    } else {
      pixels.setPixelColor(oneh, pixels.Color(0, 0, 0));
    }
  }
  for (int twoh; twoh = 82; twoh < 85) {
    if (((rtc.hour == 2) && (rtc.minute < 35)) || ((rtc.hour == 14) && (rtc.minute < 35)) || ((rtc.hour == 13) && (rtc.minute >= 35)) || ((rtc.hour == 1) && (rtc.minute >= 35))) {
      pixels.setPixelColor(twoh, pixels.Color(255, 0, 0));
    } else {
      pixels.setPixelColor(twoh, pixels.Color(0, 0, 0));
    }
  }
  for (int threeh; threeh = 110; threeh < 115) {
    if (((rtc.hour == 3) && (rtc.minute < 35)) || ((rtc.hour == 15) && (rtc.minute < 35)) || ((rtc.hour == 14) && (rtc.minute >= 35)) || ((rtc.hour == 2) && (rtc.minute >= 35))) {
      pixels.setPixelColor(threeh, pixels.Color(255, 0, 0));
    } else {
      pixels.setPixelColor(threeh, pixels.Color(0, 0, 0));
    }
  }
  for (int fourh; fourh = 60; fourh < 64) {
    if (((rtc.hour == 4) && (rtc.minute < 35)) || ((rtc.hour == 16) && (rtc.minute < 35)) || ((rtc.hour == 15) && (rtc.minute >= 35)) || ((rtc.hour == 3) && (rtc.minute >= 35))) {
      pixels.setPixelColor(fourh, pixels.Color(255, 0, 0));
    } else {
      pixels.setPixelColor(fourh, pixels.Color(0, 0, 0));
    }
  }
  for (int fiveh; fiveh = 86; fiveh < 90) {
    if (((rtc.hour == 5) && (rtc.minute < 35)) || ((rtc.hour == 17) && (rtc.minute < 35)) || ((rtc.hour == 16) && (rtc.minute >= 35)) || ((rtc.hour == 4) && (rtc.minute >= 35))) {
      pixels.setPixelColor(fiveh, pixels.Color(255, 0, 0));
    } else {
      pixels.setPixelColor(fiveh, pixels.Color(0, 0, 0));
    }
  }
  for (int sixh; sixh = 115; sixh < 118) {
    if (((rtc.hour == 6) && (rtc.minute < 35)) || ((rtc.hour == 18) && (rtc.minute < 35)) || ((rtc.hour == 17) && (rtc.minute >= 35)) || ((rtc.hour == 5) && (rtc.minute >= 35))) {
      pixels.setPixelColor(sixh, pixels.Color(255, 0, 0));
    } else {
      pixels.setPixelColor(sixh, pixels.Color(0, 0, 0));
    }
  }
  for (int sevenh; sevenh = 71; sevenh < 76) {
    if (((rtc.hour == 7) && (rtc.minute < 35)) || ((rtc.hour == 19) && (rtc.minute < 35)) || ((rtc.hour == 18) && (rtc.minute >= 35)) || ((rtc.hour == 6) && (rtc.minute >= 35))) {
      pixels.setPixelColor(sevenh, pixels.Color(255, 0, 0));
    } else {
      pixels.setPixelColor(sevenh, pixels.Color(0, 0, 0));
    }
  }
  for (int eighth; eighth = 94; eighth < 99) {
    if (((rtc.hour == 8) && (rtc.minute < 35)) || ((rtc.hour == 20) && (rtc.minute < 35)) || ((rtc.hour == 19) && (rtc.minute >= 35)) || ((rtc.hour == 7) && (rtc.minute >= 35))) {
      pixels.setPixelColor(eighth, pixels.Color(255, 0, 0));
    } else {
      pixels.setPixelColor(eighth, pixels.Color(0, 0, 0));
    }
  }
  for (int nineh; nineh = 90; nineh < 94) {
    if (((rtc.hour == 9) && (rtc.minute < 35)) || ((rtc.hour == 21) && (rtc.minute < 35)) || ((rtc.hour == 20) && (rtc.minute >= 35)) || ((rtc.hour == 8) && (rtc.minute >= 35))) {
      pixels.setPixelColor(nineh, pixels.Color(255, 0, 0));
    } else {
      pixels.setPixelColor(nineh, pixels.Color(0, 0, 0));
    }
  }
  for (int tenh; tenh = 118; tenh < 121) {
    if (((rtc.hour == 10) && (rtc.minute < 35)) || ((rtc.hour == 22) && (rtc.minute < 35)) || ((rtc.hour == 21) && (rtc.minute >= 35)) || ((rtc.hour == 9) && (rtc.minute >= 35))) {
      pixels.setPixelColor(tenh, pixels.Color(255, 0, 0));
    } else {
      pixels.setPixelColor(tenh, pixels.Color(0, 0, 0));
    }
  }
   for (int elevenh; elevenh = 100; elevenh < 106) {
    if (((rtc.hour == 11) && (rtc.minute < 35)) || ((rtc.hour == 23) && (rtc.minute < 35)) || ((rtc.hour == 22) && (rtc.minute >= 35)) || ((rtc.hour == 10) && (rtc.minute >= 35))) {
      pixels.setPixelColor(elevenh, pixels.Color(255, 0, 0));
    } else {
      pixels.setPixelColor(elevenh, pixels.Color(0, 0, 0));
    }
  }
   for (int twelveh; twelveh = 77; twelveh < 82) {
    if (((rtc.hour == 12) && (rtc.minute < 35)) || ((rtc.hour == 0) && (rtc.minute < 35)) || ((rtc.hour == 23) && (rtc.minute >= 35)) || ((rtc.hour == 11) && (rtc.minute >= 35))) {
      pixels.setPixelColor(twelveh, pixels.Color(255, 0, 0));
    } else {
      pixels.setPixelColor(twelveh, pixels.Color(0, 0, 0));
    }
  }
  pixels.show();
}
void loop() {
  if (millis() - lastTime >= 1000) {
    rtc.read();
    PrintTime();
    lastTime = millis();
    for (int oneh; oneh = 107; oneh < 110) {
    if (((rtc.hour == 1) && (rtc.minute < 35)) || ((rtc.hour == 13) && (rtc.minute < 35)) || ((rtc.hour == 12) && (rtc.minute >= 35)) || ((rtc.hour == 0) && (rtc.minute >= 35))) {
      pixels.setPixelColor(oneh, pixels.Color(255, 0, 0));
    } else {
      pixels.setPixelColor(oneh, pixels.Color(0, 0, 0));
    }
  }
  for (int twoh; twoh = 82; twoh < 85) {
    if (((rtc.hour == 2) && (rtc.minute < 35)) || ((rtc.hour == 14) && (rtc.minute < 35)) || ((rtc.hour == 13) && (rtc.minute >= 35)) || ((rtc.hour == 1) && (rtc.minute >= 35))) {
      pixels.setPixelColor(twoh, pixels.Color(255, 0, 0));
    } else {
      pixels.setPixelColor(twoh, pixels.Color(0, 0, 0));
    }
  }
  for (int threeh; threeh = 110; threeh < 115) {
    if (((rtc.hour == 3) && (rtc.minute < 35)) || ((rtc.hour == 15) && (rtc.minute < 35)) || ((rtc.hour == 14) && (rtc.minute >= 35)) || ((rtc.hour == 2) && (rtc.minute >= 35))) {
      pixels.setPixelColor(threeh, pixels.Color(255, 0, 0));
    } else {
      pixels.setPixelColor(threeh, pixels.Color(0, 0, 0));
    }
  }
  for (int fourh; fourh = 60; fourh < 64) {
    if (((rtc.hour == 4) && (rtc.minute < 35)) || ((rtc.hour == 16) && (rtc.minute < 35)) || ((rtc.hour == 15) && (rtc.minute >= 35)) || ((rtc.hour == 3) && (rtc.minute >= 35))) {
      pixels.setPixelColor(fourh, pixels.Color(255, 0, 0));
    } else {
      pixels.setPixelColor(fourh, pixels.Color(0, 0, 0));
    }
  }
  for (int fiveh; fiveh = 86; fiveh < 90) {
    if (((rtc.hour == 5) && (rtc.minute < 35)) || ((rtc.hour == 17) && (rtc.minute < 35)) || ((rtc.hour == 16) && (rtc.minute >= 35)) || ((rtc.hour == 4) && (rtc.minute >= 35))) {
      pixels.setPixelColor(fiveh, pixels.Color(255, 0, 0));
    } else {
      pixels.setPixelColor(fiveh, pixels.Color(0, 0, 0));
    }
  }
  for (int sixh; sixh = 115; sixh < 118) {
    if (((rtc.hour == 6) && (rtc.minute < 35)) || ((rtc.hour == 18) && (rtc.minute < 35)) || ((rtc.hour == 17) && (rtc.minute >= 35)) || ((rtc.hour == 5) && (rtc.minute >= 35))) {
      pixels.setPixelColor(sixh, pixels.Color(255, 0, 0));
    } else {
      pixels.setPixelColor(sixh, pixels.Color(0, 0, 0));
    }
  }
  for (int sevenh; sevenh = 71; sevenh < 76) {
    if (((rtc.hour == 7) && (rtc.minute < 35)) || ((rtc.hour == 19) && (rtc.minute < 35)) || ((rtc.hour == 18) && (rtc.minute >= 35)) || ((rtc.hour == 6) && (rtc.minute >= 35))) {
      pixels.setPixelColor(sevenh, pixels.Color(255, 0, 0));
    } else {
      pixels.setPixelColor(sevenh, pixels.Color(0, 0, 0));
    }
  }
  for (int eighth; eighth = 94; eighth < 99) {
    if (((rtc.hour == 8) && (rtc.minute < 35)) || ((rtc.hour == 20) && (rtc.minute < 35)) || ((rtc.hour == 19) && (rtc.minute >= 35)) || ((rtc.hour == 7) && (rtc.minute >= 35))) {
      pixels.setPixelColor(eighth, pixels.Color(255, 0, 0));
    } else {
      pixels.setPixelColor(eighth, pixels.Color(0, 0, 0));
    }
  }
  for (int nineh; nineh = 90; nineh < 94) {
    if (((rtc.hour == 9) && (rtc.minute < 35)) || ((rtc.hour == 21) && (rtc.minute < 35)) || ((rtc.hour == 20) && (rtc.minute >= 35)) || ((rtc.hour == 8) && (rtc.minute >= 35))) {
      pixels.setPixelColor(nineh, pixels.Color(255, 0, 0));
    } else {
      pixels.setPixelColor(nineh, pixels.Color(0, 0, 0));
    }
  }
  for (int tenh; tenh = 118; tenh < 121) {
    if (((rtc.hour == 10) && (rtc.minute < 35)) || ((rtc.hour == 22) && (rtc.minute < 35)) || ((rtc.hour == 21) && (rtc.minute >= 35)) || ((rtc.hour == 9) && (rtc.minute >= 35))) {
      pixels.setPixelColor(tenh, pixels.Color(255, 0, 0));
    } else {
      pixels.setPixelColor(tenh, pixels.Color(0, 0, 0));
    }
  }
   for (int elevenh; elevenh = 100; elevenh < 106) {
    if (((rtc.hour == 11) && (rtc.minute < 35)) || ((rtc.hour == 23) && (rtc.minute < 35)) || ((rtc.hour == 22) && (rtc.minute >= 35)) || ((rtc.hour == 10) && (rtc.minute >= 35))) {
      pixels.setPixelColor(elevenh, pixels.Color(255, 0, 0));
    } else {
      pixels.setPixelColor(elevenh, pixels.Color(0, 0, 0));
    }
  }
   for (int twelveh; twelveh = 77; twelveh < 82) {
    if (((rtc.hour == 12) && (rtc.minute < 35)) || ((rtc.hour == 0) && (rtc.minute < 35)) || ((rtc.hour == 23) && (rtc.minute >= 35)) || ((rtc.hour == 11) && (rtc.minute >= 35))) {
      pixels.setPixelColor(twelveh, pixels.Color(255, 0, 0));
    } else {
      pixels.setPixelColor(twelveh, pixels.Color(0, 0, 0));
    }
  }
  }
  pixels.show();
}
void PrintTime() {
  Serial.println(rtc.getTime("%A, %B %d %Y %H:%M:%S"));
  Serial.println("");
  Serial.println(rtc.second);
  Serial.println(rtc.minute);
  Serial.println(rtc.hour);
  Serial.println("");
}
