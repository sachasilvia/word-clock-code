#include <PicoEspTime.h>
#include <Adafruit_NeoPixel.h>
#define PIN 6
#define NUMPIXELS 129
PicoEspTime rtc;
uint32_t lastTime;
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
void setup() {
  rtc.adjust(23, 59, 55, 2023, 11, 16);
  pixels.clear();                       
  rtc.read();
   for (int past = 67; past < 71; past++) {
    if ((rtc.minute >= 5) && (rtc.minute <= 29)) {
      pixels.setPixelColor(past, pixels.Color(255, 0, 0));
    } else {
      pixels.setPixelColor(past, pixels.Color(0, 0, 0));
    }
  }
  for (int to = 66; to < 68; to++) {
    if (rtc.minute >= 30) {
      pixels.setPixelColor(to, pixels.Color(255, 0, 0));
    } else {
      pixels.setPixelColor(66, pixels.Color(0, 0, 0));
    }
  }
  pixels.show();
}
void loop() {
  if (millis() - lastTime >= 1000) {
    rtc.read();
    lastTime = millis();
    for (int past = 67; past < 71; past++) {
      if ((rtc.minute >= 5) && (rtc.minute <= 29)) {
        pixels.setPixelColor(past, pixels.Color(255, 0, 0));
      } else {
        pixels.setPixelColor(past, pixels.Color(0, 0, 0));
      }
    }
    for (int to = 66; to < 68; to++) {
    if (rtc.minute >= 30) {
      pixels.setPixelColor(to, pixels.Color(255, 0, 0));
    } else {
      pixels.setPixelColor(66, pixels.Color(0, 0, 0));
    }
  }
    pixels.show();
  }
}
