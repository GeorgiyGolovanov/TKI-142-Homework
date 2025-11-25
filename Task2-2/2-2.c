#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<float.h>

/**
* @brief Рассчитывает значение первой функции
* @param a - значение параметра a
* @param x - значение параметра x
* @return Рассчитанное значение
*/
const double F1(const double a, const double x);

/**
* @brief Рассчитывает значение первой функции
* @param a - значение параметра a
* @param x - значение параметра x
* @return Рассчитанное значение
*/
const double F2(const double a, const double x);

/**
* @brief Считывает значение, введённое с клавиатуры, с проверкой ввода
* @return Считанное значение
*/
double defValid();

/**
* @brief Проверяет переменную на условие
* @param x - значение проверяемой переменной
* @return 0 если условие ложно, иначе 1
*/
_Bool checkX(const double x);

/**
* @brief Точка входа в программу
* @return Возвращает 0, если программа была выполнена корректно, иначе 1
*/
int main(void)
{
	system("chcp 1251");

	const double a = 1.5;
	printf("Введи число X: ");
	double x = defValid();
	
	if (checkX(x))
	{
		if (x * a < 1)
		{
			printf("y = %.6lf", F1(a, x));
		}
		else
		{
			printf("y = %.6lf", F2(a, x));
		}
	}
	else
	{
		printf("Функция не определена");
	}
	
	return 0;
}

double defValid()
{
	double valid = 0;
	if (!scanf_s("%lf", &valid))
	{
		printf("Error\n");
		exit(1);
	}
	return valid;
}

_Bool checkX(const double x)
{
	return (x>0);
}

const double F1(const double a, const double x)
{
	return a * x - log10(a * x);
}

const double F2(const double a, const double x)
{
	return a * x + log10(a * x);
}
