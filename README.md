---------------------
PROJECT TITLE: A2
----------------------

TEAMMATES NAMES
--------------
- Harir Al-Rubaye
- Abdul Mahmoud
- Shayan Mohammed
- Austin Varghese
- Bahaa Zuraik
- Harikrishan singh
- Moses Oyeleye


CONTENTS OF THIS PROJECT
---------------------
-  MathOperations.c
-  BaseConversion.c 
-  Fibonacci.c
-  GreatestCommonDivisor.c 
-  PrimalityTest.c 
-  PrimeFactorization.c
-  FindArea.c
-  Matrix.c
-  FourFunctionCalculator.c
-  Mean.c
-  Median.c
-  Mode.c


CODE'S PURPOSE
---------------------
Perform Mathematical operations, including :
    
1.) Primality Test<br/>
2.) Prime Factorization<br/>
3.) Nth Term in Fibonacci Sequence<br/>
4.) Convert a Number from any Base to any Base<br/>
5.) Greatest Common Divisor<br/>
6.) Find Area<br/>
7.) Mode<br/>
8.) Mean<br/>
9.) Median<br/>
10.) Matrix<br/>
11.) FourFunctionCalculator<br/>
12.) Exit<br/>


FUNCTIONALITY
---------------------
The code calls on functions from the MATH library such as the 'pow' function.
Using well known-algorithms to find the GCD, prime numbers, Fibonacci numbers, prime factors, and base conversions.
The code uses comparison statements using returning the results that are computed by the functions.
Code error checks numbers before computing the numbers to avoid any errors.

Mode: This function takes in two parameter of type int. one is an Array and the other is an int that represent the size of the list.
      returns a value that occured the highest numbers of time which is called Mode.
      
Mean: This function takes in two parameter of type int. one is an Array and the other is an int that represent the size of the list.
      Adding all given number together and then dividing them by the total number of values to produce mean.
      
Meadian: This function takes in two parameter of type int. one is an Array and the other is an int that represent the size of the list. Sorts the list
         in an ascending order and returns the centeral value of the sorted list.
         
FourFunctionCalc: This function takes in two floats and a character array, the floats represent the numbers that will have an operation performed on 
        them. The operations range from the basic four math functions (adding, subtracting, multiplying, and dividing). The operation is determined 
        by the character array that is passed into the function. Based on what the symbol is whether its adding, subtracting, multiplying, or dividing
        the function will perform that operation on the two floats and return a float with the results of the calculation.
<br/>

Fix Command Loop:
    Earlier the functions like GreatestCommonDivisor that required 2 inputs.
    When given a second wrong input would start over from the very begining and ask the user for the first inputs.
    Now when the user enters a second or third input they only enter the wong input and dont start over. 
    Also further additions and changes to the MathOperations.c to make it work with new functions. 
    
FindArea:
    The findArea function takes in two parameters of the user choice and sucess variable. If the user choice is equal to 1, the user will enter a value for radius and
    it will find the area of the circle using the correct mathematical equal. If the user choice is equal to 2, the user will enter a length and width and it will find
    the area of a sqaure/rectangle. If the user choice is equal to 3, the user will enter a base and a height, and it will find the area of the triangle.

Matrix: 
    Addition or subtraction is accomplished by adding or subtracting corresponding elements. For example, consider matrix A and matrix B.
    The user will be asked to input number of rows and number of columns, before inputing the individual elements of the matrices.
    Note: the number of rows and columns cannot be left empty, as the user will be asked to input again.
    For example, the matrices below have 2 rows and 3 columns, Thus,
```    
         A = [1 2 3]   B = [5 6 7]   A + B = [6  8  10]
             [7 8 9]       [3 4 5]           [10 12 14]
```
   And for subtraction:
```
         A = [1 2 3]    B = [5 6 7]   A - B = [-4  -4  -4]
             [7 8 9]        [3 4 5]           [ 4   4   4]
```


HOW TO RUN
---------------------
To make the file:
$ make all

To run the program:
./MathOperations