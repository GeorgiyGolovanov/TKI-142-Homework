#define _USE_MATH_DEFINES
#include<math.h>
#include<stdio.h>

/**
* @brief Рассчитывает значение 3-ей стороны треугольника (по теореме косинусов)
* @param a - значение параметра a (первая сторона треугольника)
* @param b - значение параметра b (вторая сторона треугольника)
* @param c - значение параметра c (угол между сторонами)
* @return Рассчитанное значение
*/
double defThirdSide(const double a, const double b, const double c);

/**
* @brief Рассчитывает значение площади треугольника (через синус и две стороны)
* @param a - значение параметра a (первая сторона треугольника)
* @param b - значение параметра b (вторая сторона треугольника)
* @param c - значение параметра c (угол между сторонами)
* @return Рассчитанное значение
*/
double defSquare(const double a, const double b, const double c);

/**
* @brief Рассчитывает значение радиуса описанной окружности
* @param a - значение параметра a (первая сторона треугольника)
* @param b - значение параметра b (вторая сторона треугольника)
* @param c - значение параметра c (угол между сторонами)
* @return Рассчитанное значение
*/
double defRadius(const double a, const double b, const double c);

/**
* @brief Точка входа в программу
* @return Возвращает 0, если программа была выполнена корректно, иначе 1
*/
int main(void)
{
	system("chcp 1251");

	double firstSide;
	double secondSide;
	double Angle;

	printf("Введите длину первой стороны треугольника ");
		scanf_s("%lf", &firstSide);

	printf("Введите длину второй стороны треугольника ");
		scanf_s("%lf", &secondSide);

	printf("Введите угол между введёными выше сторонами ");
		scanf_s("%lf", &Angle);
	
	printf("Третья сторона = %.6lf\n", defThirdSide(firstSide, secondSide, Angle));
	printf("Площадь = %.6lf\n", defSquare(firstSide, secondSide, Angle));
	printf("Радиус описанной окружности = %.6lf\n", defRadius(firstSide,secondSide,Angle));

	return 0;
}

double defThirdSide(const double a, const double b, const double c)
{
	return sqrt(pow(a, 2) + pow(b, 2) - 2 * a * b * cos(c / 180 * M_PI));
}

double defSquare(const double a, const double b, const double c)
{
	return a * b * sin(c / 180 * M_PI) * (1.0 / 2);
}

double defRadius(const double a, const double b, const double c)
{
	return (a * b * defA(a, b, c)) / (4*defB(a, b, c));
}
