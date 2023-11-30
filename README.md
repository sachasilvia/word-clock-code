#Hello, this is the repository for my Word Clock project, here is where I will explain what each file in the repository does.

Make sure to download this library for the code to work --> https://github.com/3tawi/PicoEspTime //LIBRARY DOWNLOAD HERE!!!

To_and_Past_final.ino - This is the final version of the code that sets the leds for "to" and "from" accounting for the switch at 30 minutes and for the first 5 minutes of each hour where they won't be on (the led values may need to be changed based on the # of neopixels used)

actualclock.ino - This is the raw code to get the internal rtc in the rp2040 to run, it prints time and stores all time values as objects under "rtc."xxxx"", can be set with  srtftime or unix epoch

clockplusnpxl.ino - This is the main test document that I make all edits for the project in, essentially a place-holder for the final version of the code while the file doesn't exist, the MOST changes will be found here
