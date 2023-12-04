
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
  rtc.adjust(23, 9, 55, 2023, 11, 16);
  pixels.begin();
  pixels.clear();
    rtc.read();
    PrintTime();
    lastTime = millis();
    for (int fivem = 29; fivem < 33; fivem++) {
      if (((rtc.minute >= 5) && (rtc.minute < 10)) || (rtc.minute >= 55)) {
        pixels.setPixelColor(fivem, pixels.Color(255, 0, 0));
      } else {
        pixels.setPixelColor(fivem, pixels.Color(0, 0, 0));
      }
    }
    for (int tenm = 37; tenm < 40; tenm++) {
    if ( ( (rtc.minute >= 10) && (rtc.minute < 15) ) || ( (rtc.minute >= 50) && (rtc.minute < 55) ) ) {
      pixels.setPixelColor(tenm, pixels.Color(255, 0, 0));
    } else {
      pixels.setPixelColor(tenm, pixels.Color(0, 0, 0));
    }
  }
   for (int fifteenm = 14; fifteenm < 21; fifteenm++) {
    if ( ( (rtc.minute >= 15) && (rtc.minute < 20) ) || ( (rtc.minute >= 45) && (rtc.minute < 50) ) ) {
      pixels.setPixelColor(fifteenm, pixels.Color(255, 0, 0));
    } else {
      pixels.setPixelColor(fifteenm, pixels.Color(0, 0, 0));
    }
   }
    for (int twentym = 23; twentym < 29; twentym++) {
    if ( ( (rtc.minute) >= 20 && (rtc.minute < 25) ) || ( (rtc.minute >= 40) && (rtc.minute < 45) ) ) {
      pixels.setPixelColor(twentym, pixels.Color(255, 0, 0));
    } else {
      pixels.setPixelColor(twentym, pixels.Color(0, 0, 0));
    }
  }
   for (int twentyfivem = 23; twentyfivem < 33; twentyfivem++) {
    if ( ( (rtc.minute >= 25) && (rtc.minute < 30) ) || ( (rtc.minute >= 35) && (rtc.minute < 40) ) ) {
      pixels.setPixelColor(twentyfivem, pixels.Color(255, 0, 0));
    } else {
      pixels.setPixelColor(twentyfivem, pixels.Color(0, 0, 0));
    }
  }
   for (int thirtym = 41; thirtym < 47; thirtym++) {
    if ( (rtc.minute >= 30) && (rtc.minute < 35) ) {
      pixels.setPixelColor(thirtym, pixels.Color(255, 0, 0));
    } else {
      pixels.setPixelColor(thirtym, pixels.Color(0, 0, 0));
    }
  }
  pixels.show();
}


void loop() {
  //delay in seconds for how frequent it checks, if over 10k use L for long int (ENTIRE LOOP GOES IN THIS IF LOOP)
  if (millis() - lastTime >= 1000) {

    // grab time
    rtc.read();
    PrintTime();
    lastTime = millis();
    for (int fivem = 29; fivem < 33; fivem++) {
      if (((rtc.minute >= 5) && (rtc.minute < 10)) || (rtc.minute >= 55)) {
        pixels.setPixelColor(fivem, pixels.Color(255, 0, 0));
      } else {
        pixels.setPixelColor(fivem, pixels.Color(0, 0, 0));
      }
    }
    for (int tenm = 37; tenm < 40; tenm++) {
    if ( ( (rtc.minute >= 10) && (rtc.minute < 15) ) || ( (rtc.minute >= 50) && (rtc.minute < 55) ) ) {
      pixels.setPixelColor(tenm, pixels.Color(255, 0, 0));
    } else {
      pixels.setPixelColor(tenm, pixels.Color(0, 0, 0));
    }
  }
   for (int fifteenm = 14; fifteenm < 21; fifteenm++) {
    if ( ( (rtc.minute >= 15) && (rtc.minute < 20) ) || ( (rtc.minute >= 45) && (rtc.minute < 50) ) ) {
      pixels.setPixelColor(fifteenm, pixels.Color(255, 0, 0));
    } else {
      pixels.setPixelColor(fifteenm, pixels.Color(0, 0, 0));
    }
   }
    for (int twentym = 23; twentym < 29; twentym++) {
    if ( ( (rtc.minute >= 20) && (rtc.minute < 25) ) || ( (rtc.minute >= 40) && (rtc.minute < 45) ) ) {
      pixels.setPixelColor(twentym, pixels.Color(255, 0, 0));
    } else {
      pixels.setPixelColor(twentym, pixels.Color(0, 0, 0));
    }
  }
   for (int twentyfivem = 23; twentyfivem < 33; twentyfivem++) {
    if ( ( (rtc.minute >= 25) && (rtc.minute < 30) ) || ( (rtc.minute >= 35) && (rtc.minute < 40) ) ) {
      pixels.setPixelColor(twentyfivem, pixels.Color(255, 0, 0));
    } else {
      pixels.setPixelColor(twentyfivem, pixels.Color(0, 0, 0));
    }
  }
   for (int thirtym = 41; thirtym < 47; thirtym++) {
    if ( (rtc.minute >= 30) && (rtc.minute < 35) ) {
      pixels.setPixelColor(thirtym, pixels.Color(255, 0, 0));
    } else {
      pixels.setPixelColor(thirtym, pixels.Color(0, 0, 0));
    }
  }
}
  pixels.show();
}
void PrintTime() {
  Serial.println(rtc.getTime("%A, %B %d %Y %H:%M:%S"));  // (String) returns time with specified format
                                                         // formating opti`ons  https://www.cplusplus.com/reference/ctime/strftime/

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