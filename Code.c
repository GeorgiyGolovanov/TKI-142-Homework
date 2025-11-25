#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<float.h>

/**
* @brief Рассчитывает сумму n членов последовательности
* @param n - число членов последовательности
* @return Рассчитанное значение
*/
double defSumm(const int n);

/**
* @brief Рассчитывает рекурентной фоормулы с заданной точностью e
* @param e - точность рассчёта
* @return Рассчитанное значение
*/
double defSummE(const double e);

/**
* @brief Считывает значение, введённое с клавиатуры, с проверкой ввода
* @return Считанное значение
*/
double defValid();

/**
 * @brief Рассчитывает коэффициент рекуррентного выражения
 * @param i - текущий индекс
 * @return Рассчитанное значение коэффициента
 */
double getRecurent(const int i);

/**
* @brief Проверяет переменную на условие
* @param input - значение проверяемой переменной
*/
void CheckValue(const double input);

/**
* @brief Точка входа в программу
* @return Возвращает 0, если программа была выполнена корректно, иначе 1
*/
int main(void)
{
	system("chcp 1251");

	printf("Введите целое число n: ");
		int n = (int) defValid();
			CheckValue(n);

	printf("Сумма первых %d членов последовательности = %.10lf\n\n", n, defSumm(n));

	printf("Введите число e: ");
		double e = defValid();
			CheckValue(e);

	printf("Сумма членов последовательности с точностью %.2lf = %.10lf\n", e, defSummE(e));

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

void CheckValue(const double input)
{
	if (!(input > 0))
	{
		printf("Error\n");
		exit(1);
	}
}

double defSumm(const int n)
{
	double current = -0.5;
	double result = current;
	for (int i = 1; i < n; i++)
	{
		current *= getRecurent(i);
		result += current;
	}
	return result;
}

double defSummE(const double e)
{
	double current = -0.5;
	double result = 0;
	for (int i = 1; fabs(current) > e; i++)
	{
		result += current;
		current *= getRecurent(i);
	}
	return result;
}

double getRecurent(const int i)
{
	return -1.0 * (i+1)/(pow(i,2) + 2*i);
}
