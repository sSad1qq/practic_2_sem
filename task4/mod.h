#ifndef MOD_H
#define MOD_H
#define MATRIX_SIZE 10
#include <iostream>
#include <fstream>
#include <cmath>
#include <windows.h>
using namespace std;

double** createDoubleMatrix();
double** read_matrix_from_file(const char* file_name, int rows, int cols);
void printMatrix(double** matrix);
double getAverageOfNeighbours(double** matrix, int i, int j);
void smoothMatrix(double** matrix, double** smoothedMatrix);
double sumAbsUnderMainDiagonal(double** smoothedMatrix);

#endif
