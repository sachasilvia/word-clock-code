
# ORDER: TOP -> BOTTOM & LEFT -> RIGHT (ie. IT == TOP LEFT, and O'CLOCK == BOTOTM RIGHT)

# GENERAL
# 0 -> 1 = IT
# 3 -> 4 = IS
# *ALL BELOW phrase pertain to, "dist. -> time", =! time num. *
# 15 -> 21 = FIFTEEN
# 24 -> 33 = TWENTYFIVE
# 47 -> 42 = THIRTY
# 40 -> 38 = TEN
# 71 -> 65 = MINUTES
# 72 -> 75 = PAST
# 75 -> 76 = TO
# ALL BELOW phrase pertain to, "time num."
# 64 -> 61 = FOUR
# 72 -> 76 = SEVEN
# 77 -> 83 = TWELVE
# 92 -> 95 = NINE
# 88 -> 91 = FIVE
# 84 -> 86 = TWO
# 96 -> 100 = EIGHT
# 102 -> 107 = ELEVEN
# 117 -> 119 = SIX
# 112 -> 116 = THREE
# 109 -> 111 = ONE
# 120 -> 122 = TEN
# GENERAL
# 126 -> 131 = O'CLOCK

#                      :LED MATRIX:
#                    11x12 - 132 pixels
# -> 000 001 002 003 004 005 006 007 008 009 010 011
#    023 022 021 020 019 018 017 016 015 014 013 012 <-
# -> 024 025 026 027 028 029 030 031 032 033 034 035
#    047 046 045 044 043 042 041 040 039 038 037 036 <-
# -> 048 049 050 051 052 053 054 055 056 057 058 059
#    071 070 069 068 067 066 065 064 063 062 061 060 <-
# -> 072 073 074 075 076 077 078 079 080 081 082 083
#    095 094 093 092 091 090 089 088 087 086 085 084 <-
# -> 096 097 098 099 100 101 102 103 104 105 106 107
#    119 118 117 116 115 114 113 112 111 110 109 108 <-
# -> 120 121 122 123 124 125 126 127 128 129 130 131


#                     :WORD MATRIX:
#                I T L I S A S T H P M A
#                A C F I F T E E N D C O
#                T W E N T Y F I V E X W
#                T H I R T Y F T E N O S
#                M I N U T E S E T O U R
#                P A S T O R U F O U R T
#                S E V E N X T W E L V E
#                N I N E F I V E C T W O
#                E I G H T F E L E V E N
#                S I X T H R E E O N E G
#                T E N S E Z O'C L O C K

import time
import board
import neopixel
from rainbowio import colorwheel

num_pixels = 8

pixels = neopixel.NeoPixel(board.GP0, num_pixels, auto_write=False)
pixels.brightness = 0.5


def rainbow(speed):
    for j in range(255):
        for i in range(num_pixels):
            pixel_index = (i * 256 // num_pixels) + j
            pixels[i] = colorwheel(pixel_index & 255)
        pixels.show()
        time.sleep(speed)


while True:
    rainbow(0)
#
