#include <stdlib.h>
#include <string.h>
#include "MathOperations.h"

  /*This function returns if the factorizaion of a prime number succesed*/
char * primeFactorization(long int num, int * success) {
	if (success == NULL) {
		return NULL;
	} else {
		* success = '\0';
	}
	// error check
	if (num <= 1) {
		* success = -1;
		return NULL;
	}
  /* Initial memory allocation */
	char * list = (char*)malloc(sizeof(char));
	list[0] = '\0';

	if (isPrime(num) == 1) {
		* success = 1;
		list = addToList(list, num, 1);
		return list;
	}

	long int base = 2;
	long int power = 0;
	//check if num is prime
	while (num != 1) {
		while (num % base == 0) {
			num /= base;
			power++;
		}
		
		if (power != 0) {
			list = addToList(list, base, power);
			//if its a prime number then add to list
			if (num != 1 && isPrime(num) == 1) {
				list = addToList(list, num, 1);
				break;
			}
			power = 0;
		}
		// get next number
		base = getNextPrime(base);
	}
	* success = 1;
	return list;
}

char * toString(long int num) {
	int len = 1;
	long int newNum = num;

	while (newNum / 10 != 0) {
		newNum /= 10;
		len++;
	}

  /* Initial memory allocation */
	char * ret = (char*)malloc(sizeof(char) * len + 1);
	ret[len] = '\0';

	int i;
	for (i = len - 1; i >= 0; i--) {
		ret[i] = ((num % 10) + '0');
		num /= 10;
	}
	return ret;
}

  /*This function adds element to a list*/
char * addToList(char * list, long int base, long int power) {
	int currentLen = strlen(list);
	char * baseStr = toString(base);
	char * powerStr = toString(power);
	int newLen = currentLen + strlen(baseStr) + strlen(powerStr);
	char * newList;

	if (currentLen == 0) {
    /* Reallocating memory */
		newList = (char * )realloc(list, sizeof(char) * newLen + 2);
		strcat(newList,baseStr);
		strcat(newList, "^");
		strcat(newList, powerStr);
	} else {
    /* Reallocating memory */
		newList = (char * )realloc(list, sizeof(char) * newLen + 5);
		strcat(newList, "*");
		strcat(newList, baseStr);
		strcat(newList, "^");
		strcat(newList, powerStr);
	}
	free(baseStr);
	free(powerStr);
	baseStr = NULL;
	powerStr = NULL;
	return newList;
}
