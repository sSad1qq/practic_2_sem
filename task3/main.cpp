#include <iostream>
#include <windows.h>
#include <random>
using namespace std;

double* init_arr(const int size);
void display_arr(double* arr, const int size);
double find_min_el(double* arr, const int size);
double sum_of_el_btw_two_neg(double *arr, const int size);
void sort_arr(double *arr, const int size);

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

double* init_arr(const int size) {
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<double> dist(-10.0, 10.0);
	double* arr = new double[size];

	for (double* i = arr; i < arr + size; ++i) {
		*i = dist(gen);
	}

	return arr;
}

void display_arr(double* arr, const int size) {
	for (double* i = arr; i < arr + size; ++i) {
		cout << *i << " ";
	}
	cout << '\n';
}

double find_min_el(double *arr, const int size) {
	double mn = 1.0e10;

	for (double* i = arr; i != arr + size; ++i) {
		if (*i < mn) {
			mn = *i;
		}
	}
	return mn;
}

double sum_of_el_btw_two_neg(double *arr, const int size) {
	int count_neg_el = 0;
	double sum = 0.0;
	double* first = nullptr;
	double* second = nullptr;
	double* ptrs[2] = {first, second};

	for (double* i = arr; i != arr + size && count_neg_el < 2; ++i) {
		if (*i < 0) {
			ptrs[count_neg_el++] = i;
		}
	}

	for (double* i = ptrs[0] + 1; i < ptrs[1]; ++i) {
		sum += *i;
	}

	return sum;
}

void sort_arr(double *arr, const int size) {
	double* temp = new double[size];
	int idx = 0;

	for (int i = 0; i < size; i++)
		if (arr[i] > -1.0 && arr[i] < 1.0)
			temp[idx++] = arr[i];

	for (int i = 0; i < size; i++)
		if (arr[i] <= -1.0 || arr[i] >= 1.0)
			temp[idx++] = arr[i];

	for (int i = 0; i < size; i++)
		arr[i] = temp[i];

	delete[] temp;
}