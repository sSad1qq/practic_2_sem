#include "mod.h"

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