// helpers
// 0 -> 1 = IT
// 3 -> 4 = IS
// 126 -> 131 = O'CLOCK
// 48 -> 54 = MINUTES
// 68 -> 71 = PAST
// 67 -> 68 = TO

// minutes
// 15 -> 21 = FIFTEEN
// 24 -> 33 = TWENTY FIVE (twenty and five are combined, 20 on its own is: 24 -> 29 and five on its own is: 30 -> 33)
// 47 -> 42 = THIRTY
// 40 -> 38 = TEN

// hours
// 64 -> 61 = FOUR
// 72 -> 76 = SEVEN
// 77 -> 83 = TWELVE
// 92 -> 95 = NINE
// 88 -> 91 = FIVE
// 84 -> 86 = TWO
// 96 -> 100 = EIGHT
// 102 -> 107 = ELEVEN
// 117 -> 119 = SIX
// 112 -> 116 = THREE
// 109 -> 111 = ONE
// 120 -> 122 = TEN

//                      :LED MATRIX:
//                    11x12 - 132 pixels
// -> 000 001 002 003 004 005 006 007 008 009 010 011
//    023 022 021 020 019 018 017 016 015 014 013 012 <-
// -> 024 025 026 027 028 029 030 031 032 033 034 035
//    047 046 045 044 043 042 041 040 039 038 037 036 <-
// -> 048 049 050 051 052 053 054 055 056 057 058 059
//    071 070 069 068 067 066 065 064 063 062 061 060 <-
// -> 072 073 074 075 076 077 078 079 080 081 082 083
//    095 094 093 092 091 090 089 088 087 086 085 084 <-
// -> 096 097 098 099 100 101 102 103 104 105 106 107
//    119 118 117 116 115 114 113 112 111 110 109 108 <-
// -> 120 121 122 123 124 125 126 127 128 129 130 131


//                    :WORD MATRIX:
//               I T L I S A S T H P M A
//               A C F I F T E E N D C O
//               T W E N T Y F I V E X W
//               T H I R T Y F T E N O S
//               M I N U T E S E T O U R
//               P A S T O R U F O U R T
//               S E V E N X T W E L V E
//               N I N E F I V E C T W O
//               E I G H T F E L E V E N
//               S I X T H R E E O N E G
//               T E N S E Z O'C L O C K

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
  rtc.adjust(1, 55, 10, 2023, 12, 4);
  pixels.begin();
  pixels.clear();
  rtc.read();
  PrintTime();
  lastTime = millis();
  setled(0, 0, true);  //it
  setled(2, 3, true);  //is
  if (rtc.minute >= 5) {
    setled(67, 67, true);  //t for past and to
  } else {
    setled(67, 67, false);
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
    } else {
      setled(67, 67, false);
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
