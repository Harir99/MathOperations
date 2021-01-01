#include <stdlib.h>
#include <math.h>
#include "MathOperations.h"

int isPrime(long int num) {
	/*if number is less then 1 then return zero*/
	if (num <= 1) {
		return 0;
	}
	/*if number is 2 or 3*/
	else if (num <= 3) {
		return 1;
	}
	/*even number*/
	if (num % 2 == 0) {
		return 0;
	}

	int i;
	for (i = 3; i <= sqrt(num); i += 2) {
		/*if the number is divisble by any other number then itself return 0 i.e. composite*/
		if (num % i == 0) {
			return 0;
		}
	}
	return 1;
}

long int getNextPrime(long int num) {
	if (num < 2){
		/*if the number is less than 2*/
		return 2;
	}
	/*if the number is composite increse by one else by two*/
	if (num % 2 == 0){
		num += 1;
	}
	else {
		num += 2;
	}
	/*find the next prime*/
	while (isPrime(num == 0)) {
		num += 2;
	}
	return num;
}
