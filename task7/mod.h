#ifndef MOD_H
#define MOD_H
#include <iostream>
#include <cmath>
// #include <Windows.h>
#include <fstream>
using namespace std;

class rectangle
{
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
    friend istream &operator>>(istream &in, rectangle &r);
};

class parallelepiped : public rectangle
{
protected:
    double c;

public:
    parallelepiped();
    parallelepiped(double c, const rectangle &r);
    parallelepiped(double a, double b, double c);
    void display_info();
    double get_a() { return a; }
    double get_b() { return b; }
    double get_c() { return c; }
    double calc_square();
    double calc_volume();
    double calc_perimeter();
    ~parallelepiped();
    friend istream &operator>>(istream &in, parallelepiped &p);
};

rectangle *create_arr_from_rectangle(const char *filename, int &n);
parallelepiped *create_arr_from_parallelepiped(const char *filename, int &m);
int calc_middle_square_of_rectangle(rectangle *arr, const int n);
int is_cube(parallelepiped *arr, const int m);

#endif