#include "mod.h"

double F(double k[], double x) {
	double a, b, c;
	a = k[0];
	b = k[1];
	c = k[2];

	if (x < 5 && c != 0) {
		return -a * pow(x, 2) - b;
	}
	else if (x > 5 && c == 0) {
		return (x - a) / x;
	}
	else {
		return -x / c;
	}

}

void display_result(double x_begin, double x_last, double dx, double k[]) {
	const int w = 14;
	string sep = "+" + string(w, '-') + "+" + string(w, '-') + "+";

	cout << sep << '\n';
	cout << "|" << setw(w) << "x"    << "|" << setw(w) << "F(x)" << "|\n";
	cout << sep << '\n';

	cout << fixed << setprecision(4);
	for (double x = x_begin; x <= x_last + dx * 1e-9; x += dx) {
		double result = F(k, x);
		cout << "|" << setw(w) << x << "|" << setw(w) << result << "|\n";
	}

	cout << sep << '\n';
}