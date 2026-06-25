#include "mod.h"

rectangle::rectangle()
{
    a = 0;
    b = 0;
}

rectangle::rectangle(double a, double b)
{
    this->a = a;
    this->b = b;
}

void rectangle::display_info()
{
    cout << "Информация о прямоугольнике: " << '\n';
    cout << "Стороны: " << a << ", " << b << '\n';
    cout << "Диагональ: " << calc_diag() << '\n';
    cout << "Периметр: " << calc_perimeter() << '\n';
    cout << "Площадь: " << calc_square() << '\n';
    cout << '\n';
}

double rectangle::calc_diag()
{
    return sqrt(pow(a, 2) + pow(b, 2));
}

double rectangle::calc_perimeter()
{
    return 2 * (a + b);
}

double rectangle::calc_square()
{
    return a * b;
}

rectangle::~rectangle()
{
    cout << "Вызван деструктор для прямоугольника" << '\n';
}

parallelepiped::parallelepiped()
{
    c = 0;
}

parallelepiped::parallelepiped(double high, const rectangle &r) : rectangle(r), c(high) {}

parallelepiped::parallelepiped(double a, double b, double c) : rectangle(a, b)
{
    this->c = c;
}

void parallelepiped::display_info()
{
    cout << "Информация о параллелепипеде: " << '\n';
    cout << "Стороны: " << a << ", " << b << ", " << c << '\n';
    cout << "Периметр: " << calc_perimeter() << '\n';
    cout << "Площадь: " << calc_square() << '\n';
    cout << '\n';
}
double parallelepiped::calc_square()
{
    return 2 * (a * b + b * c + c * a);
}

double parallelepiped::calc_volume()
{
    return a * b * c;
}

double parallelepiped::calc_perimeter()
{
    return 4 * (a + b + c);
}

parallelepiped::~parallelepiped()
{
    cout << "Вызван деструктор для параллелепипеда" << '\n';
}

istream &operator>>(istream &in, rectangle &r)
{
    in >> r.a >> r.b;
    return in;
}

istream &operator>>(istream &in, parallelepiped &p)
{
    return in >> static_cast<rectangle &>(p) >> p.c;
}

rectangle *create_arr_from_rectangle(const char *filename, int &n)
{
    ifstream in(filename);
    in >> n;
    rectangle *arr = new rectangle[n];
    for (int i = 0; i < n; ++i)
        in >> arr[i];
    return arr;
}

parallelepiped *create_arr_from_parallelepiped(const char *filename, int &m)
{
    ifstream in(filename);
    in >> m;
    parallelepiped *arr = new parallelepiped[m];
    for (int i = 0; i < m; ++i)
        in >> arr[i];
    return arr;
}

int calc_middle_square_of_rectangle(rectangle *arr, const int n)
{
    double mid_square = 0.0;
    double square_sum = 0.0;
    int ans = 0;

    for (int i = 0; i < n; ++i)
    {
        square_sum += arr[i].calc_square();
    }

    mid_square = square_sum / n;

    for (int i = 0; i < n; ++i)
    {
        if (arr[i].calc_square() > mid_square)
        {
            ans++;
        }
    }
    return ans;
}

int is_cube(parallelepiped *arr, const int m)
{
    int ans = 0;

    for (int i = 0; i < m; ++i)
    {
        if (arr[i].get_a() == arr[i].get_b() && arr[i].get_b() == arr[i].get_c())
        {
            ans++;
        }
    }
    return ans;
}