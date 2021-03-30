#include "funcs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int isPalindrome(char* str)
{
    int i = 0;
    for(i = 0; i<strlen(str)/2; i++)
    {
        if(str[i]!=str[strlen(str)-i-1])
        {

            return 0;
        }
    }
    return 1;
}

void initMatrix(char*** matrix, int verticalSize, int horizontalSize, char** strings)
{
    int i = 0, j = 0, size = sizeof(strings)/2;
    for(i = 0; i<verticalSize; i++)
    {
        matrix[i] = (char**)malloc(sizeof(char**)*horizontalSize);
    }
    for(i = 0; i<verticalSize; i++)
    {
        for(j = 0; j<horizontalSize;j++)
        {
            matrix[i][j] = strings[j%(size)];
        }
    }
}

void freeMatrix(char*** matrix, int verticalSize)
{
    int i = 0;
    for(i = 0; i<verticalSize; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}

void editMatrix(char*** matrix, int verticalSize, int horizontalSize)
{
    int i = 0, j = 0, flag = 0, num = 0, k = 0;
    char* temp;
    printf("Matrix before deleting\n");
    for(i = 0; i<verticalSize; i++)
    {
        for(j = 0; j<horizontalSize; j++)
        {
            printf("%s\t", matrix[i][j]);
        }
        printf("\n");
    }
    for(i = 0; i<verticalSize; i++)
    {
        for(j = 0; j<horizontalSize;j++)
        {
            if(isPalindrome(matrix[i][j]))
            {
                matrix[i][j] = "";

            }
        }
    }
    for(i = 0; i<verticalSize*horizontalSize; i++)
    {
        if(strcmp(matrix[i/horizontalSize][i%horizontalSize], "") == 0)
        {
            flag = 0;
            for(j = i; j<verticalSize*horizontalSize-1; j++)
            {
                if(strcmp(matrix[j/horizontalSize][j%horizontalSize], "") != 0)
                {
                    num = j;
                    flag = 2;
                    break;
                }

            }
            if(flag == 2)
            {
                matrix[i/horizontalSize][i%horizontalSize] = matrix[num/horizontalSize][num%horizontalSize];
                matrix[num/horizontalSize][num%horizontalSize] = "";
            }
            for(j = i+1; j<verticalSize*horizontalSize-1; j++)
            {
                k = j+1;
                temp = matrix[j/horizontalSize][j%horizontalSize];
                matrix[j/horizontalSize][j%horizontalSize] = matrix[k/horizontalSize][k%horizontalSize];
                matrix[k/horizontalSize][k%horizontalSize] = temp;
            }
        }
    }
    printf("\nMatrix after deleting\n");
    for(i = 0; i<verticalSize; i++)
    {
        for(j = 0; j<horizontalSize;j++)
        {
            if(strcmp(matrix[i][j], "") == 0)
            {
                flag = 3;
                break;
            }
            printf("%s\t", matrix[i][j]);
        }
        if(flag == 3)
        {
            break;
        }
        printf("\n");
    }
    printf("\n\n");
}