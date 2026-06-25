#include "mod.h"

int main() {
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	int size = 0;
	cout << "Введите размер массива: ";
	cin >> size;

	double* arr = init_arr(size);
	cout << "Исходный массив: " << '\n';
	display_arr(arr, size);

	cout << '\n';

	double mn_el_of_arr = find_min_el(arr, size);
	double sum_el = sum_of_el_btw_two_neg(arr, size);

	cout << '\n';

	cout << "Минимальный элемент массива: " << mn_el_of_arr << '\n';
	cout << "Сумма элементов между двумя первыми отриц. элементами: " << sum_el << '\n';

	cout << '\n';

	sort_arr(arr, size);
	cout << "Массив после преобразования: " << '\n';
	display_arr(arr, size);

	delete[] arr;
	return 0;
}