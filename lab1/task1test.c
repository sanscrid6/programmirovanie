#include "task1test.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


void testIsOneColor()
{
    int * grid = init();
    int testArr[4] = {1,1,3,1};
    int result = isOneColor(testArr, grid);
    assert(result == 1);
    free(grid);
}

int main()
{
    testIsOneColor();
    printf("Test passed");
    return 0;
}