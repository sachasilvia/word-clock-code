#include <PicoEspTime.h>
#include <Adafruit_NeoPixel.h>
#define PIN 6
#define NUMPIXELS 129
PicoEspTime rtc;
uint32_t lastTime;
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
void PrintTime(void);
void setled(int, int, int);
void setled(int start, int end, int on) {
  for (int pixel = start; pixel < end + 1; pixel++) {
    if (on == true) {
      pixels.setPixelColor(pixel, pixels.Color(255, 0, 0));

    } else {
      pixels.setPixelColor(pixel, pixels.Color(0, 0, 0));
    }
    pixels.show();
  }
}
void setup() {
  Serial.begin(115200);
  rtc.adjust(1, 43, 50, 2023, 12, 4);
  pixels.begin();
  pixels.clear();
  rtc.read();
  PrintTime();
  lastTime = millis();
  setled(0, 0, true);  //it
  setled(2, 3, true);  //is
  if (rtc.minute >= 5) {
    setled(67, 67, true);  //t for past and to
  }
  if (rtc.minute >= 5) {
    setled(47, 53, true);  //minutes
  } else {
    setled(47, 53, false);
  }
  if ((rtc.minute >= 5) && (rtc.minute <= 34)) {
    setled(68, 70, true);  //past (techincally turns on pas)
  } else {
    setled(68, 70, false);
  }
  if (rtc.minute >= 35) {
    setled(66, 66, true);  //to (technically turns on o)
  } else {
    setled(66, 66, false);
  }
  setled(124, 129, true);  //oclock
  if (((rtc.minute >= 5) && (rtc.minute < 10)) || ((rtc.minute >= 25) && (rtc.minute < 30)) || ((rtc.minute >= 35) && (rtc.minute < 40)) || (rtc.minute >= 55)) {
    setled(29, 32, true);
  } else {
    setled(29, 32, false);  // five (minutes)
  }
  if (((rtc.minute >= 10) && (rtc.minute < 15)) || ((rtc.minute >= 50) && (rtc.minute < 55))) {
    setled(37, 39, true);  // ten (minutes)
  } else {
    setled(37, 39, false);
  }
  if (((rtc.minute >= 15) && (rtc.minute < 20)) || ((rtc.minute >= 45) && (rtc.minute < 50))) {
    setled(14, 20, true);  // fifteen (minutes)
  } else {
    setled(14, 20, false);
  }
  if (((rtc.minute >= 20) && (rtc.minute < 30)) || ((rtc.minute >= 35) && (rtc.minute < 45))) {
    setled(23, 28, true);  // twenty (minutes)
  } else {
    setled(23, 28, false);
  }
  if ((rtc.minute >= 30) && (rtc.minute < 35)) {
    setled(41, 46, true);  // thirty (minutes)
  } else {
    setled(41, 46, false);
  }
  if (((rtc.hour == 1) && (rtc.minute < 35)) || ((rtc.hour == 13) && (rtc.minute < 35)) || ((rtc.hour == 12) && (rtc.minute >= 35)) || ((rtc.hour == 0) && (rtc.minute >= 35))) {
    setled(107, 109, true);  //one (hours)
  } else {
    setled(107, 109, false);
  }
  if (((rtc.hour == 2) && (rtc.minute < 35)) || ((rtc.hour == 14) && (rtc.minute < 35)) || ((rtc.hour == 13) && (rtc.minute >= 35)) || ((rtc.hour == 1) && (rtc.minute >= 35))) {
    setled(82, 84, true);  //two (hours)
  } else {
    setled(82, 84, false);
  }
  if (((rtc.hour == 3) && (rtc.minute < 35)) || ((rtc.hour == 15) && (rtc.minute < 35)) || ((rtc.hour == 14) && (rtc.minute >= 35)) || ((rtc.hour == 2) && (rtc.minute >= 35))) {
    setled(110, 114, true);  //three (hours)
  } else {
    setled(110, 114, false);
  }
  if (((rtc.hour == 4) && (rtc.minute < 35)) || ((rtc.hour == 16) && (rtc.minute < 35)) || ((rtc.hour == 15) && (rtc.minute >= 35)) || ((rtc.hour == 3) && (rtc.minute >= 35))) {
    setled(60, 63, true);  //four (hours)
  } else {
    setled(60, 63, false);
  }
  if (((rtc.hour == 5) && (rtc.minute < 35)) || ((rtc.hour == 17) && (rtc.minute < 35)) || ((rtc.hour == 16) && (rtc.minute >= 35)) || ((rtc.hour == 4) && (rtc.minute >= 35))) {
    setled(86, 89, true);  // five (hours)
  } else {
    setled(86, 89, false);
  }
  if (((rtc.hour == 6) && (rtc.minute < 35)) || ((rtc.hour == 18) && (rtc.minute < 35)) || ((rtc.hour == 17) && (rtc.minute >= 35)) || ((rtc.hour == 5) && (rtc.minute >= 35))) {
    setled(115, 117, true);  // six (hours)
  } else {
    setled(115, 117, false);
  }
  if (((rtc.hour == 7) && (rtc.minute < 35)) || ((rtc.hour == 19) && (rtc.minute < 35)) || ((rtc.hour == 18) && (rtc.minute >= 35)) || ((rtc.hour == 6) && (rtc.minute >= 35))) {
    setled(71, 75, true);  // seven (hours)
  } else {
    setled(71, 75, false);
  }
  if (((rtc.hour == 8) && (rtc.minute < 35)) || ((rtc.hour == 20) && (rtc.minute < 35)) || ((rtc.hour == 19) && (rtc.minute >= 35)) || ((rtc.hour == 7) && (rtc.minute >= 35))) {
    setled(94, 98, true);  // eight (hours)
  } else {
    setled(94, 98, false);
  }
  if (((rtc.hour == 9) && (rtc.minute < 35)) || ((rtc.hour == 21) && (rtc.minute < 35)) || ((rtc.hour == 20) && (rtc.minute >= 35)) || ((rtc.hour == 8) && (rtc.minute >= 35))) {
    setled(90, 93, true);  // nine (hours)
  } else {
    setled(90, 93, false);
  }
  if (((rtc.hour == 10) && (rtc.minute < 35)) || ((rtc.hour == 22) && (rtc.minute < 35)) || ((rtc.hour == 21) && (rtc.minute >= 35)) || ((rtc.hour == 9) && (rtc.minute >= 35))) {
    setled(118, 120, true);  // ten (hours)
  } else {
    setled(118, 120, false);
  }
  if (((rtc.hour == 11) && (rtc.minute < 35)) || ((rtc.hour == 23) && (rtc.minute < 35)) || ((rtc.hour == 22) && (rtc.minute >= 35)) || ((rtc.hour == 10) && (rtc.minute >= 35))) {
    setled(100, 105, true);  // eleven (hours)
  } else {
    setled(100, 105, false);
  }
  if (((rtc.hour == 12) && (rtc.minute < 35)) || ((rtc.hour == 0) && (rtc.minute < 35)) || ((rtc.hour == 23) && (rtc.minute >= 35)) || ((rtc.hour == 11) && (rtc.minute >= 35))) {
    setled(77, 81, true);  // twelve (hours)
  } else {
    setled(77, 81, false);
  }
}
void loop() {
  if (millis() - lastTime >= 1000) {
    rtc.read();
    PrintTime();
    lastTime = millis();
    setled(0, 0, true);  //it
    setled(2, 3, true);  //is
    if (rtc.minute >= 5) {
      setled(67, 67, true);  //t for past and to
    }
    if (rtc.minute >= 5) {
      setled(47, 53, true);  //minutes
    } else {
      setled(47, 53, false);
    }
    if ((rtc.minute >= 5) && (rtc.minute <= 34)) {
      setled(68, 70, true);  //past (techincally turns on pas)
    } else {
      setled(68, 70, false);
    }
    if (rtc.minute >= 35) {
      setled(66, 66, true);  //to (technically turns on o)
    } else {
      setled(66, 66, false);
    }
    setled(124, 129, true);  //oclock
    if (((rtc.minute >= 5) && (rtc.minute < 10)) || ((rtc.minute >= 25) && (rtc.minute < 30)) || ((rtc.minute >= 35) && (rtc.minute < 40)) || (rtc.minute >= 55)) {
      setled(29, 32, true);
    } else {
      setled(29, 32, false);  // five (minutes)
    }
    if (((rtc.minute >= 10) && (rtc.minute < 15)) || ((rtc.minute >= 50) && (rtc.minute < 55))) {
      setled(37, 39, true);  // ten (minutes)
    } else {
      setled(37, 39, false);
    }
    if (((rtc.minute >= 15) && (rtc.minute < 20)) || ((rtc.minute >= 45) && (rtc.minute < 50))) {
      setled(14, 20, true);  // fifteen (minutes)
    } else {
      setled(14, 20, false);
    }
    if (((rtc.minute >= 20) && (rtc.minute < 30)) || ((rtc.minute >= 35) && (rtc.minute < 45))) {
      setled(23, 28, true);  // twenty (minutes)
    } else {
      setled(23, 28, false);
    }
    if ((rtc.minute >= 30) && (rtc.minute < 35)) {
      setled(41, 46, true);  // thirty (minutes)
    } else {
      setled(41, 46, false);
    }
    if (((rtc.hour == 1) && (rtc.minute < 35)) || ((rtc.hour == 13) && (rtc.minute < 35)) || ((rtc.hour == 12) && (rtc.minute >= 35)) || ((rtc.hour == 0) && (rtc.minute >= 35))) {
      setled(107, 109, true);  //one (hours)
    } else {
      setled(107, 109, false);
    }
    if (((rtc.hour == 2) && (rtc.minute < 35)) || ((rtc.hour == 14) && (rtc.minute < 35)) || ((rtc.hour == 13) && (rtc.minute >= 35)) || ((rtc.hour == 1) && (rtc.minute >= 35))) {
      setled(82, 84, true);  //two (hours)
    } else {
      setled(82, 84, false);
    }
    if (((rtc.hour == 3) && (rtc.minute < 35)) || ((rtc.hour == 15) && (rtc.minute < 35)) || ((rtc.hour == 14) && (rtc.minute >= 35)) || ((rtc.hour == 2) && (rtc.minute >= 35))) {
      setled(110, 114, true);  //three (hours)
    } else {
      setled(110, 114, false);
    }
    if (((rtc.hour == 4) && (rtc.minute < 35)) || ((rtc.hour == 16) && (rtc.minute < 35)) || ((rtc.hour == 15) && (rtc.minute >= 35)) || ((rtc.hour == 3) && (rtc.minute >= 35))) {
      setled(60, 63, true);  //four (hours)
    } else {
      setled(60, 63, false);
    }
    if (((rtc.hour == 5) && (rtc.minute < 35)) || ((rtc.hour == 17) && (rtc.minute < 35)) || ((rtc.hour == 16) && (rtc.minute >= 35)) || ((rtc.hour == 4) && (rtc.minute >= 35))) {
      setled(86, 89, true);  // five (hours)
    } else {
      setled(86, 89, false);
    }
    if (((rtc.hour == 6) && (rtc.minute < 35)) || ((rtc.hour == 18) && (rtc.minute < 35)) || ((rtc.hour == 17) && (rtc.minute >= 35)) || ((rtc.hour == 5) && (rtc.minute >= 35))) {
      setled(115, 117, true);  // six (hours)
    } else {
      setled(115, 117, false);
    }
    if (((rtc.hour == 7) && (rtc.minute < 35)) || ((rtc.hour == 19) && (rtc.minute < 35)) || ((rtc.hour == 18) && (rtc.minute >= 35)) || ((rtc.hour == 6) && (rtc.minute >= 35))) {
      setled(71, 75, true);  // seven (hours)
    } else {
      setled(71, 75, false);
    }
    if (((rtc.hour == 8) && (rtc.minute < 35)) || ((rtc.hour == 20) && (rtc.minute < 35)) || ((rtc.hour == 19) && (rtc.minute >= 35)) || ((rtc.hour == 7) && (rtc.minute >= 35))) {
      setled(94, 98, true);  // eight (hours)
    } else {
      setled(94, 98, false);
    }
    if (((rtc.hour == 9) && (rtc.minute < 35)) || ((rtc.hour == 21) && (rtc.minute < 35)) || ((rtc.hour == 20) && (rtc.minute >= 35)) || ((rtc.hour == 8) && (rtc.minute >= 35))) {
      setled(90, 93, true);  // nine (hours)
    } else {
      setled(90, 93, false);
    }
    if (((rtc.hour == 10) && (rtc.minute < 35)) || ((rtc.hour == 22) && (rtc.minute < 35)) || ((rtc.hour == 21) && (rtc.minute >= 35)) || ((rtc.hour == 9) && (rtc.minute >= 35))) {
      setled(118, 120, true);  // ten (hours)
    } else {
      setled(118, 120, false);
    }
    if (((rtc.hour == 11) && (rtc.minute < 35)) || ((rtc.hour == 23) && (rtc.minute < 35)) || ((rtc.hour == 22) && (rtc.minute >= 35)) || ((rtc.hour == 10) && (rtc.minute >= 35))) {
      setled(100, 105, true);  // eleven (hours)
    } else {
      setled(100, 105, false);
    }
    if (((rtc.hour == 12) && (rtc.minute < 35)) || ((rtc.hour == 0) && (rtc.minute < 35)) || ((rtc.hour == 23) && (rtc.minute >= 35)) || ((rtc.hour == 11) && (rtc.minute >= 35))) {
      setled(77, 81, true);  // twelve (hours)
    } else {
      setled(77, 81, false);
    }
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