#define MATRIX_UTILS_H

#include <cstddef>

double** allocateMatrix(size_t rows, size_t cols);
void freeMatrix(double** matrix, size_t rows);
void printMatrix(double** matrix, size_t rows, size_t cols);

double calcElementLib(size_t i, size_t j);
double calcElementTaylor(size_t i, size_t j);

void buildMatrixLib(double** matrix, size_t rows, size_t cols);
void buildMatrixTaylor(double** matrix, size_t rows, size_t cols);

