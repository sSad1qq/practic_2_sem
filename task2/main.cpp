#include "mod.h"

int main() {
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	double a = 0.0, b = 0.0, c = 0.0, x_begin = 0.0, x_last = 0.0, dx = 0.0, x = 0.0;

	cout << "Введите коэффициенты a, b, c: ";
	cin >> a >> b >> c;

	double k[3] = { a, b, c };

	cout << "Введите начальное значение x_begin: ";
	cin >> x_begin;

	cout << "Введите конечное значение x_last: ";
	cin >> x_last;

	cout << "Введите шаг dx: ";
	cin >> dx;

	display_result(x_begin, x_last, dx, k);

	return 0;
}