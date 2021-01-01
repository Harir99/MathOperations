#include <stdlib.h>
#include "MathOperations.h"

long int gcd(long int num1, long int num2, int* success) {

	/*This function will return the greatest common divisor between the values of num1 and num2*/

	/*if even one number is zero*/
	if (num1 == 0 || num2 == 0) {

		*success = 0;
		return 0;
	}

	if (success == NULL) {

		return 0;
	}
	else {

		*success = '\0';
	}
	/*if any number is -ve then make it positive*/
	if (num1 < 0) {

		num1 *= -1;
	}

	if (num2 < 0) {

		num2 *= -1;
	}
	/*num1 i to always bigger than num2 else interchange*/
	if (num2 > num1) {

		long int temp = num2;

		num2 = num1;

		num1 = temp;
	}

	long int remainder = '\0';
	long int lastRemainder = '\0';

	do {

		lastRemainder = remainder;

		remainder = (num1 % ((num1 / num2) * num2));

		num1 = num2;
		num2 = remainder;

	} while (remainder != 0);

	*success = 1;

	if (lastRemainder == 0) {

		return num1;
	}
	else {

		return lastRemainder;
	}
}
