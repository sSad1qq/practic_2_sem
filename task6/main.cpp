#include "mod.h"

int main() {
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	int k = 0;

	cout << "Введите количество прямых (K): ";
	cin >> k;

	straight* arr = create_arr(k);

	display(arr, k);

	return 0;
}