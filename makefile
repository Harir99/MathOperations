CC=gcc
CFLAGS=-std=c99 -Wall -pedantic

all: MathOperations

MathOperations: MathOperations.o BaseConversion.o Fibonacci.o GreatestCommonDivisor.o PrimalityTest.o PrimeFactorization.o FindArea.o mode.o mean.o median.o matrix.o FourFunctionCalc.o
	$(CC) $(CFLAGS) MathOperations.o BaseConversion.o Fibonacci.o GreatestCommonDivisor.o PrimalityTest.o PrimeFactorization.o FindArea.o mode.o mean.o median.o matrix.o FourFunctionCalc.o -o MathOperations -lm

MathOperations.o: MathOperations.c
	$(CC) $(CFLAGS) -c MathOperations.c -o MathOperations.o

BaseConversion.o: BaseConversion.c
	$(CC) $(CFLAGS) -c BaseConversion.c -o BaseConversion.o -lm

Fibonacci.o: Fibonacci.c
	$(CC) $(CFLAGS) -c Fibonacci.c -o Fibonacci.o

GreatestCommonDivisor.o: GreatestCommonDivisor.c
	$(CC) $(CFLAGS) -c GreatestCommonDivisor.c -o GreatestCommonDivisor.o

PrimalityTest.o: PrimalityTest.c
	$(CC) $(CFLAGS) -c PrimalityTest.c -o PrimalityTest.o -lm

PrimeFactorization.o: PrimeFactorization.c
	$(CC) $(CFLAGS) -c PrimeFactorization.c -o PrimeFactorization.o -lm

FindArea.o:FindArea.c
	$(CC) $(CFLAGS) -c FindArea.c -o FindArea.o -lm

mode.o:mode.c
	$(CC) $(CFLAGS) -c mode.c -o mode.o -lm

mean.o:mean.c
	$(CC) $(CFLAGS) -c mean.c -o mean.o -lm

median.o:median.c
	$(CC) $(CFLAGS) -c median.c -o median.o -lm

matrix.o:matrix.c
	$(CC) $(CFLAGS) -c matrix.c -o matrix.o -lm

FourFunctionCalc.o:FourFunctionCalc.c
	$(CC) $(CFLAGS) -c FourFunctionCalc.c -o FourFunctionCalc.o -lm
	
clean:
	rm -f *.o MathOperations
