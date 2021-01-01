/* Abdul Mahmoud(1093276) , Bahaa Zuraik(1096463), Austin Varghese (1098759)
 * Oct 23, 2020
 * FourFunctionCalculator
 * Passes 2 floats and performs the requested operation
 */

#include <stdlib.h>
#include <ctype.h>
#include "MathOperations.h"

float fourFunctionCalc(float num1, float num2,char tempString[]){
	char operation = tempString[0];
	int result;

	/*error checking the operation to ensure it is on of the
	four functions will done in the main function*/
	if(operation == '+'){
		result = num1 + num2;
	}else if(operation == '-'){
		result = num1 - num2;
	}else if(operation == '*'){
		result = num1 * num2;
	}else{
		result = num1 / num2;
	}


	return result;
}
