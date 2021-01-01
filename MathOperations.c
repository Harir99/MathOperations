/*
 * FindArea and matrix by Shayan Mohammed(1097825) and Harir Al Rubaye (1108085)
 * Median, mode ,Mean and FourFunctionCalc by Abdul Mahmoud(1093276) , Bahaa Zuraik(1096463), Austin Varghese (1098759)
 * MathOperations.c (Main file) by Harikrishan Singh (1118437)
 * Fixing the command loop by Harikrishan Singh(1118437) and Moses Oyeleye(1057075)
 */


#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <limits.h>
#include <ctype.h>
#include <string.h>
#include "MathOperations.h"

int main(int argc, char *argv[]) {
	//long int i = '\0';
	long int choice = '\0';
	long int num2 = '\0';
	int baseFrom = '\0';
	int baseTo = '\0';
	char *alphaNum = NULL;

	int boolResult = '\0';
	long int longResult = '\0';
	unsigned long int unsignedLResult = '\0';
	char *strResult = NULL;

	int *success = (int*)malloc(sizeof(int));
	*success = '\0';

	int lastDigit = '\0';
	char *ordinalIndicator = NULL;

	int choiceA = 0;
	int numElements= 0 ;
	int list[1000] ;
	float listF[1000];
	int error=0, rows=0, cols=0;
	float f1 = 0,f2 = 0;
	char oP[100];
	int valid = 0;

	while (1) {
		do {
			/*Menu*/
			printf("*** FUN WITH MATH OPERATIONS ***\n");
			printf("Select one of the following options to continue (1 - 6):\n"
					"1.) Primality Test\n"
					"2.) Prime Factorization\n"
					"3.) Nth Term in Fibonacci Sequence\n"
					"4.) Convert a Number from any Base to any Base\n"
					"5.) Greatest Common Divisor\n"
					"6.) Find Area\n"
					"7.) Mode\n"
					"8.) Mean\n"
					"9.) Median\n"
					"10.) Matrix\n"
					"11.) FourFunctionCalculator\n"
					"12.) Exit\n"
					"Your Selection: ");
			/*error checking the user input is valid*/
			choice = retrieveNumericInput(success);
			if (*success != 1 || choice > 12 || choice < 1) {
				printf("\nError parsing response, please try again.)))))))))))\n");
				printf("%ls\n",success);
			}
		} while (*success != 1 || choice > 12 || choice < 1);

		/*swtiching using variable 'choice'*/
		switch (choice) {
			case 1:

				do {
					/*asking user for input*/
					printf("\n~~~~~~~~~~~~~~~~~~~~\n\n"
							"Primality Test:\n"
							"Enter a Number to Test the Primality Of: ");

					choice = retrieveNumericInput(success);
					/*error checking value from input*/
					if (*success != 1) {
						printf("\nError parsing response, please try again.");
					}
				/*Checking if inputted number is prime*/
				} while (*success != 1);

				if ((boolResult = isPrime(choice)) == 0) {
					printf("The Number IS NOT Prime.\n");
				} else if (boolResult == 1) {
					printf("The Number IS Prime.\n");
				}

				/*reseting values so they can be tested again*/
				*success = '\0';
				boolResult = '\0';
				choice = '\0';
				break;

			case 2:
				do {
					/*asking user for input*/
					printf("\n~~~~~~~~~~~~~~~~~~~~\n\n"
							"Prime Factorization:\n"
							"Enter a Number to take the Prime Factorization Of: ");
					/*error checking value from input*/
					choice = retrieveNumericInput(success);
					if (*success != 1) {
						printf("\nError parsing response, please try again.\n");
					} else {

						strResult = primeFactorization(choice, success);
						if (strResult == NULL && *success == -1) {
							printf("\nError: Please Enter a Number Greater Than 1.\n");
						}
					}
				/*doing prime factorization*/
				} while (*success != 1);

				printf("The Prime Factorization of %ld is:\n"
						"%s\n", choice, strResult);

				/*freeing memory*/
				free(strResult);
				strResult = NULL;

				/*reseting values for continued use*/
				*success ='\0';
				choice = '\0';
				break;

			case 3:
				do {
					/*asking user for input*/
					printf("\n~~~~~~~~~~~~~~~~~~~~\n\n"
							"Nth Term in Fibonacci Sequence:\n"
							"Enter the Term of the Fibonacci Sequence You Want: ");

					choice = retrieveNumericInput(success);
					/*error checking value from input*/
					if (*success != 1) {
						printf("\nError parsing response, please try again.\n");
					} else {

						unsignedLResult = nthFibonacciTerm(choice, success);
						if (*success == -1) {
							printf("\nError: Please Enter a Non-Negative Number.\n");
						} else if (*success == 0 && unsignedLResult == ULONG_MAX) {
							printf("\nError: Number Too Big. Please Enter a Smaller Term.\n");
						}
					}
				} while (*success != 1);

				/*checking suffix for number*/
				lastDigit = choice % 10;
				if (lastDigit == 1) {
					ordinalIndicator = "st";
				} else if (lastDigit == 2) {
					ordinalIndicator = "nd";
				} else if (lastDigit == 3) {
					ordinalIndicator = "rd";
				} else {
					ordinalIndicator = "th";
				}

				/*printing sequence values*/
				printf("The %ld%s Term of the Fibonacci Sequence is:\n"
						"%lu\n", choice, ordinalIndicator, unsignedLResult);

				/*reseting values for continued use*/
				*success = '\0';
				choice = '\0';
				unsignedLResult = '\0';
				lastDigit = '\0';
				ordinalIndicator = NULL;
				break;

			case 4:
				do {
					/*asking user for input*/
					printf("\n~~~~~~~~~~~~~~~~~~~~\n\n"
							"Convert a Number From Any Base to Any Base:\n"
							"Enter the Base to Convert From: ");

					baseFrom = retrieveNumericInput(success);
					/*error checking value from input*/
					if (*success != 1) {
						printf("\nError parsing input. Please try again.\n");
						continue;
					} else if (baseFrom < 2 || baseFrom > 36) {
						printf("\nError: Please Enter a Base Between 2 and 36 (Inclusive)\n");
						*success = 0;
						continue;
					}
					/*asking user for input*/
					do{
									printf("Now Enter the Number to Convert: ");
									alphaNum = retrieveAlphanumericInput(success, baseFrom);
									/*error checking value from input*/
									if (*success != 1) {
										printf("\nError parsing input. Please try again.\n");

									}
					}while (*success != 1);

					do{
								printf("Now Enter the Base to Convert To: ");
								baseTo = retrieveNumericInput(success);
								/*error checking value from input*/
								if (*success != 1) {
									printf("\nError parsing input. Please try again.\n");

								} else if (baseTo < 2 || baseTo > 36) {
									printf("\nError: Please Enter a Base Between 2 and 36 (Inclusive)\n");
										*success = 0;

										}
					}while (*success != 1);

					/*error checking value from input*/
					strResult = baseConversion(baseFrom, baseTo, alphaNum, success);
					if (*success != 1) {
						printf("\nError Converting Number. Please try again.\n");
						continue;
					}
				} while (*success != 1);
				/*printing answers*/
				printf("The Base %d Number %s in Base %d is:\n"
						"%s\n", baseFrom, alphaNum, baseTo, strResult);

				/*reseting values and freeing memory for continued use*/
				*success = '\0';
				baseFrom = '\0';
				free(alphaNum);
				alphaNum = NULL;
				baseTo = '\0';
				free(strResult);
				strResult = NULL;
				break;

			case 5:
				do {
					/*asking for user input*/
					printf("\n~~~~~~~~~~~~~~~~~~~~\n\n"
							"Greatest Common Divisor:\n"
							"Enter Number 1: ");

					choice =  retrieveNumericInput(success);
					/*error checking value from input*/
					if (*success != 1) {
						printf("\nError parsing input. Please try again.\n");
						continue;
					}
					/*error checking value from input*/
					if (choice == 0) {
						printf("\nError: Please Enter a Non-Zero Number.\n");
						continue;
					}

					do{
							printf("Now Enter Number 2: ");
							num2 = retrieveNumericInput(success);
							/*error checking value from input*/
							if (*success != 1) {
								printf("\nError parsing input. Please try again.\n");
								continue;
							}
							/*error checking value from input*/
							if (choice == 0) {
								printf("\nError: Please Enter a Non-Zero Number.\n");
								continue;
							}
				}while (*success!=1);

					longResult = gcd(choice, num2, success);
					/*error checking value from input*/
					if (*success != 1) {
						printf("\nError getting result. Please try again.\n");
						continue;
					}

				} while (*success != 1);
				/*printing results*/
				printf("The Greatest Common Divisor of %ld and %ld is\n"
						"%ld\n", choice, num2, longResult);

				/*reseting values for continued use*/
				*success = '\0';
				choice =  '\0';
				num2 = '\0';
				break;

			case 6:
				/*find area*/

				do{
						printf("select the shape you would like \n");
						printf("1. CIRCLE:\n");
						printf("2. SQUARE/RECTANGLE:\n");
						printf("3. TRIANGLE:\n");

						choiceA = retrieveNumericInput(success);
					}while (*success!=1);

						FindArea (choiceA,success);
						choice = retrieveNumericInput(success);

						*success = '\0';

				break;

			case 7:
			/*mode*/
					do{
					printf("Please enter the number of elements you want to enter:\n");
					numElements = retrieveNumericInput(success);
					}while (*success!=1);

					for (int i = 0;i<numElements;i++){
						printf("Please enter the element:");
						list[i] = retrieveNumericInput(success);
					}

			    int modeValue;

			    modeValue = mode(list, numElements);
			    printf("The mode Value is: %d\n", modeValue);

					*success = '\0';


					break;

			case 8:
					do{
					printf("Please enter the number of elements you want to enter:\n");
					numElements = retrieveNumericInput(success);
					}while (*success!=1);

					for (int i = 0;i<numElements;i++){
						printf("Please enter the element:");
						listF[i] = retrieveNumericInput(success);
					}

					int meanValue;

					meanValue = Mean(listF, numElements);
					printf("The mean Value is: %d\n", meanValue);

					break;

			case 9:
					do{
						printf("Please enter the number of elements you want to enter:\n");
						numElements = retrieveNumericInput(success);
					}while (*success!=1);

					for (int i = 0;i<numElements;i++){
						printf("Please enter the element:");
						list[i] = retrieveNumericInput(success);
					}
					int medianValue;

					medianValue = median(list, numElements);
					printf("The median Value is: %d\n", medianValue);
					break;

			case 10:
						do{
							error = 0;
								printf("Do you wish to: \n (1) add matrices\n (2) difference of matrices \n");
								printf("Enter choice: ");
								choice = retrieveNumericInput(success);

								if(choice != 1 && choice != 2) error = 1;
								if(error == 1) {
									printf("\ninvalid entry!! Enter choice: ");
								}
							}while(error == 1);

							//  set up number of rows and cols
							printf("Enter number of rows of matrix (between 1 - 100): \n");
							rows = retrieveNumericInput(success);

							printf("Enter number of columns of matrix(between 1 - 100): \n");
							cols = retrieveNumericInput(success);

							calculateMatrix(choice,rows,cols);
					break;

			case 11:
					valid = 0;
					do{
					printf("Please enter the first number you would like to operate on:\n");
					f1 = (float)retrieveNumericInput(success);
					}while (*success!=1);

					do{
					printf("Please enter the second number you would like to operate on:\n");
					f2 = (float)retrieveNumericInput(success);
					}while (*success!=1);

					do{
						printf("Please enter the operation ('+','-','/','*'):\n");
					 	fgets(oP,100,stdin);
						int length = strlen(oP);
						int j = length - 1;
						if (oP[j] == '\n'){
							oP[j] = '\0';
						}

					 if (((oP[0] == '*' )|| (oP[0] == '+') ||( oP[0] == '-')||(oP[0] == '/')) && (strlen(oP) == 1)){
						 valid  = 1;
					 }
				 }while (!valid);

				 printf("%f %s %f = %f\n",f1,oP,f2,fourFunctionCalc(f1,f2,oP));
				 *success = '\0';
				 choice = '\0';

			 break;

			case 12:
				/*freeing memory before exiting*/
				free(success);
				success = NULL;
				return 0;
				break;

			default:
				/*freeing memory before exiting*/
				free(success);
				success = NULL;
				return 1;


		}

		printf("\n~~~~~~~~~~~~~~~~~~~~\n\n");
	}
}

