#include "armstrong_numbers.h"
#include <math.h>

int is_armstrong_number(long number){
	long i = number;
	int k = 0, m = 0; // number of digits
	long sum = 0;

	//Defining the number of digits
	while(i){
		k++;
		i/=10;
	}

	m=k;
	i = number;

	while(k > 0){
		long round = pow(10, k - 1);
		int num = i / round;
		sum += pow(num, m);
		i = i - num*round;
		k--;
	}

	return sum == number ? 1 : 0;
}
