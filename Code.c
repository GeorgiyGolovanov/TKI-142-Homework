#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<stdbool.h>

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
* @brief Создаёт новый массив согласно условию 1
* @param arr - массив
* @param size - размер массива
*/
void defForTask1( int* arr, const size_t size);

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
int* defForTask3(const int* arr, const size_t size);

/**
* @brief Находит максимальное значение массива
* @param arr - массив
* @param size - размер массива
* @return Возвращaет максимальный элемент массива
*/
int defMAXX(const int* arr, const size_t size);

/**
* @brief Проверяет, есть ли в числе единица
* @param input - проверяемое число
* @return Возвращaет 1 или 0 в зависимости от верности условия
*/
bool findOne(int input);

/**
* @brief Находит количество чисел массива, в которых встречается единица
* @param arr - массив
* @param size - размер массива
* @return Возвращaет количество элементов, удовлетворяющих условию
*/
const int defcountOne(const int* arr, const size_t size);

/**
@brief choiseOne - первый выбор (Ручное заполнение массива)
@brief  choiseTwo - второй выбор (Автоматическое заполнение массива)
@brief  taskOne - выполнение первого задания
@brief  taskTwo - выполнение второго задания
@brief  taskThree - выполнение третьего задания
*/
enum { choiseOne = 1, choiseTwo, taskOne = 1, taskTwo, taskThree };

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
* @brief Проверяет, удалось ли выделить память для массива
* @param arr - массив
*/
void checkMemory(const int* arr);

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
	checkMemory(A);

	printf("Введите диапазон, в котором будут задаваться числа массива: \n");
	int min = getValid();
	int max = getValid();
	defCheckMinMax(min, max);
	printf("Числа массива будут в диапазоне [%d,%d]", min, max);

	printf("\nКак будет заполнен массив?\n %d - Ручной ввод\n %d - Автоматический ввод\n", choiseOne, choiseTwo);
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
		fprintf(stderr,"Error");
		free(A);
		exit(1);
	}

	defPrintArr(A, size);
	int* copyA = defcopyArr(A, size);
	checkMemory(copyA);

	int* AforTask3 = defForTask3(copyA, size);

	printf("\nКакие будут преобразования?\n%d - Заменить максимальный элемент массива на противоположный по знаку\n%d - Вставить максимальный элемент массива после всех элементов, в которых есть цифра 1\n%d - Из элементов массива C сформировать массив A той же размерности по правилу: первые 10 элементов находятся по формуле: A[i]=C[i]+i, иначе A[i]=C[i]-i.\n", taskOne, taskTwo, taskThree);
	int second_choise = getValid();

	switch (second_choise)
	{
	case taskOne:
		defForTask1(copyA, size);
		break;

	case taskTwo:
		defForTask2(copyA, size);
		break;

	case taskThree:
		defPrintArr(AforTask3, size);
		break;

	default:
		fprintf(stderr,"Error");
		free(A);
		free(copyA);
		free(AforTask3);
		exit(1);
	}

	free(A);
	free(copyA);
	free(AforTask3);

	return 0;
}

int getValid()
{
	int valid = 0;
	if (!scanf_s("%d", &valid))
	{
		fprintf(stderr,"Error");
		exit(1);
	}
	return valid;
}

void checkValue(const int input, const int min, const int max)
{
	if (input > max || input < min)
	{
		fprintf(stderr,"Error\nЧисло должно лежать в промежутке [%d;%d]", min, max);
		exit(1);
	}
}

void getManual(int* arr, const size_t size, const int min, const int max)
{
	checkMemory(arr);

	printf("\nВведи %d элемент-а(ов) массива:\n", size);
	for (size_t i = 0; i < size; i++)
	{
		int num = getValid();
		checkValue(num, min, max);
		printf("A[%zu] = %d\n", i, num);
		arr[i] = num;
	}
}

void defCheckMinMax(const int min, const int max)
{
	if (min >= max)
	{
		fprintf(stderr,"Error\n Неправильно указан диапазон");
		exit(1);
	}
}

void getRandom(int* arr, const size_t size, const int min, const int max)
{
	checkMemory(arr);
	srand(time(NULL));

	for (size_t i = 0; i < size; i++)
	{
		int numm = (rand() % (max - min + 1)) + min;
		arr[i] = numm;
	}
}

void defPrintArr(const int* arr, const size_t size)
{
	checkMemory(arr);

	printf("\nВведённый массив: \n");
	for (size_t i = 0; i < size; i++)
	{
		printf("%d\n", arr[i]);
	}
}

void checkValueForN(const int input)
{
	if (input < 1)
	{
		fprintf(stderr,"Error\nЧисло должно быть не меньше 1");
		exit(1);
	}
}

void defForTask1(int* arr, const size_t size)
{
	checkMemory(arr);

	const int defmax = defMAXX(arr, size);
	printf("\nНовый массив: \n");
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] == defmax)
		{
			arr[i] = -1 * defmax;
		}

		printf("%d\n",arr[i]);
	}
}

void defForTask2(const int* arr, const size_t size)
{
	checkMemory(arr);

	const int max = defMAXX(arr, size);
	size_t newsize = size + defcountOne(arr, size);

	int* newarr = malloc(sizeof(int) * newsize);
	checkMemory(newarr, newsize);
	
	printf("\nНовый массив: \n");
	size_t j = 0;
	for (size_t i = 0; i < newsize; i++)
	{
		newarr[j++] = arr[i];
		if (findOne(arr[i]) == 1)
		{
			newarr[j++] = max;
		}

		printf("%d\n", newarr[i]);
	}
}

int* defForTask3(const int* arr, const size_t size)
{
	checkMemory(arr);

	int* newarr = malloc(sizeof(int) * size);
	checkMemory(newarr, size);

	for (size_t i = 0; i < size; i++)
	{
		if (i < 10)
		{
			newarr[i] = arr[i] + i;
		}
		else
		{
			newarr[i] = arr[i] - i;
		}
	}

	return newarr;
}

int defMAXX(const int* arr, const size_t size)
{
	checkMemory(arr);

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
	checkMemory(arr);

	int* copyArr = malloc(sizeof(int) * size);
	checkMemory(copyArr, size);

	for (size_t i = 0; i < size; i++)
	{
		copyArr[i] = arr[i];
	}
	return copyArr;
}

bool findOne(int input)
{
	input = abs(input);
	bool check = 0;
	if (input == 0)
	{
		return 0;
	}
	else
	{
		while ((int)(log10(input)) >= 0)
		{
			if (input == 1 || input%10 == 1)
			{
				check = 1;
				return 1;
			}
			input = input / 10;
		}
		if (check = 0)
		{
			return 0;
		}
	}
}

const int defcountOne(const int* arr, const size_t size)
{
	checkMemory(arr);

	int count = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (findOne(arr[i])==1)
		{
			count += 1;
		}
	}
	return count;
}

void checkMemory(const int* arr)
{
	if (arr == NULL)
	{
		printf("Error");
		exit(1);
	}
}
