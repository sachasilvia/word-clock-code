#include <time.h>
#include <sys/time.h>

void setup() {
  Serial.begin(115200);
  delay(5000);
  struct timeval tv;

  tv.tv_sec = 1698947780;
  tv.tv_usec = 0;
  settimeofday(&tv, nullptr);
}

void loop() {
  time_t now;
  char buff[80];

  time(&now);
  strftime(buff, sizeof(buff), "%c", localtime(&now));
  Serial.println(buff);
  delay(1000);
}
