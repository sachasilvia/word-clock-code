// words for grammar correctness
// 0 -> 1 = IT
// 3 -> 4 = IS
// numbers to tell the *DISTANCE* from the hour
// 15 -> 21 = FIFTEEN
// 24 -> 33 = TWENTYFIVE (twenty and five are combined, 20 on its own is: 24 -> 29 and five on its own is: 30 -> 33)
// 47 -> 42 = THIRTY
// 40 -> 38 = TEN
// more words for grammar correctness
// 48 -> 54 = MINUTES
// 68 -> 71 = PAST
// 67 -> 68 = TO
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


//includes
#include <PicoEspTime.h>
#include <Adafruit_NeoPixel.h>

//defines
#define PIN 6
#define NUMPIXELS 129  // 129 pins for bypass (two leds out), 131 total (really there are 132, but led 0)
#define DELAYVAL 1000

//functions
PicoEspTime rtc;

uint32_t lastTime;

// array used for hours
uint8_t hours[24][2]{

  // for testing if less than 81, -1 , if more than 81, -2
  { 77, 81 },    // twelve am (0)
  { 107, 109 },  // one am (1)
  { 82, 84 },    // two am (2)
  { 110, 114 },  // three am (3)
  { 60, 63 },    // four am (4)
  { 86, 89 },    // five am (5)
  { 115, 117 },  // six am (6)
  { 71, 75 },    // seven am (7)
  { 94, 98 },    // eight am (8)
  { 90, 93 },    // nine am (9)
  { 118, 120 },  // ten am (10)
  { 100, 105 },  // elven am (11)
  { 77, 81 },    // twelve pm (12)
  { 107, 109 },  // one pm (13)
  { 82, 84 },    // two pm (14)
  { 110, 114 },  // three pm (15)
  { 60, 63 },    // four pm (16)
  { 86, 89 },    // five pm (17)
  { 115, 117 },  // six pm (18)
  { 71, 75 },    // seven pm (19)
  { 94, 98 },    // eight pm (20)
  { 90, 93 },    // nine pm (21)
  { 118, 120 },  // ten pm (22)
  { 100, 105 },  // eleven pm (23)
};

// array used for minutes
uint8_t minutes[6][2]{
  // for testing if less than 81, -1 , if more than 81, -2
  { 29, 32 },  // 5 past
  { 37, 49 },  // 10 past
  { 14, 20 },  // 15 past
  { 23, 28 },  // 20 past
  { 23, 32 },  // 25 past
  { 41, 46 },  // 30 to
};

//ints
int hour
int lasthour;


Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void PrintTime(void);

void setup() {
  Serial.begin(115200);
  rtc.adjust(11, 59, 1, 2023, 11, 16);  // EXAMPLE: 01:26:21 03 Jun 2022 (SETS THE TIME WITH DATE VALUES)
                                        // rtc.adjust(1654219721); // Friday, June 03 2022 01:28:41 (SETS THE TIME WITH UNIX EPOCH TIME)
  pixels.begin();                       // initialize neopixel object
  pixels.clear();                       // sets all pixels off to begin with
 
  //grabs the time at the beginning of the setup 
  rtc.read();

  hour = rtc.hour;

  //the entire loop needs to be placed in the setup due to the millis "if loop" so it can run one time before the minute delay
  
  for (int past = 67; past < 71; past++) {
    if (rtc.minute <= 29) {
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
  for (int it = 0; it < 1; it++) {
    pixels.setPixelColor(it, pixels.Color(255, 0, 0));
  }
  for (int is = 2; is < 4; is++) {
    pixels.setPixelColor(is, pixels.Color(255, 0, 0));
  }
  for (int mins = 46; mins < 53; mins++){
      pixels.setPixelColor(mins, pixels.Color(255, 0, 0);
    }
  if (hour <= 0) {
      for (int hrbypass = 100; hrbypass < 106; hrbypass++) {
        pixels.setPixelColor(hrbypass, pixels.Color(0, 0, 0));  // turns off 11 if the hour is 12am but stored as 0 in 24 hour time
      }
  for (int i = hours[hour][0]; i <= hours[hour][1]; i++) {
    pixels.setPixelColor(i, pixels.Color(255, 0, 0));
  }
  for (int oclock = 124; oclock < 130; oclock++) {
      pixels.setPixelColor(oclock, pixels.Color(255, 0, 0));
    }
  pixels.show();  
}

void loop() {
//delay in seconds for how frequent it checks, if over 10k use L for long int (ENTIRE LOOP GOES IN THIS IF LOOP)
  if (millis() - lastTime >= 60000L) {
    
    // grab time
    rtc.read();
    PrintTime();
    lastTime = millis();

  // for setting hours
    hour = rtc.hour;
    lasthour = rtc.hour - 1;

  // sets the leds for "past"
  for (int past = 67; past < 71; past++) {
    if (rtc.minute <= 29) {
      pixels.setPixelColor(past, pixels.Color(255, 0, 0));
    } else {
      pixels.setPixelColor(past, pixels.Color(0, 0, 0));
    }
  }

  // sets the leds for "to"
  for (int to = 66; to < 68; to++) {
    if (rtc.minute >= 30) {
      pixels.setPixelColor(to, pixels.Color(255, 0, 0));
    } else {
      pixels.setPixelColor(66, pixels.Color(0, 0, 0));
    }
  }

  // sets the leds for "it"
  for (int it = 0; it < 1; it++) {
    pixels.setPixelColor(it, pixels.Color(255, 0, 0));
  }

  // sets the leds for "is"
  for (int is = 2; is < 4; is++) {
    pixels.setPixelColor(is, pixels.Color(255, 0, 0));
  }

  // sets the leds for "minutes"
  for (int mins = 46; mins < 53; mins++){
      pixels.setPixelColor(mins, pixels.Color(255, 0, 0);
    }

  // 24 hour time bypass, since 0-1 breaks the array, set "eleven" to off
  if (hour <= 0) {
      for (int hrbypass = 100; hrbypass < 106; hrbypass++) {
        pixels.setPixelColor(hrbypass, pixels.Color(0, 0, 0));  // turns off 11 if the hour is 12am but stored as 0 in 24 hour time
      }
    
  // only need in loop, removes leds for "last hour" (rtc.hour - 1)
    for (int i = hours[lasthour][0]; i <= hours[lasthour][1]; i++) {
      pixels.setPixelColor(i, pixels.Color(0, 0, 0));
    }
    
  // sets the leds for value of "rtc.hour" using a 2d array
  // *in 2d array 12=0, 1=1, 2=2, 3=3, and so on, this ONLY WORKS because the numbers match so rtc.hour can be used to call to the array*
  for (int i = hours[hour][0]; i <= hours[hour][1]; i++) {

    pixels.setPixelColor(i, pixels.Color(255, 0, 0));
  }

  // sets the leds for "o'clock"
  for (int oclock = 124; oclock < 130; oclock++) {
      pixels.setPixelColor(oclock, pixels.Color(255, 0, 0));
    }

  // turns on all of the leds for above true statements
  pixels.show();
    
  }
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
