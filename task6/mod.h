#ifndef MOD_H
#define MOD_H
#include <iostream>
#include <vector>
#include <Windows.h>
using namespace std;

struct straight {
	double x1, x2;
	double y1, y2;
};

straight* create_arr(const int k);
void from_kanon_to_k(straight p);
void display(straight* arr, const int k);

#endif