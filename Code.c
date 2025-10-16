#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

/**
* @brief Считывает значение, введённое с клавиатуры, с проверкой ввода
* @return Считанное значение
*/
double defValid();

/**
* @brief Проверяет переменную на условие
* @param input - значение проверяемой переменной
*/
void checkValueForN(int input);

/**
* @brief Проверяет переменную на условие
* @param input - значение проверяемой переменной
*/
void checkValue(int input);

/**
* @brief Считает сумму согласно условию 1
* @param arr - массив
* @param n - размер массива
* @return Посчитанное значение
*/
int defForTask1(int* arr, const int n);

/**
* @brief Находит индексы согласно условию 2
* @param arr - массив
* @param n - размер массива
*/
void defForTask2(int* arr, const int n);

/**
* @brief Создаёт новый массив согласно условию 3
* @param arr - массив
* @param n - размер массива
*/
void defForTask3(int* arr, const int n);

/**
* @brief Рассчитывает минимальное значение массива
* @param arr - массив
* @param n - размер массива
* @return Возвращaет минимальный элемент массива
*/
int defMINN(int* arr, const int n);

/**
* @brief Рассчитывает максимальное значение массива
* @param arr - массив
* @param n - размер массива
* @return Возвращaет максимальный элемент массива
*/
int defMAXX(int* arr, const int n);

/**
@brief choiseOne - первый выбор (Ручное заполнение массива)
@brief  choiseTwo - второй выбор (Автоматическое заполнение массива)
@brief  taskOne - выполнение первого задания
@brief  taskTwo - выполнение второго задания
@brief  taskThree - выполнение третьего задания
*/
enum { choiseOne=1, choiseTwo, taskOne=1, taskTwo, taskThree};

/**
* @brief Точка входа в программу
* @return Возвращает 0, если программа была выполнена корректно, иначе 1
*/
int main(void)
{
	system("chcp 1251");
	srand(time(NULL));

	printf("Введите размер массива: ");
	int n = defValid();
	checkValueForN(n);

	int* A = malloc(sizeof(int) * n);

	int min = -1000;
	int max = 1000;

	printf("\nКак будет заполнен массив?\n %d - Ручной ввод\n %d - Автоматический ввод\n",choiseOne,choiseTwo);
	int choise = (int)defValid();

	switch (choise)
	{
	case choiseOne:
		printf("\nВведи %d элемент-а(ов) массива:\n", n);
		for (int i = 0; i < n; i++)
		{
			int num = defValid();
			checkValue(num);
			printf("A[%d] = %d\n", i,num);
			A[i] = num;
		}
		break;

	case choiseTwo:
		for (int i = 0; i < n; i++)
		{
			int numm = min + rand() % (max - min + 1);
			A[i] = numm;
		}
		break;

	default:
		printf("Error");
		exit(1);
	}

	
	printf("\nВведённый массив: \n");
	for (int i = 0; i < n; i++)
	{
		printf("%d\n", A[i]);
	}

	printf("\nКакие будут преобразования?\n%d - Найти сумму четных отрицательных элементов\n%d - Вывести индексы тех элементов, значения которых кратны 3 и 6\n%d - Заменить нулями элементы массива между минимальным и максимальным, кроме их самих\n", taskOne, taskTwo, taskThree);
	int second_choise = (int)defValid();
	
	switch (second_choise)
	{
	case taskOne:
		printf("\nСумма чётных отрицательных элементов = %d\n", defForTask1(A, n));
		break;

	case taskTwo:
		defForTask2(A, n);
		break;

	case taskThree:
		defForTask3(A, n);
		break;

	default:
		printf("Error");
		exit(1);
	}

	return 0;
}

double defValid()
{
	double valid = 0;
	if (!scanf_s("%lf", &valid))
	{
		printf("Error");
		exit(1);
	}
	return valid;
}

void checkValue(double input)
{
	if (input > 1000 || input < -1000)
	{
		printf("Error\nЧисло должно лежать в промежутке [-1000;1000]");
		exit(1);
	}
}

void checkValueForN(double input)
{
	if (input < 2)
	{
		printf("Error\nЧисло должно быть не меньше 2");
		exit(1);
	}
}

int defForTask1(int* arr, const int n)
{
	int summ = 0;
	for (int i = 0; i < n; i++)
	{
		if ((arr[i] % 2 == 0) && (arr[i] < 0))
		{
			summ += arr[i];
		}
	}
	return summ;
}

void defForTask2(int* arr, const int n)
{
	_Bool chek = 0;
	printf("\nИндексы элементов, значения которых кратны 3 и 6: ");

	for (int i = 0; i < n; i++)
	{
		if ((arr[i] % 6 == 0) && (arr[i] % 3 == 0))
		{
			printf("%d ",i);
			chek = 1;
		}
	}
	if (!chek)
	{
		printf("\nТаких элементов в массиве нету");
	}
}

int defMAXX(int* arr, const int n)
{
	int maxx = -1001;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > maxx)
		{
			maxx = arr[i];
		}
	}
	return maxx;
}

int defMINN(int* arr, const int n)
{
	int minn = 1001;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < minn)
		{
			minn = arr[i];
		}
	}
	return minn;
}

void defForTask3(int* arr, const int n)
{
	const int defmax = defMAXX(arr, n);
	const int defmin = defMINN(arr, n);
	printf("\nНовый массив: \n");
	for (int i = 0; i < n; i++)
	{
		if (!(arr[i] == defmin || arr[i] == defmax))
		{
			arr[i] = 0;
		}
		printf("%d\n", arr[i]);
	}
}