// converting part of string to a long integer value accoridng to a given base
long int retrieveNumericInput(int * success) {
	// pointer to string that needs to be converted to long int
    char * input = NULL;
	// endicates when conversion stops
    char * endptr = NULL;
    retrieveInput( & input, success, 10);
    if (input == NULL || * success != 1) {
        * success = 0;
        return '\0';
    }

	// to distinguish success/failure after calling
    errno = 0;
	long int ret = '\0';
    ret = strtol(input, & endptr, 10);
    free(input);
    input = NULL;

    // check for various possible errors
    if (((ret == LONG_MAX || ret == LONG_MIN) && errno == ERANGE) || (input == endptr)){
        * success = 0;
        return '\0';
    }
    * success = 1;
    return ret;
}

// gets the number to convert whether in hex, decimal or binary
char * retrieveAlphanumericInput(int * success, int base) {
    char * input = NULL;
    retrieveInput( & input, success, base);

    if (input == NULL || * success != 1) {
        * success = 0;
        return NULL;
    }

    // if we got this far, the number has beeen converted succefully
    * success = 1;
    return input;
}

void retrieveInput(char ** input, int * success, int base) {
	char * newInput = NULL;
    char maxChar = '\0';
    char c = '\0';
    int len = 0;

    if (input == NULL || success == NULL || (base < 2 || base > 36)) {
        return;
    } else {
        * success = '\0';
    }
	// allocate size bytes of suffiecient memory for input
    int size = 128;
    * input = (char * ) malloc(sizeof(char) * size);
    ( * input)[size - 1] = '\0';

    if ( * input == NULL) {
        * success = 0;
        return;
    }

	/* if number is binary, octal or decimal, then the range for input is 0 - 9 */
	/*  otherwise, it's hex, so the range for input is 0 - F  */
    if (base <= 10) {
        maxChar = base + '0' - 1;
    } else {
        maxChar = 'A' + (base - 11);
    }

    do {
        c = getchar();
        c = toupper(c);

		// zero spaces found
        if (isspace(c) == 0) {

       		 // checking for valid input
			if ((!isalnum(c) && (c != '-' && c != '+')) || ((c == '-' || c == '+') && len != 0) || c > maxChar) {
				free( * input);
				* input = NULL;
				* success = 0;
				while ((c = getchar()) != '\n' && c != EOF);
				return;
			}

			if (len == (size - 1)) {
				size += 64;
				newInput = (char * ) realloc( * input, sizeof(char) * size);
				if (newInput == NULL) {
					* success = 0;
					free( * input);
					* input = NULL;
					return;
				} else {
					* input = newInput;
					newInput = NULL;
				}
			}

			// incremenet length
			if (len == 0) {
				if (c != '-' && c != '+') {
					( * input)[len] = '+';
					len++;
				}
			}

			( * input)[len] = c;
			len++;
		}
    } while (c != '\n' && c != EOF);

    if (len == 0) {
        free( * input);
        * input = NULL;
        * success = 0;
        return;
    }

    newInput = (char * ) realloc( * input, sizeof(char) * len + 1);

    if (newInput == NULL) {
        * success = 0;
        free( * input);
        * input = NULL;
        return;
    } else {
        * input = newInput;
        newInput = NULL;
    }

    * success = 1;
    ( * input)[len] = '\0';
}
