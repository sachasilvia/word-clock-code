// ORDER: TOP -> BOTTOM & LEFT -> RIGHT (ie. IT == TOP LEFT, and O'CLOCK == BOTOTM RIGHT)

// words for grammar correctness
// 0 -> 1 = IT
// 3 -> 4 = IS
// numbers to tell the *DISTANCE* from the hour
// 15 -> 21 = FIFTEEN
// 24 -> 33 = TWENTYFIVE (twenty and five are combined, 20 on its own is: 24 -> 29 and five on its own is: 30 -> 33)
// 47 -> 42 = THIRTY
// 40 -> 38 = TEN
// more words for grammar correctness
// 71 -> 65 = MINUTES
// 72 -> 75 = PAST
// 75 -> 76 = TO
// actual numbers for the hour
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
// the last word for grammar correctness
// 126 -> 131 = O'CLOCK

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

#include <Adafruit_NeoPixel.h>
#include <time.h>
#include <sys/time.h>

#define PIN 6
#define NUMPIXELS 8
// 130 pins for bypass (one led is out), 131 total (really there are 132, but led 0)

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 1000

void setup() {
  Serial.begin(115200);
  delay(5000);
  struct timeval tv;

  tv.tv_sec = 1699464720; // set to unix time
  tv.tv_usec = 0;
  settimeofday(&tv, nullptr);
  pixels.begin();  // initialize neopixel object
}                     

void loop() {
  pixels.clear();  // all pixels off

  time_t now;
  char buff[80];

  time(&now);
  strftime(buff, sizeof(buff), "%c", localtime(&now));
  Serial.println(buff);

  for (int g = 0; g < 256; g++) { //change the value of a color scaling from 0-255
    for (int i = 0; i < NUMPIXELS; i++) {  // for(each pixel)
      // this code sends a single led up the neopixel matrix and resets the loop once it reaches the top:

      pixels.setPixelColor(i, pixels.Color(255, g, 0));  //(r,g,b), 0-255
      //pixels.setPixelColor(i, pixels.Color(random(256), random(256), random(256))); //for each pixel to be a random color
      //pixels.setPixelColor(i-1,pixels.Color(0 ,0 ,0)); // turns the led that is on i-1 to off (in other words turns off the led behind the newest led to be illuminated)

      pixels.show();    // sets color values
      //delay(DELAYVAL);  //delay before the loop runs again
    }
  }
}
