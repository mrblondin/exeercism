#ifndef DARTS_H
#define DARTS_H

typedef struct {
	float x;
	float y;
} coordinate_t;

unsigned int score(coordinate_t coord);

#define MIN_RAD 1
#define MID_RAD 5
#define MAX_RAD 10
#define OUT_POINTS 0
#define MIN_POINTS 1
#define MID_POINTS 5
#define MAX_POINTS 10

#endif
