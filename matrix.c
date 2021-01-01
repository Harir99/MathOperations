/*
*Matrix by Shayan Mohammed(1097825) and Harir Al Rubaye (1108085) 
*/


#include <stdio.h>
#include <stdlib.h>
#include "MathOperations.h"

void calculateMatrix(int choice, int rows, int cols){
    int row = 0;
    int col = 0;
    int** matrix1;
    int** matrix2;
    int** sum;
    int** subtract;
    int *success = (int*)malloc(sizeof(int));
	*success = '\0';

    // get values for matrix 1
    printf("please enter the elements of the first matrix one by one : \n");
    matrix1 = getMatrixValues(rows,cols);

    // get values for matrix 2
    printf("please enter the elements of the second matrix one by one : \n");
    matrix2 = getMatrixValues(rows,cols);

    // do the addition and subtraction of matrices
    sum = createMatrix(rows,cols);
    subtract = createMatrix(rows,cols);

    for ( row = 0; row < rows; row++){
        for ( col = 0; col < cols; col++){
            sum[row][col] = matrix1[row][col] + matrix2[row][col];
            subtract[row][col] = matrix1[row][col] -  matrix2[row][col];

        }
    }
    // print results
    if(choice == 1){

        printf("Sum of the two matrices:\n");

        for( row = 0; row < rows; row++) {
            for ( col = 0; col < cols; col++){
                printf("%d\t",sum[row][col]);
            }
                printf("\n");
        }
    } else if (choice == 2){
         printf("difference of two matrices:\n");

        for( row = 0; row < rows; row++) {
            for ( col = 0; col < cols; col++){
                printf("%d\t",subtract[row][col]);

            }
                printf("\n");
        }
    }
    // free memory
   destroyMatrix(matrix1,rows);
   destroyMatrix(matrix2,rows);
   destroyMatrix(subtract,rows);
   destroyMatrix(sum,rows);


}
int** getMatrixValues(int rows, int cols){
    int *success = (int*)malloc(sizeof(int));
	*success = '\0';
    int** matrix = createMatrix(rows,cols);
    int row;
    int col;
    for ( row = 0; row < rows; row++){
        for ( col = 0; col < cols; col++){
            printf("Enter element a%d%d: ",row+1,col+1);
			matrix[row][col] = retrieveNumericInput(success);


        }

    }
    return matrix;
}
int** createMatrix(int row, int col){
    int** matrix;
    matrix = (int**) malloc(row*sizeof(int*));
    for (int i = 0; i < row; i++)
    {
       matrix[i] = (int*) malloc(col*sizeof(int));
    }
    return matrix;
}

void destroyMatrix(int** matrix,int row){
    int i;
     for (i = 0; i < row; i++){
       free(matrix[i]);
    }
    free(matrix);
}
