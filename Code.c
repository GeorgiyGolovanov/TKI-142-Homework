#include<stdio.h>
#include<math.h>
#include<stdlib.h>

/**
* @brief Считывает значение, введённое с клавиатуры, с проверкой ввода
* @return Считанное значение
*/
double defValid();

int main(void)
{
	system("chcp 1251");

	printf("Введите число A: ");
	double A = defValid();

	printf("Введите число B: ");
	double B = defValid();

	printf("Введите число C: ");
	double C = defValid();
	
	double AB = (A + B);
	double AC = (A + C);
	double BC = (B + C);
	double ABC = (A + B + C);

	if (AB > 0 || AC > 0 || BC > 0 || ABC > 0)
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
