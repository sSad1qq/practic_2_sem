#ifndef MOD_H
#define MOD_H
#include <iostream>
#include <cmath>
#include <Windows.h>
#include <fstream>
using namespace std;

class rectangle {
	protected:
		double a, b;
	public:
		rectangle();
		rectangle(double a, double b);
		void display_info();
		double calc_diag();
		double calc_perimeter();
		double calc_square();
		~rectangle();
};

class parallelepiped : public rectangle {
	protected:
		double c;
	public:
		parallelepiped();
		parallelepiped(double c, const rectangle& r);
		parallelepiped(double a, double b, double c);
		void display_info();
		double calc_square();
		double calc_volume();
		double calc_perimeter();
		~parallelepiped();
};

rectangle* create_arr_from_rectangle(const int n, const char* filename);
parallelepiped* create_arr_from_parallelepiped(const int m, const char* filename);
double calc_middle_square_of_rectangle(rectangle* arr, const int n);
bool is_cube(parallelepiped* arr, const int m);


#endif