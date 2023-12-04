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
    PrintTime();
    lastTime = millis();

    for (int it = 0; it < 1; it++) {
      pixels.setPixelColor(it, pixels.Color(255, 0, 0));
    }
    for (int is = 2; is < 4; is++) {
      pixels.setPixelColor(is, pixels.Color(255, 0, 0));
    }
    for (int mins = 47; mins < 54; mins++) {
      if (rtc.minute >= 5) {
        pixels.setPixelColor(mins, pixels.Color(255, 0, 0));
      } else {
        pixels.setPixelColor(mins, pixels.Color(0, 0, 0));
      }
    }
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
    for(int oclock = 124; oclock < 130; oclock++) {
      pixels.setPixelColor(oclock, pixels.Color(255,0,0));
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
