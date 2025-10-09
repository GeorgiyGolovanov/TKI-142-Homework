#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<float.h>


/**
* @brief Рассчитывает значение функции в точке
* @param x - точка
* @return Рассчитанное значение
*/
const double function(const double x);

/**
* @brief Рассчитывает значение рекурентной формулы с заданной точностью e
* @param e - точность рассчёта 
* @param x - значение параметра x, участвующее в расcчёте
* @return Рассчитанное значение
*/
double defSummE(const double e, const double x);

/**
* @brief Считывает значение, введённое с клавиатуры, с проверкой ввода
* @return Считанное значение
*/
double defValid();

/**
 * @brief Рассчитывает коэффициент рекуррентного выражения
 * @param i - текущий индекс
 * @param x - значение параметра x, участвующее в раcсчёте
 * @return Рассчитанное значение коэффициента
 */
double getRecurent(const int i, const double x);

/**
* @brief Проверяет переменную на условие
* @param input - значение проверяемой переменной
*/
void CheckValue(const double input);

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

	printf("Введите число e: ");
	double e = defValid();
	CheckValue(e);

	printf("Введите начальное значение: ");
	double start = defValid();
	printf("Введите конечное значение: ");
	double end = defValid();
	checkEndStart(start, end);

	printf("Введите шаг: ");
	double step = defValid();
	checkStep(step);

	printf("%-10s%-25s%-10s\n", "x", "f(x)", "Summ(x)");
	for (double x = start; x <= end + DBL_EPSILON; x += step - DBL_EPSILON)
	{
		if (checkX(x))
		{
			printf_s("%-10.2lf%-25.4lf%-10.4lf\n", x, function(x), defSummE(e,x));
		}
		else
		{
			printf_s("%-10.2lf%-25s%-10s\n", x, "Функция неопределена", "Сумма ряда неопределена");
		}

	}

	return 0;
}

const double function(const double x)
{
	return 1.0/2*log(x);
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

double defSummE(const double e, const double x)
{
	double current = (x-1)/(x+1);
	double result = 0;
	for (int i = 0; fabs(current) > e; i++)
	{
		result += current;
		current *= getRecurent(i,x);
	}
	return result;
}

void checkEndStart(const double start, const double end)
{
	if (!(start < end))
	{
		printf("Error\n Значения не должны совпадать\n Значение начала не может быть больше значения конца\n");
		exit(1);
	}
}

void checkStep(const double step)
{
	if (step <= DBL_EPSILON)
	{
		printf("Error\n Шаг должен быть больше 0\n");
		exit(1);
	}
}

double getRecurent(const int i, const double x)
{
	return (2 * i * pow(x, 2) + pow(x, 2) - 4 * i * x - 2 * x + 2 * i + 1) / (2 * i * pow(x, 2) + 4 * i * x + 2 * i + 3 * pow(x, 2) + 6 * x + 3);
}

_Bool checkX(const double x)
{
	return x > 0;
}
