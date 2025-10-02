#include<stdio.h>
#include<math.h>
#include<stdlib.h>

/**
* @brief Рассчитывает значение функции в точке
* @param x - точка
* @return Рассчитанное значение
*/
const double Function(const double x);

/**
* @brief Считывает значение, введённое с клавиатуры, с проверкой ввода
* @return Считанное значение
*/
double defValid();

/**
* @brief Проверяет значения на условие
* @param end - значение конца промежутка
* @param start - значение начала промежутка
*/
void checkEndStart(const double start, const double end);

/**
* @brief Проверяет значение на условие
* @param step - значение шага
*/
void checkStep(const double step);

/**
* @brief Проверяет заначение на условие
* @param x - значение параметра x
* @return Возвращает 0 или 1 в зависимости от истинности выражения
*/
_Bool checkX(const double x);

/**
* @brief Точка входа в программу
* @return Возвращает 0, если программа была выполнена корректно, иначе 1
*/
int main(void)
{
	system("chcp 1251");

	printf("Введите начальное значение: ");
		double start = defValid();
	printf("Введите конечное значение: ");
		double end = defValid();
	checkEndStart(start, end);

	printf("Введите шаг: ");
		double step = defValid();
	checkStep(step);


	int countSTEP = (int)((end - start) / step);
	int counter;

	printf("%-9s %s\n", "x", "f(x)");
	for (counter = 0; counter <= countSTEP; counter++)
	{
		double x = start + step * counter;
		if (checkX(x))
		{
			printf_s("%-10.2lf%.4lf\n", x, Function(x));
		}
		else
		{
			printf_s("%-10.2lf%s\n", x, "Функция неопределена");
		}
		
	}

	return 0;
}

const double Function(const double x)
{
	return sqrt(1 - x) - cos(sqrt(1 - x));
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

void checkEndStart(const double start, const double end)
{
	if (start < end){}
	else
	{
		printf("Error\n Значения не должны совпадать\nЗначение начала не может быть больше конца\n");
		abort();
	}
}

void checkStep(const double step)
{
	if (step>0){}
	else
	{
		printf("Error\n Шаг должен быть больше 0\n");
		abort();
	}
}

_Bool checkX(const double x)
{
	return !(x > 1);
}
