#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include "task1.h"
#include <assert.h>

void testSignOfZodiack()
{
	int dateArr1[] = { 22, 3, 2010, 1 };
	int dateArr2[] = { 22, 1, 2003, 0 };
	int element1, element2;
	char *arr1 = signOfZodiack(dateArr1, &element1);
	char *arr2 = signOfZodiack(dateArr2, &element2);
	char result1[] = "Овен";
	char result2[] = "Водолей";
	assert(strcmp(arr1, result1) == 0);
	assert(strcmp(arr2, result2) == 0);
}

void testIsDay()
{
    int arr1[] = {29, 2};
    int arr2[] = {31, 12};
    assert(isDay(arr1[0], arr1[1]) == 0);
    assert(isDay(arr2[0], arr2[1]) == 1);

}

int main()
{
	testSignOfZodiack();
	testIsDay();
	printf("Tests passed");
	return 0;
}

