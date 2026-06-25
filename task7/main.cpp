#include "mod.h"

int main()
{
    /*
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    */
    int n, m;
    const char *file_with_pars = "/Users/daniildyatlov/develop/git/prac/practic_2_sem/task7/pars.txt";
    const char *file_with_rects = "/Users/daniildyatlov/develop/git/prac/practic_2_sem/task7/rect.txt";

    parallelepiped *arr_pars = create_arr_from_parallelepiped(file_with_pars, m);
    rectangle *arr_rects = create_arr_from_rectangle(file_with_rects, n);

    cout << "Прочитано прямоугольников: " << n << '\n';
    for (int i = 0; i < n; ++i)
    {
        arr_rects[i].display_info();
    }
    cout << "Из них количество прямоугольников, площадь которых больше средней: " << calc_middle_square_of_rectangle(arr_rects, n) << '\n';

    cout << "Прочитано параллелепипедов: " << m << '\n';
    for (int i = 0; i < m; ++i)
    {
        arr_pars[i].display_info();
    }
    cout << "Из них количество параллелепипедов, являющихся кубами:  " << is_cube(arr_pars, m) << '\n';

    delete[] arr_rects;
    delete[] arr_pars;
    return 0;
}