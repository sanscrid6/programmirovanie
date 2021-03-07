#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include "task1.h"

/*1 - земля 2 - воздух 3 - огонь 4 - вода*/

char* signOfZodiack(int* dateArr, int * element)
{
	if ((dateArr[1] == 3 && dateArr[0] >=21) || (dateArr[1] == 4 && dateArr[0] <=20))
	{
		static char sign[] = "Овен";
		*element = 3;
		return sign;
	}
	else if ((dateArr[1] == 4 && dateArr[0] >= 21) || (dateArr[1] == 5 && dateArr[0] <= 20))
	{
		static char sign[] =  "Телец" ;
		*element = 1;
		return sign;
	}
	else if ((dateArr[1] == 5 && dateArr[0] >= 21) || (dateArr[1] == 6 && dateArr[0] <= 20))
	{
		static char sign[] = "Близнецы" ;
		*element = 2;
		return sign;
	}
	else if ((dateArr[1] == 6 && dateArr[0] >= 21) || (dateArr[1] == 7 && dateArr[0] <= 22))
	{
		static char sign[] =  "Рак" ;
		*element = 4;
		return sign;
	}
	else if ((dateArr[1] == 7 && dateArr[0] >= 23) || (dateArr[1] == 8 && dateArr[0] <= 22))
	{
		static char sign[] =  "Лев" ;
		*element = 3;
		return sign;
	}
	else if ((dateArr[1] == 8 && dateArr[0] >= 23) || (dateArr[1] == 9 && dateArr[0] <= 23))
	{
		static char sign[] =  "Дева" ;
		*element = 1;
		return sign;
	}
	else if ((dateArr[1] == 9 && dateArr[0] >= 24) || (dateArr[1] == 10 && dateArr[0] <= 23))
	{
		static char sign[] =  "Весы" ;
		*element = 2;
		return sign;
	}
	else if ((dateArr[1] == 10 && dateArr[0] >= 24) || (dateArr[1] == 11 && dateArr[0] <= 21))
	{
		static char sign[] =  "Скорпион" ;
		*element = 4;
		return sign;
	}
	else if ((dateArr[1] == 11 && dateArr[0] >= 22) || (dateArr[1] == 12 && dateArr[0] <= 21))
	{
		static char sign[] =  "Стрелец" ;
		*element = 3;
		return sign;
	}
	else if ((dateArr[1] == 12 && dateArr[0] >= 22) || (dateArr[1] == 1 && dateArr[0] <= 19))
	{
		static char sign[] =  "Козерог" ;
		*element = 1;
		return sign;
	}
	else if ((dateArr[1] == 1 && dateArr[0] >= 22) || (dateArr[1] == 2 && dateArr[0] <= 18))
	{
		static char sign[] =  "Водолей" ;
		*element = 2;
		return sign;
	}
	else if ((dateArr[1] == 2 && dateArr[0] >= 19) || (dateArr[1] == 3 && dateArr[0] <= 20))
	{
		static char sign[] =  "Рыбы" ;
		*element = 4;
		return sign;
	}

}

int isDay(int day, int month)
{
	if (month == 2 && day >= 1 && day <= 28)
	{
		return 1;
	}
	else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 9 || month == 10 || month == 12) && (day>=1 && day<=31))
	{
		return 1;
	}
	else if (day<=30 && day>=1 && (month == 4 || month == 6 || month == 10 || month == 11 ))
	{
		return 1;
	}
	return 0;
}


int isDigit(char * arr)
{
	int i = 0;
	while (i<strlen(arr)-1)
	{
		if (!isdigit(arr[i]))
		{
			return 0;
		}
		i++;
	}
	return 1;
}


int isMonth(int month)
{
	if (month <= 12 && month >= 1)
	{
		return 1;
	}
	return 0;
}

