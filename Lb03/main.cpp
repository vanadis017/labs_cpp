#include <iostream>
#include <cmath>
#include "matrix_utils.h"
#include <locale>


bool testElement() {
    double a = calcElementLib(1, 2);
    double b = calcElementTaylor(1, 2);

    return std::abs(a - b) < 1e-3;
}

int main() {
    std::setlocale(LC_ALL, "Russian");
    size_t n, m;

    std::cout << "Введите размеры матрицы: ";
    std::cin >> n >> m;

double** A = allocateMatrix(n, m);

std::cout << "\n[LIB]\n";
buildMatrixLib(A, n, m);
printMatrix(A, n, m);

std::cout << "\n[TAYLOR]\n";
buildMatrixTaylor(A, n, m);
printMatrix(A, n, m);

freeMatrix(A, n);

if (testElement()) {
    std::cout << "[ТЕСТ] Сравнение методов: ПРОЙДЕН\n";
}
else {
    std::cout << "[ТЕСТ] Сравнение методов: НЕ ПРОЙДЕН\n";
}

return 0;
}