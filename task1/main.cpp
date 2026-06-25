#include <iostream>
#include <cmath>
#include <windows.h>
using namespace std;

double calc_z1(double ang);
double calc_z2(double ang);
void display(double num1, double num2);

const double PI = 3.141592;

int main() {
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	double z1 = 0.0, z2 = 0.0, alpha = 0.0;
	cout << "Введите угол (в рад.): ";
	cin >> alpha;

	z1 = calc_z1(alpha);
	z2 = calc_z2(alpha);

	display(z1, z2);

	return 0;
}

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