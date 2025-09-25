#include<stdio.h>
#include<math.h>
#include<stdlib.h>

/**
* @brief Считывает значение, введённое с клавиатуры, с проверкой ввода
* @return Считанное значение
*/
double defValid();

/**
* @brief Рассчитывает значение по выбранной формуле
* @param A - значение параметра A
* @param N - значение параметра N
* @return Рассчитанное значение
*/
double СhoiceFormulas(const double A, const double N, const int s);

/**
* @brief Точка входа в программу
* @return Возвращает 0, если программа была выполнена корректно, иначе 1
*/
int main(void)
{
	system("chcp 1251");

	printf("Введи число A: ");
	double A = defValid();

	printf("Введи число N: ");
	double N = defValid();

	printf("Выберите формулу вычисления (Введите цифру от 1 до 3)\n\
(домножить число A на N; домножить число A на 2N; домножить число A на 3N): ");
	int s = defValid();

	printf("Полученное значение = %.02lf\n", СhoiceFormulas(A, N, s));

	return 0;
}

double defValid()
{
	double valid = 0;
	if (!scanf_s("%lf",&valid))
	{
		printf("Error\n");
		abort();
	}

	return valid;
}

double СhoiceFormulas(const double A, const double N, const int s)
{
	if (s == 1)
	{
		return A * N;
	}
	else if (s == 2)
	{
		return A * 2 * N;
	}
	else if (s == 3)
	{
		return A * 3 * N;
	}
	else
	{
		printf("Error\n");
		abort();
	}
}
