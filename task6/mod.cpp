#include "mod.h"

straight* create_arr(const int k) {
	straight* arr = new straight[k];

	for (int i = 0; i < k; ++i) {
		cout << i + 1 << " прямая: " << '\n';

		cout << "Введите координаты первой точки (x, y): ";
		cin >> arr[i].x1 >> arr[i].y1;

		cout << "Введите координаты второй точки (x, y): ";
		cin >> arr[i].x2 >> arr[i].y2;

		cout << '\n';
	}

	return arr;
}

void from_kanon_to_k(straight p) {
	if (p.x2 - p.x1 == 0) {
		cout << "Уравнение прямой, проходящей через точки (" <<
			p.x1 << ", " << p.y1 << ") и (" << p.x2 << ", " << p.y2 << "): " << '\n';
		cout << "x = " << p.x1 << '\n';
		return;
	}

	double k = (p.y2 - p.y1) / (p.x2 - p.x1);
	double b = p.y1 - k * p.x1;

	cout << "Уравнение прямой, проходящей через точки (" <<
		p.x1 << ", " << p.y1 << ") и (" << p.x2 << ", " << p.y2 << "): " << '\n';

	if (k != 0 && b == 0) {
		cout << "y = " << k << 'x' << '\n';
	}
	else if (k == 0 && b != 0) {
		cout << "y = " << b << '\n';
	}
	else if (k != 0 && b != 0) {
		cout << "y = " << k << 'x' << " + " << b << '\n';
	}
	else {
		cout << "y = 0" << '\n';
	}
}

void display(straight* arr, const int k) {
	for (int i = 0; i < k; ++i) {
		cout << i + 1 << " прямая: ";
		from_kanon_to_k(arr[i]);
		cout << '\n';
	}
}
