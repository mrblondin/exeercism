#include "clock.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HOUR_DAY  24
#define MIN_HOUR  60
#define MIN_DAY   24*60

/**
 * Create adjusted clock
 * @param {int} hours
 * @param {int} minute
 * @param {int} adjust_minutes - add or subtract minutes from time
 * returns {clock_t} clock
 */
static clock_t clock_create_adjusted(int hour, int minute, int adjust_minutes) {
  clock_t clock;

  // the time of the day in min
  minute = (hour * MIN_HOUR + minute + adjust_minutes) % (MIN_DAY);

  // check that minute value is greater than 0
  minute = minute >= 0 ? minute : minute + MIN_DAY;

  printf("min: %i\n", minute);

  hour = minute / MIN_HOUR;
  minute = minute % MIN_HOUR;

  sprintf(clock.text,"%02i:%02i", hour, minute);

  return clock;
}

static void get_hour_min_from_clock(clock_t clock, int * hour, int * minute){
  char * pEnd;

  *hour = strtol(clock.text, &pEnd, 10);
  *minute = strtol(++pEnd, NULL, 10);
}

clock_t clock_create(int hour, int minute) {
  return clock_create_adjusted(hour, minute, 0);
}

clock_t clock_add(clock_t clock, int minute_add) {
  int hour, minute;

  get_hour_min_from_clock(clock, &hour, &minute);

  return clock_create_adjusted(hour, minute, minute_add);
}

clock_t clock_subtract(clock_t clock, int minute_subtract) {
  int hour, minute;

  get_hour_min_from_clock(clock, &hour, &minute);

  return clock_create_adjusted(hour, minute, 0 - minute_subtract);
}

bool clock_is_equal(clock_t a, clock_t b) {
  if (strcmp(a.text, b.text) == 0)
    return true;

  return false;
}
