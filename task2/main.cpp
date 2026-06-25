#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <windows.h>
using namespace std;

double F(double k[], double x);
void display_result(double x_begin, double x_last, double dx, double k[]);

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    double a = 0.0, b = 0.0, c = 0.0, x_begin = 0.0, x_last = 0.0, dx = 0.0, x = 0.0;

    cout << "Введите коэффициенты a, b, c: ";
    cin >> a >> b >> c;

    double k[3] = {a, b, c};

    cout << "Введите начальное значение x_begin: ";
    cin >> x_begin;

    cout << "Введите конечное значение x_last: ";
    cin >> x_last;

    cout << "Введите шаг dx: ";
    cin >> dx;

    display_result(x_begin, x_last, dx, k);

    return 0;
}


double F(double k[], double x)
{
    double a, b, c;
    a = k[0];
    b = k[1];
    c = k[2];

    if (x < 5 && c != 0)
    {
        return -a * pow(x, 2) - b;
    }
    else if (x > 5 && c == 0)
    {
        return (x - a) / x;
    }
    else
    {
        return -x / c;
    }
}

void display_result(double x_begin, double x_last, double dx, double k[])
{
    const int w = 14;
    string sep = "+" + string(w, '-') + "+" + string(w, '-') + "+";

    cout << sep << '\n';
    cout << "|" << setw(w) << "x" << "|" << setw(w) << "F(x)" << "|\n";
    cout << sep << '\n';

    cout << fixed << setprecision(4);
    for (double x = x_begin; x <= x_last + dx * 1e-9; x += dx)
    {
        double result = F(k, x);
        cout << "|" << setw(w) << x << "|" << setw(w) << result << "|\n";
    }

    cout << sep << '\n';
}