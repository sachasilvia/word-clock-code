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
    if ((rtc.minute >= 5) && (rtc.minute <= 34)) {
      pixels.setPixelColor(past, pixels.Color(255, 0, 0));
    } else {
      pixels.setPixelColor(past, pixels.Color(0, 0, 0));
    }
  }
  for (int to = 66; to < 68; to++) {
    if (rtc.minute >= 35) {
      pixels.setPixelColor(to, pixels.Color(255, 0, 0));
    } else {
      pixels.setPixelColor(66, pixels.Color(0, 0, 0));
    }
  }
  for (int oclock = 124; oclock < 130; oclock++) {
    pixels.setPixelColor(oclock, pixels.Color(255, 0, 0));
  }

  for (int fivem = 29; fivem < 33; fivem++) {
    if (((rtc.minute >= 5) && (rtc.minute < 10)) || ((rtc.minute >= 25) && (rtc.minute < 30)) || ((rtc.minute >= 35) && (rtc.minute < 40)) || (rtc.minute >= 55)) {
      pixels.setPixelColor(fivem, pixels.Color(255, 0, 0));
    } else {
      pixels.setPixelColor(fivem, pixels.Color(0, 0, 0));
    }
  }
  for (int tenm = 37; tenm < 40; tenm++) {
    if (((rtc.minute >= 10) && (rtc.minute < 15)) || ((rtc.minute >= 50) && (rtc.minute < 55))) {
      pixels.setPixelColor(tenm, pixels.Color(255, 0, 0));
    } else {
      pixels.setPixelColor(tenm, pixels.Color(0, 0, 0));
    }
  }
  for (int fifteenm = 14; fifteenm < 21; fifteenm++) {
    if (((rtc.minute >= 15) && (rtc.minute < 20)) || ((rtc.minute >= 45) && (rtc.minute < 50))) {
      pixels.setPixelColor(fifteenm, pixels.Color(255, 0, 0));
    } else {
      pixels.setPixelColor(fifteenm, pixels.Color(0, 0, 0));
    }
  }
  for (int twentym = 23; twentym < 29; twentym++) {
    if (((rtc.minute >= 20) && (rtc.minute < 30)) || ((rtc.minute >= 35) && (rtc.minute < 45))) {
      pixels.setPixelColor(twentym, pixels.Color(255, 0, 0));
    } else {
      pixels.setPixelColor(twentym, pixels.Color(0, 0, 0));
    }
  }
  for (int thirtym = 41; thirtym < 47; thirtym++) {
    if ((rtc.minute >= 30) && (rtc.minute < 35)) {
      pixels.setPixelColor(thirtym, pixels.Color(255, 0, 0));
    } else {
      pixels.setPixelColor(thirtym, pixels.Color(0, 0, 0));
    }
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
      if ((rtc.minute >= 5) && (rtc.minute <= 34)) {
        pixels.setPixelColor(past, pixels.Color(255, 0, 0));
      } else {
        pixels.setPixelColor(past, pixels.Color(0, 0, 0));
      }
    }
    for (int to = 66; to < 68; to++) {
      if (rtc.minute >= 35) {
        pixels.setPixelColor(to, pixels.Color(255, 0, 0));
      } else {
        pixels.setPixelColor(66, pixels.Color(0, 0, 0));
      }
    }
    for (int oclock = 124; oclock < 130; oclock++) {
      pixels.setPixelColor(oclock, pixels.Color(255, 0, 0));
    }
    for (int fivem = 29; fivem < 33; fivem++) {
      if (((rtc.minute >= 5) && (rtc.minute < 10)) || ((rtc.minute >= 25) && (rtc.minute < 30)) || ((rtc.minute >= 35) && (rtc.minute < 40)) || (rtc.minute >= 55)) {
        pixels.setPixelColor(fivem, pixels.Color(255, 0, 0));
      } else {
        pixels.setPixelColor(fivem, pixels.Color(0, 0, 0));
      }
    }
    for (int tenm = 37; tenm < 40; tenm++) {
      if (((rtc.minute >= 10) && (rtc.minute < 15)) || ((rtc.minute >= 50) && (rtc.minute < 55))) {
        pixels.setPixelColor(tenm, pixels.Color(255, 0, 0));
      } else {
        pixels.setPixelColor(tenm, pixels.Color(0, 0, 0));
      }
    }
    for (int fifteenm = 14; fifteenm < 21; fifteenm++) {
      if (((rtc.minute >= 15) && (rtc.minute < 20)) || ((rtc.minute >= 45) && (rtc.minute < 50))) {
        pixels.setPixelColor(fifteenm, pixels.Color(255, 0, 0));
      } else {
        pixels.setPixelColor(fifteenm, pixels.Color(0, 0, 0));
      }
    }
    for (int twentym = 23; twentym < 29; twentym++) {
      if (((rtc.minute >= 20) && (rtc.minute < 30)) || ((rtc.minute >= 35) && (rtc.minute < 45))) {
        pixels.setPixelColor(twentym, pixels.Color(255, 0, 0));
      } else {
        pixels.setPixelColor(twentym, pixels.Color(0, 0, 0));
      }
    }
    for (int thirtym = 41; thirtym < 47; thirtym++) {
      if ((rtc.minute >= 30) && (rtc.minute < 35)) {
        pixels.setPixelColor(thirtym, pixels.Color(255, 0, 0));
      } else {
        pixels.setPixelColor(thirtym, pixels.Color(0, 0, 0));
      }
    }
    pixels.show();
  }
}
void PrintTime() {
  Serial.println(rtc.getTime("%A, %B %d %Y %H:%M:%S"));
  Serial.println("");
  Serial.println(rtc.second);
  Serial.println(rtc.minute);
  Serial.println(rtc.hour);
  Serial.println("");
}
