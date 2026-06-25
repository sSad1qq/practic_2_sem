#include "mod.h"

double** createDoubleMatrix() {
	double** matrix = new double* [MATRIX_SIZE];
	for (int i = 0; i < MATRIX_SIZE; i++) {
		*(matrix + i) = new double[MATRIX_SIZE];
	}
	return matrix;
}

double** read_matrix_from_file(const char* file_name, int rows, int cols) {
	ifstream in(file_name);
	
	in >> rows >> cols;

	double** B = new double* [rows];
	for (int i = 0; i < rows; ++i) {
		B[i] = new double[cols];
		for (int j = 0; j < cols; ++j) {
			in >> B[i][j];
		}
	}

	return B;
}

void printMatrix(double** matrix) {
	for (int i = 0; i < MATRIX_SIZE; i++) {
		for (int j = 0; j < MATRIX_SIZE; j++) {
			cout << *(*(matrix + i) + j) << " ";
		}
		cout << endl;
	}
	cout << endl;

}
double getAverageOfNeighbours(double** matrix, int i, int j) {
	double sum = 0;
	int count = 0;

	for (int k = i - 1; k <= i + 1; k++) {
		for (int l = j - 1; l <= j + 1; l++) {
			if (k >= 0 && k < MATRIX_SIZE && l >= 0 && l < MATRIX_SIZE && !(k == i && l == j)) {
				sum += *(*(matrix + k) + l);
				count++;
			}
		}
	}
	return (count > 0) ? sum / count : 0;
}

void smoothMatrix(double** matrix, double** smoothedMatrix) {
	for (int i = 0; i < MATRIX_SIZE; i++) {
		for (int j = 0; j < MATRIX_SIZE; j++) {
			*(*(smoothedMatrix + i) + j) = getAverageOfNeighbours(matrix, i, j);
		}
	}
}

double sumAbsUnderMainDiagonal(double** smoothedMatrix) {
	double sum = 0;
	for (int i = 0; i < MATRIX_SIZE; i++) {
		for (int j = 0; j < MATRIX_SIZE; j++) {
			if (i > j)
				sum += fabs(*(*(smoothedMatrix + i) + j));
		}
	}
	return sum;
}