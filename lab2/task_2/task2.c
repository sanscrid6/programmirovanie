#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include "task2.h"

unsigned long int factorial(int n)
{
	unsigned long int result = 1;
	int i;
	for (i = 1; i <= n; i++)
	{
		result *= i;
	}
	return result;
}

int countN(float epsilon, float x)
{
	float temp = 0;
	int n = 1;
	do
	{
		temp = (float)pow(x, n) / factorial(n);
		n++;
	} while (temp > epsilon);
	return n-1;
}

#ifndef TESTING
int main()
{
	float epsilon, summ1 = 0,  x;
	int  n = 20, i;
	int sign = 1;
	char buff[50];
	printf("Enter epsilon ");
	fgets(buff, 50, stdin);
	sscanf(buff, "%f", &epsilon);
	printf("Enter x ");
	fgets(buff, 50, stdin);
	sscanf(buff, "%f", &x);
	if (x > 4)
	{
		printf("Incorrect input(x < 5)");
		return 1;
	}
	n = countN(epsilon, x);
	if (2*n-1 > 20)
	{
		printf("Too small epsilon");
		return 2;
	}
	for (i = 1; i <= 2*n-1; i+=2)
	{
		summ1 += (double)pow(x, i) / factorial(i) * sign;
		sign *= -1;
	}
	printf("sin(x) = %.10f\tSumm of Teylor series = %.10f\tDifference is %.10f",sin(x), summ1, fabs(sin(x)-summ1));

}

#endif