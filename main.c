#include <stdio.h>
#include <stdlib.h>
/**
@brief: algorithm used to flood fill a matrix, takes a coordinate from the user and finds all its adjacent equals
@param1: matrix in which the search is done
@param2: current value of row in which the number is located
@param2: current value of column in which the number is located
@param3: number of rows and cols since it is a square matrix
@param4: the value of the number we want to find its adjacent equals
@param5: the value which the adjacent equal values will be "colored"
@return: the equivalent matrix since it is passed as a pointer
*/
void floodFill(int **matrix, int currX, int currY, int num, int sourceColor, int newColor);

int main()
{

    int i, j, num;
    int x, y;

    printf("Enter size of square matrix: "); //value of rows and cols
    scanf("%d", &num);

    int **matrix;
    matrix = (int**)malloc(num * sizeof(int*)); // dynamic memory allocation for matrix
    for(i=0; i<num; i++){
        matrix[i] = (int*)malloc(num * sizeof(int));
    }
    if(matrix == NULL){
        printf("Could not allocate memory!"); // if memory is not allocated, return with an error
        return -1;
    }

    printf("\nEnter elements of matrix: "); // part of code to take the values of the matrix
    for(i=0; i<num; i++){
        for(j=0; j<num; j++){
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\nEnter # of row and column you wish to flood fill: "); // first initial value to find its equivalents
    scanf("%d %d", &x, &y);

    int sourceColor = matrix[x][y]; // the initial value of the source color given by its corresponding  matrix value
    int newColor = sourceColor;
    floodFill(matrix, x, y, num, sourceColor, newColor); // first call of recursive function

    printf("Matrix: \n");
    for(i=0; i<num; i++){
        for(j=0; j<num; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    for(i=0; i<num; i++){
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}

void floodFill(int **matrix, int currX, int currY, int num, int sourceColor, int newColor)
{
    int i;

    if((currX < 0) || (currX >= num) || (currY < 0) || (currY >= num) || matrix[currX][currY] != sourceColor)
        return; // if the coordinates are out of bounds or the current value of the matrix does not match the
                // source color, it returns because no more moves are available

    matrix[currX][currY] = newColor; // assigning the current matrix value the new color

    for(i=0; i<=2; i=i+2){ // i jumps from 0 to 2 so that the middle element wont be checked
        floodFill(matrix, (currX - 1 + i), currY, num, sourceColor, newColor); // checking first one element down then up
        floodFill(matrix, currX, (currY - 1 + i), num, sourceColor, newColor); // checking one element left then right
    }
}
