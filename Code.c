#include<stdio.h>
#include<math.h>
#include<stdlib.h>

/**
* @brief Считывает значение, введённое с клавиатуры, с проверкой ввода
* @return Считанное значение
*/
double defValid();

/**
* @brief Проверяет переменную на условие
* @param A - значение параметра A
* @param B - значение параметра B
* @param C - значение параметра C
* @return Если хотя бы одно условие верно, возвращает 1, иначе 0
*/
_Bool defPlus(const double A, const double B, const double C);

/**
* @brief Точка входа в программу
* @return Возвращает 0, если программа была выполнена корректно, иначе 1
*/
int main(void)
{
	system("chcp 1251");

	printf("Введите число A: ");
	double A = defValid();

	printf("Введите число B: ");
	double B = defValid();

	printf("Введите число C: ");
	double C = defValid();

	if (defPlus(A,B,C))
	{
		printf_s("Есть положительная сумма");
	}
	else
	{
		printf_s("Положительной суммы нет");
	}

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

_Bool defPlus(const double A, const double B, const double C)
{
	return A + B > 0 || A + C > 0 || C + B > 0;
}
