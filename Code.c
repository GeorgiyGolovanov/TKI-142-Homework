#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
* @brief Считывает число с проверкой ввода и проверяет на условие
* @return Число
*/
const int getValidForSize();

/**
* @brief Считывает число с проверкой ввода
* @return Число
*/
int getValidForDigit();

/**
* @brief Проверяет промежуток на корректность
* @param min_ - начало промежутка
* @param max_ - конец промежутка
*/
void check_min_max(const int min_, const int max_);

/**
* @param min - минимальное число, возможное для добавления в массив
* @param max - максимальное число, возможное для добавления в массив
*/
int min = 0;
int max = 0;

/**
* @brief Проверяет лежит ли число в промежутке [min;max]
* @param value - число
*/
void checkMinMaxForDigit(const int value);

/**
* @brief Выделяет память под массив
* @param size_n - количество строк массива
* @param size_m - количесвто столбцов массива
* @return Массив
*/
int** getMakeArrays(size_t size_n, size_t size_m);

/**
* @brief Создаёт новый массив, идентинчый элементами прообразу
* @param arr - массив прообраз
* @param size_n - количество строк массива
* @param size_m - количесвто столбцов массива
* @return Новый массив
*/
int** getCopyArray(const int** arr, size_t size_n, size_t size_m);

/**
* @brief Проверяет, корректно ли выделилась память под массив
* @param arr - массив
* @param size_n - количество строк массива
*/
void checkArraysFromMemory(const int** arr, size_t size_n);

/**
* @brief Выводит на экран полученный массив
* @param arr - массив
* @param size_n - количество строк массива
* @param size_m - количесвто столбцов массива
*/
void printArrays(const int** arr, size_t size_n, size_t size_m);

/**
* @brief Заполняет массив элементами, который вводит пользователь
* @param arr - массив
* @param size_n - количество строк массива
* @param size_m - количесвто столбцов массива
*/
void getManual(int** arr, size_t size_n, size_t size_m);

/**
* @brief Заполняет массив случайными элементами
* @param arr - массив
* @param size_n - количество строк массива
* @param size_m - количесвто столбцов массива
*/
void getRandom(int** arr, size_t size_n, size_t size_m);

/**
* @brief Очищает выделенную память под массив
* @param arr - массив
* @param size_n - количество строк массива
*/
void freeArraysMemory(int** arr, size_t size_n);

/**
* @brief Выводит новый массив согласно заданию №1
* @param arr - массив
* @param size_n - количество строк массива
* @param size_m - количесвто столбцов массива
*/
void defTaskOne(int** arr, size_t size_n, size_t size_m);

/**
* @brief Выводит новый массив согласно заданию №2
* @param arr - массив
* @param size_n - количество строк массива
* @param size_m - количесвто столбцов массива
*/
void defTaskTwo(int** arr, size_t size_n, size_t size_m);

/**
* @param Manual - выбор ручного создания массива
* @param Random - выбор автоматического создания массива
* @param TaskOne - выбор первого задания
* @param TaskTwo - выбор второго задания
*/
enum {Manual=1,Random,TaskOne=1,TaskTwo};

/**
* @brief Находит, есть ли в столбце положительный нечётный элемент
* @param arr - массив
* @param size_n - количество строк массива
* @param size_m - количесвто столбцов массива
* @return Количесто положительных нечётных элементов (<=1 на столбец)
*/
const int findCountOddPositive(int** arr, size_t size_n, size_t size_m);

/**
* @brief Точка входа в программу
* @return Возвращает 0, если программа была выполнена корректно, иначе 1
*/
int main(void)
{
	system("chcp 1251");
	system("CLS");

	printf("Введите количество строк массива: ");
	size_t size_n = getValidForSize();
	printf("Введите количество столбцов массива: ");
	size_t size_m = getValidForSize();

	printf("\nВведите минимальное значение элемента массива: ");
	min = getValidForDigit();
	printf("Введите максимальное значение элемента массива: ");
	max = getValidForDigit();
	check_min_max(min,max);
	printf("Элементы массива будут задаваться в промежутке [%d;%d]\n", min,max);

	int** mainArray = getMakeArrays(size_n, size_m);
	checkArraysFromMemory(mainArray, size_n);

	printf("\nВыберите метод заполнение массива:\n%d - Ручное заполнение массива\n%d - Автоматическое заполнение массива\n", Manual, Random);
	int firstChoise = getValidForDigit();
	switch (firstChoise)
	{
	case Manual:
		getManual(mainArray, size_n, size_m);
		break;

	case Random:
		getRandom(mainArray, size_n, size_m);
		break;

	default:
		printf("Error\n	Ошибка выбора");
		freeArraysMemory(mainArray, size_n);
		exit(1);
	}

	int** newArray = getCopyArray(mainArray,size_n,size_m);
	printArrays(newArray, size_n, size_m);

	printf("\nВыберите выполняемую операцию с массивом:\n%d - Заменить минимальный элемент каждой строки нулем\n%d - Удалить все столбцы, в которых встретится нечетный положительный элемент\n", TaskOne, TaskTwo);
	int secondChoise = getValidForDigit();
	switch (secondChoise)
	{
	case TaskOne:
		defTaskOne(newArray, size_n, size_m);
		break;

	case TaskTwo:
		defTaskTwo(newArray, size_n, size_m);
		break;

	default:
		printf("Error\n	Ошибка выбора");
		freeArraysMemory(newArray, size_n);
		freeArraysMemory(mainArray, size_n);
		exit(1);
	}

	freeArraysMemory(newArray, size_n);
	freeArraysMemory(mainArray, size_n);
	return 0;
}

