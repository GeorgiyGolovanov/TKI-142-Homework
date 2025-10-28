#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

/**
* @brief Считывает значение, введённое с клавиатуры, с проверкой ввода
* @return Считанное значение
*/
int getValid();

/**
* @brief Проверяет переменную на условие
* @param input - значение проверяемой переменной
*/
void checkValueForN(const int input);

/**
* @brief Проверяет переменную на условие
* @param input - значение проверяемой переменной
*/
void checkValue(const int input, const int min, const int max);

/**
* @brief Считает сумму согласно условию 1
* @param arr - массив
* @param size - размер массива
* @return Посчитанное значение
*/
int defForTask1(const int* arr, const size_t size);

/**
* @brief Находит индексы согласно условию 2
* @param arr - массив
* @param size - размер массива
*/
void defForTask2(const int* arr, const size_t size);

/**
* @brief Создаёт новый массив согласно условию 3
* @param arr - массив
* @param size - размер массива
*/
void defForTask3(const int* arr, const size_t size);

/**
* @brief Находит минимальное значение массива
* @param arr - массив
* @param size - размер массива
* @return Возвращaет минимальный элемент массива
*/
int defMINN(const int* arr, const size_t size);

/**
* @brief Находит максимальное значение массива
* @param arr - массив
* @param size - размер массива
* @return Возвращaет максимальный элемент массива
*/
int defMAXX(const int* arr, const size_t size);

/**
@brief choiseOne - первый выбор (Ручное заполнение массива)
@brief  choiseTwo - второй выбор (Автоматическое заполнение массива)
@brief  taskOne - выполнение первого задания
@brief  taskTwo - выполнение второго задания
@brief  taskThree - выполнение третьего задания
*/
enum { choiseOne=1, choiseTwo, taskOne=1, taskTwo, taskThree};

/**
* @brief Проверяет значения на условие
* @param min - минимально возможный элемент массива
* @param max - максимально возможный элемент массива
*/
void defCheckMinMax(const int min, const int max);

/**
* @brief Заполняет массив элементами, который пользователь вводит с клавиатуры, c учётом максимально и минимально возможного
* @param arr - массив
* @param size - размер массива
* @param min - минимально возможный элемент массива
* @param max - максимально возможный элемент массива
*/
void getManual(int* arr, const size_t size, const int min, const int max);

/**
* @brief Заполняет массив случайнами элементами, c учётом максимально и минимально возможного
* @param arr - массив
* @param size - размер массива
* @param min - минимально возможный элемент массива
* @param max - максимально возможный элемент массива
*/
void getRandom(int* arr, const size_t size, const int max, const int min);

/**
* @brief Выводит все элементы массива на экран
* @param arr - массив
* @param size - размер массива
*/
void defPrintArr(int* arr, const size_t size);

/**
* @brief Копирует все элементы массива в новый
* @param arr - массив
* @param size - размер массива
* @return Новый массив, идентичный старому
*/
int* defcopyArr(const int* arr, const size_t size);

