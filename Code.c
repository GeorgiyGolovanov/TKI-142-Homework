#include<stdio.h>
#include<math.h>
#include<stdlib.h>

/**
* @brief Перевод числа в десятичную систему счисления
* @param a - число
* @param x - система счисления, в которой записано число
* @return Рассчитанное значение
*/
const double Perevod(const double a, const double x);

/**
* @brief Рассчитывает значение первой функции
* @param a - значение параметра a
* @param x - значение параметра x
* @return Рассчитанное значение
*/
const double F1(const double a, const double x);

/**
* @brief Рассчитывает значение второй функции
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
* @param value - значение проверяемой переменной
*/
void checkValue(int value);

/**
* @brief Точка входа в программу
* @return Возвращает 0, если программа была выполнена корректно, иначе 1
*/
int main(void)
{
	system("chcp 1251");

	const double a = 1.5;
	printf("Введи число X (большее 6):");
	int x = defValid();
	checkValue(x);
	
	if (x * a < 1)
	{
		printf("y = %.6lf", F1(a, x));
	}
	else
	{
		printf("y = %.6lf", F2(a, x));
	}

	return 0;
}

const double Perevod(const double a, const double x)
{
	int cell = (int)a;
	int newdrob = 0;
	double drob = 0;
	double systemsch = 0;

	drob = a - cell;

	newdrob = drob * 10;
	systemsch = cell * pow(x, 0) + newdrob * pow(x, -1);

	return systemsch;
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

void checkValue(const int value)
{
	if (value < 6)
	{
		printf("Error\n");
		abort();
	}
}

const double F1(const double a, const double x)
{
	return Perevod(a, x) - log10(a * x);
}

const double F2(const double a, const double x)
{
	return Perevod(a, x) + log10(a * x);
}