const int getValidForSize()
{
	int value = 0;

	if (!scanf_s("%d", &value))
	{
		printf("Error\n	Ошибка ввода размерности массива");
		exit(1);
	}

	if (value < 1)
	{
		printf("Error\n	Ошибка ввода размерности массива");
		exit(1);
	}

	return value;
}

int getValidForDigit()
{
	int value = 0;

	if (!scanf_s("%d", &value))
	{
		printf("Error\n	Ошибка ввода");
		exit(1);
	}

	return value;
}

void check_min_max(const int min_, const int max_)
{
	if (min_ >= max_)
	{
		printf("Error\n	Ошибка ввода промежутка");
		exit(1);
	}
}

void checkMinMaxForDigit(const int value)
{
	if (value > max || value < min)
	{
		printf("Error\n	Ошибка ввода, число вне промежутка");
		exit(1);
	}
}

int** getMakeArrays(size_t size_n, size_t size_m)
{
	int** arr = malloc(sizeof(int*) * size_n);
	for (size_t i = 0; i < size_n; i++)
	{
		arr[i] = malloc(sizeof(int) * size_m);
	}

	return arr;
}

void checkArraysFromMemory(const int** arr, size_t size_n)
{
	if (arr == NULL)
	{
		printf("Error\n	Ошибка выделения памяти под массив");
		exit(1);
	}
	else
	{
		for (size_t i = 0; i < size_n; i++)
		{
			if (arr[i] == NULL)
			{
				printf("Error\n	Ошибка выделения памяти под массив");
				exit(1);
			}
		}
	}
}

void printArrays(const int** arr, size_t size_n, size_t size_m)
{
	printf("\nПолученный массив:\n");
	for (size_t i = 0; i < size_n; i++)
	{
		for (size_t j = 0; j < size_m; j++)
		{
			printf("%5d", arr[i][j]);
		}
		printf("\n");
	}
}

void getManual(int** arr, size_t size_n, size_t size_m)
{
	printf("\nВведите %d элементов массива:\n", size_n*size_m);
	for (size_t i = 0; i < size_n; i++)
	{
		for (size_t j = 0; j < size_m; j++)
		{
			int num = getValidForDigit();
			checkMinMaxForDigit(num);
			printf("A[%d][%d] = %d\n", i, j, num);
			arr[i][j] = num;
		}
	}
}

void getRandom(int** arr, size_t size_n, size_t size_m)
{
	srand(time(NULL));

	for (size_t i = 0; i < size_n; i++)
	{
		for (size_t j = 0; j < size_m; j++)
		{
			arr[i][j] = rand() % (max-min+1) + min;
		}
	}
}

void freeArraysMemory(int** arr, size_t size_n)
{
	for (size_t i = 0; i < size_n; i++)
	{
		free(arr[i]);
	}
	free(arr);
}

int** getCopyArray(const int** arr, size_t size_n, size_t size_m)
{
	int** array = getMakeArrays(size_n, size_m);
	checkArraysFromMemory(array,size_n);

	for (size_t i = 0; i < size_n; i++)
	{
		for (size_t j = 0; j < size_m; j++)
		{
			array[i][j] = arr[i][j];
		}
	}

	return array;
}

void defTaskOne(int** arr, size_t size_n, size_t size_m)
{
	for (size_t i = 0; i < size_n; i++)
	{
		int minimum = arr[i][0];
		int idx = 0;

		for (size_t j = 0; j < size_m; j++)
		{
			if (minimum > arr[i][j])
			{
				minimum = arr[i][j];
				idx = j;
			}
		}

		arr[i][idx] = 0;
	}

	printArrays(arr, size_n, size_m);
}

void defTaskTwo(int** arr, size_t size_n, size_t size_m)
{
	int count = findCountOddPositive(arr, size_n, size_m);

	if (count == 0)
	{
		printArrays(arr, size_n, size_m);
		printf("\nМассив не изменён\n");
	}
	else
	{
		int** newarr = getMakeArrays(size_n, size_m);
		checkArraysFromMemory(newarr, size_n);

		int* idx = malloc(sizeof(int) * size_m);
		for (size_t i = 0; i < size_m; i++)
		{
			idx[i] = 1; 
		}

		for (size_t j = 0; j < size_m; j++)
		{
			for (size_t i = 0; i < size_n; i++)
			{
				if (arr[i][j] % 2 != 0 && arr[i][j] > 0)
				{
					idx[j] = 0;
					break;
				}
			}
		}

		size_t next_idx = 0;
		for (size_t j = 0; j < size_m; j++)
		{
			if (idx[j] == 1)
			{ 
				for (size_t i = 0; i < size_n; i++)
				{
					newarr[i][next_idx] = arr[i][j];
				}
				next_idx++;
			}
		}

		printArrays(newarr, size_n, size_m - count);
		printf("\nУдалено %d столбцов\n", count);
		freeArraysMemory(newarr, size_n);
		free(idx);
	}
}

const int findCountOddPositive(int** arr, size_t size_n, size_t size_m)
{
	int count = 0;
	for (size_t j = 0; j < size_m; j++)
	{
		for (size_t i = 0; i < size_n; i++)
		{
			if (arr[i][j] % 2 != 0 && arr[i][j] > 0)
			{
				count++;
				break;
			}
		}
	}
	return count;
}
