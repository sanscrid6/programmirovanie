#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funcs.h"


int main() {
    const int n = 3;
    int result;
    char*** matrixes[n];
    int horizontalSize = 4, verticalSize = 3, i = 0;
    char* strs[4];
    strs[0] = "zxc";
    strs[1] = "asdda";
    strs[2] = "asdsa";
    strs[3] = "asddsa";
    for(i = 0; i<n; i++)
    {
        verticalSize = 3+i;
        horizontalSize = 4+i;
        printf("Matrix number %i\n", i+1);
        matrixes[i] = (char***)malloc(sizeof(char***)*verticalSize);
        if(matrixes[i] != NULL)
        {
            result = initMatrix(matrixes[i],verticalSize, horizontalSize, strs);
            if(result == 0)
            {   
                editMatrix(matrixes[i], verticalSize, horizontalSize);
                freeMatrix(matrixes[i], verticalSize);
            }
            else
            {
                 printf("Cannot create array\n");
            }
        }
        else
        {
            printf("Cannot create array\n");
        }

    }
    return 0;
}
