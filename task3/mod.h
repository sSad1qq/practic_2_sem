#ifndef MOD_H
#define MOD_H
#include <iostream>
#include <windows.h>
#include <random>
using namespace std;

double* init_arr(const int size);
void display_arr(double* arr, const int size);
double find_min_el(double* arr, const int size);
double sum_of_el_btw_two_neg(double *arr, const int size);
void sort_arr(double *arr, const int size);

#endif