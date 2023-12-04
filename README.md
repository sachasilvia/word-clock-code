# Hello, welcome to the repository for my Word Clock project, this ReadMe is where I will explain what each file in the repository does.

Make sure to download this library for the code to work --> https://github.com/3tawi/PicoEspTime

actualclock.ino - This is the code to get the internal rtc in the rp2040 to run on its own, it prints time in the serial monitor and stores all time values as objects under "rtc."xxxx"", can be set with  srtf time or unix epoch

testdoc.ino - This is the main test document that I make all edits for the project in, essentially a place-holder for the final version of the code while the file doesn't exist, the MOST changes will be found here

non_numbers.ino - the final version of the code for powering ALL non-number words (it, is, minutes, to, past, o'clock) 

minutes.ino - This is the final version of the code for running just minutes based on telling time in five-minute intervals with the highest value being 30 minutes

everything_but_hours.ino - Everything working but hours, combined minutes.ino and non_numbers.ino

top_comments - To maintain a document with important comments

hours.ino - This is the final version of the code for running just hours based on the hour switching at the thirty minute mark
