#tm_year: the year

#tm_mon: the month, range [1, 12]

#tm_mday: the day of the month, range [1, 31]

#tm_hour: the hour, range [0, 23]

#tm_min: the minute, range [0, 59]

#tm_sec: the second, range [0, 61]

#tm_wday: the day of the week, range [0, 6], Monday is 0

#tm_yday: the day of the year, range [1, 366], -1 indicates not known

#tm_isdst: 1 when in daylight savings, 0 when not, -1 if unknown.

#(tm_year, tm_mon, tm_mday, tm_hour, tm_min, tm_sec, tm_wday, tm_yday, tm_isdst)


import rtc
import time

class RTC(object):
    @property
    def datetime(self):
        return time.struct_time((2023, 10, 31, 12, 35, 00, 1, 304, 1))
r = RTC()
rtc.set_time_source(r)
while True:
    current_time = time.time()
    print(current_time)
    time.sleep(0.5)
