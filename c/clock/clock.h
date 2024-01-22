#ifndef CLOCK_H
#define CLOCK_H

#include <stdbool.h>

#define MAX_STR_LEN sizeof("##:##")

typedef struct {
   char text[MAX_STR_LEN];
} clock_t;

/**
 * Create new clock
 * @param {int} hour
 * @param {int} minute
 * reeturns {clock_t} clock
 */
clock_t clock_create(int hour, int minute);


/**
 * Add minutes to clock
 * @param {clock_t} clock
 * @param {int} minutes to add
 * reeturns {clock_t} clock
 */
clock_t clock_add(clock_t clock, int minute_add);


/**
 * Subtrack minutes from clock
 * @param {clock_t} clock
 * @param {int} minutes to subtract
 * reeturns {clock_t} clock
 */
clock_t clock_subtract(clock_t clock, int minute_subtract);

/**
 * Check if 2 clocks are the same
 * @param {clock_t} clock 1
 * @param {clock_t} clock 2
 * returns {bool} true/false
 */
bool clock_is_equal(clock_t a, clock_t b);

#endif
