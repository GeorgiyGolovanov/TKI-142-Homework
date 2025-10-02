#include<stdio.h>
#include<math.h>
#include<stdlib.h>

/**
* @brief Рассчитывает значение по заданной формуле
* @param k - постоянно растущее число (до числа n)
* @return Рассчитанное значение
*/
double defSum(const int k);

/**
* @brief Рассчитывает факториал числа
* @param k - число, факториал которого находится
* @return Рассчитанное значение
*/
double Factorial(const int k);

/**
* @brief Считывает значение, введённое с клавиатуры, с проверкой ввода
* @return Считанное значение
*/
double defValid();

/**
* @brief Проверяет переменную на условие
* @param input - значение проверяемой переменной
*/
int CheckValue(input);

/**
* @brief Точка входа в программу
* @return Возвращает 0, если программа была выполнена корректно, иначе 1
*/
int main(void)
{
	system("chcp 1251");

	int k = 1;
	double summ1 = 0;
	double summ2 = 0;

	printf("Введите целое число n (конечное значение суммы): ");
		int n = defValid();
	CheckValue(n);

	printf("Введите число e: ");
		double e = defValid();

	for (k; k <= n; k++)
	{
		summ1 += defSum(k);

		if (fabs(defSum(k)) < e)
		{
			continue;
		}
		else
		{
			summ2 += defSum(k);
		}
	}

	printf("Сумма первых %d членов = %.20lf\n", n, summ1);
	printf("Сумма первых %d членов, по модулю не меньших чем %lf = %.10lf\n", n, e, summ2);

	return 0;
}

double defValid()
{
	double valid = 0;
	if (!scanf_s("%lf", &valid))
	{
		printf("Error\n");
		abort();
	}

	return valid;
}

int CheckValue(input)
{
	if (input < 1)
	{
		printf("Error\n Число n должно быть не меньше 1\n");
		abort();
	}
}

double defSum(const int k)
{
	return pow(-1, k) * k / Factorial(k + 1);
}

double Factorial(const int k)
{
	if (k <= 1)
	{
		return 1;
	}
	else
	{
		return k * Factorial(k - 1);
	}
}
