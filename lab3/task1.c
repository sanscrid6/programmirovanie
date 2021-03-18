#include <stdio.h>
#include <stdlib.h>
#include "task1.h"
int** init(int n, int m)
{
    int i, j;
    int ** arr = (int **)malloc(n*sizeof(int*));
    if(arr == NULL)
    {
        printf("Malloc error");
        return NULL;
    }
    for(i = 0; i<n;i++)
    {
        arr[i] = (int *)malloc(m*sizeof(int));
        if(arr[i] == NULL)
        {
            printf("Malloc error");
            return NULL;
        }
    }
    for(i = 0; i<n; i++)
    {
        for(j = 0; j<m; j++)
        {
            if(i%2 == 0)
            {
                if(j%2 == 0)
                {
                    arr[i][j] = 1;
                }
                else
                {
                    arr[i][j] = 2;
                }
            }
            else
            {
                if(j%2 == 0)
                {
                    arr[i][j] = 3;
                }
                else
                {
                    arr[i][j] = 4;
                }
            }

        }

    }
    return arr;

}


void inputHandler(int* n, int* m)
{

    while(*m<1 && *n<1)
    {
        char buff[50];
        printf("Enter n, m\n");
        fgets(buff, 50, stdin);
        sscanf(buff, "%i %i", n, m);
    }
}

#ifndef TESTING
int main() {
    int n = -1, m = -1, i = 0, j = 0;
    int ** arr;
    inputHandler(&n, &m);
    arr = init(n, m);
    if(arr == NULL)
    {
        return 1;
    }
    for(i = 0; i<n;i++)
    {
        for(j = 0; j<m; j++)
        {
             printf("%3d\t", arr[i][j]);
        }
        printf("\n");
    }
    for(i = 0; i<n;i++)
    {
        free(arr[i]);
    }
    free(arr);
    return 0;
}
#endif