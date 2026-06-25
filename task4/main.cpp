#include "mod.h"

int main() {
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

	const char* file_name = "C:/Users/dyatl/source/repos/task4/data.txt";

	double** A = read_matrix_from_file(file_name, MATRIX_SIZE, MATRIX_SIZE);
	double** B = createDoubleMatrix();

	cout << "Исходная матрица: " << '\n';
	printMatrix(A);

	smoothMatrix(A, B);

	cout << "Сглаженная матрица: " << '\n';
	printMatrix(B);

	cout << "Сумма модулей элементов ниже главной диагонали: " << sumAbsUnderMainDiagonal(B) << '\n';

	return 0;
}