#include<stdio.h>
#include<math.h>

/**
* @brief Вычисляет сопротивление по формуле
* @param S - площадь поперечнего сечения
* @param l - длинна проводника
* @param Al - удельное сопротивление алюминия
* @return Рассчитанне значение
*/
double defResist(const double S, const double l, const double Al);

/**
* @brief Точка входа в программу
* @return Возвращает 0, если программа была выполнена корректно, иначе 1
*/
int main(void)
{
	system("chcp 1251");

	const double Al = 0.028;
	double S;
	double l;
	
	printf("Введите площадь поперечнего сечения проводника в квадратных мм: ");
		scanf_s("%lf", &S);
	
	printf("Введите длинну проводника в метрах: ");
		scanf_s("%lf", &l);

	printf("Сопротивление проводника = %.6lf Ом\n", defResist(S,l,Al));

	return 0;
}

double defResist(const double S, const double l, const double Al)
{
	return Al * l / S;
}
