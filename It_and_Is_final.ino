#include <PicoEspTime.h>
#include <Adafruit_NeoPixel.h>
#define PIN 6
#define NUMPIXELS 129
PicoEspTime rtc;
uint32_t lastTime;
int hour;
int lasthour;
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
void setup() {
  rtc.adjust(23, 59, 55, 2023, 11, 16);
  pixels.clear();
  rtc.read();
  for (int it = 0; it < 1; it++) {
    pixels.setPixelColor(it, pixels.Color(255, 0, 0));
  }
  for (int is = 2; is < 4; is++) {
    pixels.setPixelColor(is, pixels.Color(255, 0, 0));
  }
  pixels.show();
}
void loop() {
  if (millis() - lastTime >= 1000) {
    rtc.read();
    lastTime = millis();
    if(rtc.hour){
    for (int it = 0; it < 1; it++) {
      pixels.setPixelColor(it, pixels.Color(255, 0, 0));
    }
    for (int is = 2; is < 4; is++) {
      pixels.setPixelColor(is, pixels.Color(255, 0, 0));
    }
    }
    pixels.show();
  }
}