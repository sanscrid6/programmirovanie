#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include "task1test.h"

int isOk(int* arr)
{
	int i;
	for (i = 0; i < 4; i++)
	{
		if (arr[i] < 0)
		{
			return 0;
		}
	}
	return 1;
}

void inputHandler(char* buff, int* arr)
{
	int i = 0;
	printf("Введите координаты клеток\n");
	while (!isOk(arr))
	{
		fgets(buff, 50, stdin);
		if (isdigit(buff[0]) && buff[0] != '0' && buff[0] != '9' && i % 2 == 0 && strlen(buff) == 2)
		{
			arr[i] = atoi(buff);
			i++;
		}
		else if ((buff[0] == 'a' || buff[0] == 'b' || buff[0] == 'c' || buff[0] == 'd' ||
			buff[0] == 'e' || buff[0] == 'f' || buff[0] == 'g' || buff[0] == 'h') && i % 2 == 1 && strlen(buff) == 2)
		{
			arr[i] = (int)buff[0] - 96;
			i++;
		}
		else
		{
			printf("Некорректный ввод((\n");
		}
	}
}



#ifndef TESTING
int main()
{
	char buff[50];
	int i = 0;
	int coordinates[4];
	int * grid = NULL;
	setlocale(LC_ALL, "ru");
	grid = init();
	for (i = 0; i < 4; i++)
	{
		coordinates[i] = -1;
	}
	inputHandler(buff, coordinates);
	if(isOneColor(coordinates, grid))
	{
	    printf("Одного цвета");
	}
	else
	{
	    printf("Не одного цвета");
	}
	free(grid);
	return 0;
}
#endif

int* init()
{
	int* arr = (int*)malloc(sizeof(int) * 64);
	int i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (i % 2 == 0 && j % 2 == 0)
			{
				*(arr + i * 8 + j) = 1;
			}
			else if (i % 2 == 1 && j % 2 == 1)
			{
				*(arr + i * 8 + j) = 1;
			}
			else
			{
				*(arr + i * 8 + j) = 0;
			}
			printf("%i ", *(arr + i * 8 + j));
		}
		printf("\n");
	}
	return arr;
}

int isOneColor(int* coordinates, int* grid)
{
	if (*(grid + 8 *(coordinates[0]-1) + coordinates[1]-1) == *(grid + (coordinates[2]-1) * 8 + coordinates[3]-1))
	{
		return 1;
	}
    return 0;
}