#include <iostream>
#include <cmath>
#include <iomanip>
#include <windows.h>
using namespace std;

double calc_z1(double ang);
double calc_z2(double ang);
void display(double num1, double num2);

const double PI = 3.14159265358979323846;

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
	double arg1 = (3.0 / 8.0) * PI - (ang / 4.0);
	double arg2 = (11.0 / 8.0) * PI + (ang / 4.0);
	double first_slag = pow(cos(arg1), 2);
	double second_slag = pow(cos(arg2), 2);
	return first_slag - second_slag;
	
}

double calc_z2(double ang) {
	return (sqrt(2) / 2) * sin(ang / 2);
}

void display(double num1, double num2) {
	cout << "Результаты вычислений: " << '\n';
	cout << fixed << setprecision(6);
	cout << "z1 = " << num1 << '\n';
	cout << "z2 = " << num2 << '\n';
} 