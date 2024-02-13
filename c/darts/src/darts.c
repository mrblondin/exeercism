#include "darts.h"
#include "math.h"
#include "stdio.h"

unsigned int score(coordinate_t coord){
	double hyp = sqrt(pow(coord.x, 2) + pow(coord.y, 2));
	int result = 0;
	if(hyp <= MIN_RAD)
		result = MAX_POINTS;
	else if (hyp <= MID_RAD)
		result = MID_POINTS;
	else if (hyp <= MAX_RAD)
		result = MIN_POINTS;
	return result;
}
