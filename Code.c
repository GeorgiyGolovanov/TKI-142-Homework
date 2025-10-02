#include<stdio.h>
#include<math.h>
#include<stdlib.h>

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
* @brief Проверяет значение на условие
* @param limit - лимит расчёта рекурентной функции
*/
void checkLimit(const int limit);

/**
* @brief Проверяет заначение на условие
* @param x - значение параметра x
* @return Возвращает 0 или 1 в зависимости от истинности выражения
*/
_Bool checkX(const double x);

/**
* @brief Рассчитывает значение функции в точке
* @param x - точка
* @return Рассчитанное значение
*/
double Function(const double x);

/**
* @brief Рассчитывает значение по заданной формуле
* @param x - переменная x
* @param limit - лимит рекурсии
* @return Рассчитанное значение
*/
double Sum(const double x, const int limit);

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

	printf("Введите лимит для рекурентной формуле (чем больше значение - тем точнее расчёт): ");
		int limit = defValid();
	checkLimit(limit);

	int CountStep = (int)((end - start) / step);
	int Counter;

	printf("%-10s%-30s%-10s\n", "x", "f(x)", "Sum");
	for (Counter = 0; Counter <= CountStep; Counter++)
	{
		double x = start + step * Counter;
		if (checkX(x))
		{
			printf("%-10.2lf%-30.4lf%-10.4lf\n", x, Function(x), Sum(x, limit));
		}
		else
		{
			printf("%-10.2lf%-30s%-10.4lf\n", x, "Функция неопределена", Sum(x, limit));
		}
	}
	return 0;
}

double Function(const double x)
{
	return 1.0 / 2 * log(x);
}

double Sum(const double x, const int limit)
{
	double summ = 0;
	int n = 0;
	for (n; n <= limit; n++)
	{
		summ += 1.0 / (2 * n + 1) * (pow((x - 1) / (x + 1), 2 * n + 1));
	}
	return summ;
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
	if (start < end) {}
	else
	{
		printf("Error\n Значения не должны совпадать\nЗначение начала не может быть больше конца\n");
		abort();
	}
}

void checkStep(const double step)
{
	if (step > 0) {}
	else
	{
		printf("Error\n Шаг должен быть больше 0\n");
		abort();
	}
}

_Bool checkX(const double x)
{
	return (x > 0);
}

void checkLimit(const int limit)
{
	if (limit < 10)
	{
		printf("Error\nЗначение слишком маленькое или недопустимое");
		abort();
	}
}
