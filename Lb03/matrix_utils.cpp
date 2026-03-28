#include "matrix_utils.h"
#include <iostream>
#include <cmath>

double** allocateMatrix(size_t rows, size_t cols) {
	double** matrix = new double* [rows];

	for (size_t i = 0; i < rows; i++) {
		matrix[i] = new double[cols];
	}
	return matrix;
}

void freeMatrix(double** matrix, size_t rows) {
	for (size_t i = 0; i < rows; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}

void printMatrix(double** matrix, size_t rows, size_t cols) {
	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < cols; j++) {
			std::cout << matrix[i][j] << "\t";
		}
		std::cout << "\n";
	}
}


double calcElementLib(size_t i, size_t j) {
	if (i == j) {
		return i + j;
	}
	return (2 * cos(2 * i) - sin(2 * j)) / ((i + 1) * (i + 1));
}

double sinTaylor(double x) {
	double term = x;
	double sum = x;

	for (int n = 1; n < 10; n++) {
		term *= -x * x / ((2 * n) * (2 * n + 1));
		sum += term;
	}

	return sum;
}

double cosTaylor(double x) {
	double term = 1;
	double sum = 1;

	for (int n = 1; n < 10; n++) {
		term *= -x * x / ((2 * n - 1) * (2 * n));
		sum += term;
	}

	return sum;
}

double calcElementTaylor(size_t i, size_t j) {
	if (i == j) {
		return i + j;
	}

	double cosVal = cosTaylor(2 * i);
	double sinVal = sinTaylor(2 * j);

	return (2 * cosVal - sinVal) / ((i + 1) * (i + 1));
}

void buildMatrixLib(double** matrix, size_t rows, size_t cols) {
	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < cols; j++) {
			matrix[i][j] = calcElementLib(i, j);
		}
	}
}

void buildMatrixTaylor(double** matrix, size_t rows, size_t cols) {
	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < cols; j++) {
			matrix[i][j] = calcElementTaylor(i, j);
		}
	}
}