/**
* @brief Точка входа в программу
* @return Возвращает 0, если программа была выполнена корректно, иначе 1
*/
int main(void)
{
	system("chcp 1251");

	printf("Введите размер массива: ");
		size_t size = (size_t)getValid();
	checkValueForN(size);

	int* A = malloc(sizeof(int) * size);
	if (A == NULL)
	{
		printf("Error");
		exit(1);
	}

	printf("Введите диапазон, в котором будут задаваться числа массива: \n");
		int min = getValid();
		int max = getValid();
	defCheckMinMax(min, max);

	printf("\nКак будет заполнен массив?\n %d - Ручной ввод\n %d - Автоматический ввод\n",choiseOne,choiseTwo);
	int choise = getValid();

	switch (choise)
	{
	case choiseOne:
		getManual(A, size, min, max);
		break;

	case choiseTwo:
		getRandom(A, size, min, max);
		break;

	default:
		printf("Error");
		free(A);
		exit(1);
	}

	defPrintArr(A, size);
	int* copyA = defcopyArr(A, size);

	printf("\nКакие будут преобразования?\n%d - Найти сумму четных отрицательных элементов\n%d - Вывести индексы тех элементов, значения которых кратны 3 и 6\n%d - Заменить нулями элементы массива между минимальным и максимальным, кроме их самих\n", taskOne, taskTwo, taskThree);
	int second_choise = getValid();
	
	switch (second_choise)
	{
	case taskOne:
		printf("\nСумма чётных отрицательных элементов = %d\n", defForTask1(copyA, size));
		break;

	case taskTwo:
		defForTask2(copyA, size);
		break;

	case taskThree:
		defForTask3(copyA, size);
		break;

	default:
		printf("Error");
		free(A);
		free(copyA);
		exit(1);
	}

	free(A);
	free(copyA);

	return 0;
}

int getValid()
{
	int valid = 0;
	if (!scanf_s("%d", &valid))
	{
		printf("Error");
		exit(1);
	}
	return valid;
}

void checkValue(const int input, const int min, const int max)
{
	if (input > max || input < min)
	{
		printf("Error\nЧисло должно лежать в промежутке [%d;%d]",min,max);
		exit(1);
	}
}

void getManual(int* arr, const size_t size, const int min, const int max)
{
	printf("\nВведи %d элемент-а(ов) массива:\n", size);
	for (size_t i = 0; i < size; i++)
	{
		int num = getValid();
		checkValue(num, min, max);
		printf("A[%d] = %d\n", i, num);
		arr[i] = num;
	}
}

void defCheckMinMax(const int min, const int max)
{
	if (min >= max)
	{
		printf("Error\n Неправильно указан диапазон");
		exit(1);
	}
}

void getRandom(int* arr, const size_t size, const int min, const int max)
{
	srand(time(NULL));

	for (size_t i = 0; i < size; i++)
	{
		int numm = (rand() % (max - min + 1)) + min;
		arr[i] = numm;
	}
}

void defPrintArr(int* arr, const size_t size)
{

	printf("\nВведённый массив: \n");
	for (size_t i = 0; i < size; i++)
	{
		printf("%d\n", arr[i]);
	}
}

void checkValueForN(int input)
{
	if (input < 1)
	{
		printf("Error\nЧисло должно быть не меньше 2");
		exit(1);
	}
}

int defForTask1(int* arr, const size_t size)
{
	int summ = 0;
	for (size_t i = 0; i < size; i++)
	{
		if ((arr[i] % 2 == 0) && (arr[i] < 0))
		{
			summ += arr[i];
		}
	}
	return summ;
}

void defForTask2(int* arr, const size_t size)
{
	_Bool chek = 0;

	printf("\nИндексы элементов, значения которых кратны 3 и 6: ");
	for (size_t i = 0; i < size; i++)
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

int defMAXX(int* arr, const size_t size)
{
	int maxx = arr[0];
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] > maxx)
		{
			maxx = arr[i];
		}
	}
	return maxx;
}

int* defcopyArr(const int* arr, const size_t size)
{
	int* copyArr = malloc(sizeof(int) * size);
	for (size_t i = 0; i < size; i++)
	{
		copyArr[i] = arr[i];
	}
	return copyArr;
}

int defMINN(int* arr, const size_t size)
{
	int minn = arr[0];
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] < minn)
		{
			minn = arr[i];
		}
	}
	return minn;
}

void defForTask3(int* arr, const size_t size)
{
	const int defmax = defMAXX(arr, size);
	const int defmin = defMINN(arr, size);
	printf("\nНовый массив: \n");
	for (size_t i = 0; i < size; i++)
	{
		if (!(arr[i] == defmin || arr[i] == defmax))
		{
			arr[i] = 0;
		}
		printf("%d\n", arr[i]);
	}
}
