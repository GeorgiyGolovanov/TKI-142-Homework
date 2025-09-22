#include<stdio.h>
#include<math.h>

/**
* @brief Рассчитывает значение функции A
* @param X - значение параметра X
* @param Y - значение параметра Y
* @param Z - значение параметра Z
* @return Рассчитанное значение
*/
double defA(const double X, const double Y, const double Z);

/**
* @brief Рассчитывает значение функции B
* @param X - значение параметра X
* @param Y - значение параметра Y
* @param Z - значение параметра Z
* @return Рассчитанное значение
*/
double defB(const double X, const double Y, const double Z);

/**
* @brief Точка входа в программу
* @return Возвращает 0, если программа была выполнена корректно, иначе 1
*/
int main(void)
{
	const double X = 0.5;
	const double Y = 0.05;
	const double Z = 0.7;

	printf("A = %.6f\nB = %.6f", defA(X, Y, Z), defB(X, Y, Z));

	return 0;
}

double defA(const double X, const double Y, const double Z)
{
	return (pow(X, 2) * (X + 1)) / (Y - pow(sin(X + Z),2));
}

double defB(const double X, const double Y, const double Z)
{
	return sqrt((X * Y) / Z) + pow(cos(pow((X + Y),2)), 2);
}
