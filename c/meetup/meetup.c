#include "meetup.h"
#include <assert.h>
#include <string.h>

// algorithm of day of the week determination
// https://en.wikipedia.org/wiki/Determination_of_the_day_of_the_week#Implementation-dependent_methods

#define DESCIPTOR_LAST 5
#define DAYS_PER_WEEK 7
#define LEAP_YEAR_DAY 29

typedef struct {
  char week[6];
  int day_max;
} descriptor_t;

static const descriptor_t descriptor[] = {
  { "first",  7},
  { "second", 14},
  { "third",  21},
  { "teenth", 19},
  { "fourth", 28},
  { "last",   0},
};

static const char *DAYS_OF_WEEK[] = { "Monday", "Tuesday", "Wednesday", "Thursday", 
                                      "Friday", "Saturday", "Sunday" };

static const int DAYS_IN_MONTH[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 
                                     30, 31};

static int is_leap_year(int year){
  return !(year % 4) && (year % 100 || !(year % 400));
}

static int weekday(unsigned int year, unsigned int month, unsigned int day){
  return  (day += month < 3 ? year-- : year - 2, 23 * month/9 +
            day + 4 + year/4- year/100 + year/400) % 7;
} 

int meetup_day_of_month(unsigned int year, unsigned int month, const char *week,
                        const char *day_of_week){
  assert(year && month && week && day_of_week);

  int date_day_max;
  int day_of_week_int;
  int date_result;

  // find the range of dates using desciptor
  for (int i = 0; i <= DESCIPTOR_LAST; i++){
    if (!strcmp(descriptor[i].week, week)) {

      // last day should be treated specifically
      if (i == DESCIPTOR_LAST)
        date_day_max = month == 2 && is_leap_year(year) ?
          LEAP_YEAR_DAY : DAYS_IN_MONTH[month - 1];
      // ordinary day
      else
        date_day_max = descriptor[i].day_max; 

      break;
    }
  }

  // find day of week
  for (int i = 1; i <= DAYS_PER_WEEK; i++) {
    if (!strcmp(DAYS_OF_WEEK[i - 1], day_of_week))
      day_of_week_int = i;
  }

  date_result = date_day_max - 
    (weekday(year, month, date_day_max) - day_of_week_int);

  // adjust date if it is out of range
  date_result = date_result > date_day_max ? date_result - DAYS_PER_WEEK 
                                           : date_result;

  return date_result;
}
