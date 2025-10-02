#include<stdio.h>
#include<math.h>
#include<stdlib.h>

/**
* @brief Считывает значение, введённое с клавиатуры, с проверкой ввода
* @return Считанное значение
*/
double defValid();

/**
* @brief Проводит рассчёт по первой формуле
* @param A - значение параметра A
* @param N - значение параметра N
* @return Считанное значение
*/
const double defFirstF(const double A, const double N);

/**
* @brief Проводит рассчёт по второй формуле
* @param A - значение параметра A
* @param N - значение параметра N
* @return Считанное значение
*/
const double defSecondF(const double A, const double N);

/**
* @brief Проводит рассчёт по третьей формуле
* @param A - значение параметра A
* @param N - значение параметра N
* @return Считанное значение
*/
const double defThirdF(const double A, const double N);

/**
@brief FirstF - первая формула
@brief SecondF - вторая формула
@brief ThirdF - третья формула
*/
enum {FirstF, SecondF, ThirdF};

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

	printf("Выберите формулу вычисления: %d-A*N, %d-A*2N, %d-A*3N\n",FirstF,SecondF,ThirdF);
	int choise = (int)defValid();

	switch (choise)
	{
	case FirstF:
		printf("Полученное значение = %.02lf\n", defFirstF(A,N));
		break;

	case SecondF:
		printf("Полученное значение = %.02lf\n", defSecondF(A, N));
		break;

	case ThirdF:
		printf("Полученное значение = %.02lf\n", defThirdF(A, N));
		break;

	default:
		printf("Error");
		abort();
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

const double defFirstF(const double A, const double N)
{
	return A * N;
}

const double defSecondF(const double A, const double N)
{
	return A * 2 * N;
}

const double defThirdF(const double A, const double N)
{
	return A * 3 * N;
}
