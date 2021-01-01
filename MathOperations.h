#ifndef MATHOPERATIONS_H_INCLUDED
#define MATHFOPERATIONS_H_INCLUDED
// math operations functions
int main(int, char*[]);

long int retrieveNumericInput(int*);
char* retrieveAlphanumericInput(int*, int);
void retrieveInput(char**, int*, int);
int errorChecker(int * success, int i);

// base conversion functions
char* baseConversion(int, int, char*, int*);
int willNextOverflow(unsigned long int, unsigned long int);

// fabonacci fucntions
unsigned long int nthFibonacciTerm(long int, int*);
int willOverflow(unsigned long int, unsigned long int);

//GreatestCommonDivisor functions
long int gcd(long int, long int, int*);

// primalityTest
int isPrime(long);
long int getNextPrime(long int);

//primeFactorization
char* primeFactorization(long int, int*);
char* toString(long int);
char* addToList(char*, long int, long int);

//newFunctions
float FindArea(int x, int* success);
int mode(int a[],int n);
float median(int Array[], int n);
float Mean(float Array[], int n);

void calculateMatrix(int choice, int rows, int cols);
int** getMatrixValues(int rows, int cols);
int** createMatrix(int row, int col);
void destroyMatrix(int** matrix,int row);

float fourFunctionCalc(float num1, float num2, char operation[]);
#endif