int* inputHandler()
{
	char buff[50];
	int* dateArr = (int*)malloc(sizeof(int) * 4);
	int i;
	if (dateArr == NULL)
	{
		return NULL;
	}
	for (i = 0; i < 4; i++)
	{
		dateArr[i] = -1;
	}
	while (dateArr[1] < 0)
	{
		printf("Введите месяц ");
		fgets(buff, 50, stdin);
		if (isDigit(buff))
		{
			dateArr[1] = atoi(buff);
			isMonth(dateArr[1]);
			if (!isMonth(dateArr[1]))
			{
				dateArr[1] = -1;
				printf("Не корректный ввод\n");
			}
		}
		else
		{
			printf("Не корректный ввод\n");
		}

	}
	while (dateArr[0] < 0)
	{
		printf("Введите дату рождения ");
		fgets(buff, 50, stdin);
		if (isDigit(buff))
		{
			dateArr[0] = atoi(buff);
			if (!isDay(dateArr[0], dateArr[1]))
			{
				dateArr[0] = -1;
				printf("Не корректный ввод\n");
			}
		}
		else
		{
			printf("Не корректный ввод\n");
		}
	}
	while (dateArr[2] < 0)
	{

		printf("Введите год ");
		fgets(buff, 50, stdin);
		if (isDigit(buff))
		{
			dateArr[2] = atoi(buff);
			if (dateArr[2] < 0 || dateArr[2]>2021)
			{
				printf("Не корректный ввод\n");
				dateArr[2] = -1;
			}
		}
		else
		{
			printf("Не корректный ввод\n");
		}
	}
	while (dateArr[3] < 0)
	{
		printf("Введите пол(0 - женщина, 1 - мужчина) ");
		fgets(buff, 50, stdin);
		if ((buff[0] == '1' || buff[0] == '0') && strlen(buff) == 2)
		{
			dateArr[3] = atoi(buff);
		}
		else
		{
			printf("Не корректный ввод\n");
		}
	}
	return dateArr;
}

#ifndef TESTING
int main()
{
	int el1, el2;
	int switcher;
	char buff[2];
	int **people = (int**)malloc(sizeof(int*) * 2);
	char **signs = (char**)malloc(sizeof(char*) * 2);
	setlocale(LC_ALL, "Russian");
	if (people == NULL || signs == NULL)
	{
		printf("Случилась ошибка");
		return 1;
	}
	while (1)
	{
		printf("1 - Ввод данных первого человека\n2 - ввод данных второго человека\n3 - определение знака зодиака каждого партнера\n4 - возможна ли между партнерами дружба\n5 - подходят ли они друг другу в бизнесе\n6 - смогут ли жить в браке\n7 - информация о версии и авторе программы\n8 - выход\n");
		scanf("%d", &switcher);
		fgets(buff, 2, stdin);
		if (switcher == 1)
		{
			people[0] = inputHandler();
			if (people[0] == NULL)
			{
				printf("Случилась ошибка");
				break;
			}
			signs[0] = signOfZodiack(people[0], &el1);
		}
		else if (switcher == 2)
		{
			people[1] = inputHandler();
			if (people[1] == NULL)
			{
				printf("Случилась ошибка");
				break;
			}
			signs[1] = signOfZodiack(people[1], &el2);
		}
		else if (switcher == 3)
		{
			printf("Знак зодиака 1 человека - %s\nЗнак зодиака 2 человека - %s\n", signs[0], signs[1]);
		}
		else if (switcher == 4)
		{
			if (el1 == el2)
			{
				printf("Астрологи полагают, что дружба возможна\n");
			}
			else
			{
				printf("Астрологи пологают, что дружба не возможна\n");
			}
		}
		else if (switcher == 5)
		{
			if (strcmp(signs[0], signs[1]) == 0)
			{
				printf("Вы совместны в бизнесе\n");
			}
			else
			{
				printf("Вы не совместны в бизнесе\n");
			}

		}
		else if (switcher == 6)
		{
			if (people[0][3] != people[1][3] && (el1%2 == el2%2))
			{
				printf("Ура!!!\nВы подходите для своместной жизни\n");
			}
			else
			{
				printf("Вы не подходите для совместной жизни((\n");
			}
		}
		else if (switcher == 7)
		{
			printf("Feedback creator: Ivan Svetushkov\n");
		}
		else if (switcher == 8)
		{
			break;
		}
	}
	free(people[0]);
	free(people[1]);
	free(people);
	free(signs);
	return 0;
}

#endif