#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include "task2.h"
#include <assert.h>


void testFactorial()
{
    int n = 5;
    assert(factorial(n) == 120);
}

void testCountN()
{
    float epsilon = 0.01;
    float x = 0.3;
    assert(countN(epsilon, x) == 3);
}

int main()
{
    testFactorial();
    testCountN();
    printf("Tests passed");
    return 0;
}