#include "mod.h"


const double PI = 3.141592;

double calc_z1(double ang) {
	double k = ang / 4;
	return pow(cos((3 / 8) * PI - k), 2) - pow(cos((11 / 8) * PI + k), 2);
}

double calc_z2(double ang) {
	return (sqrt(2) / 2) * sin(ang / 2);
}

void display(double num1, double num2) {
	cout << "Результаты вычислений: " << '\n';
	cout << "z1 = " << num1 << '\n';
	cout << "z2 = " << num2 << '\n';
} 