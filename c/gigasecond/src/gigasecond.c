#include "gigasecond.h"
#include "math.h"

time_t gigasecond_after(time_t curTime) {
    return curTime + pow(10, 9);
}
