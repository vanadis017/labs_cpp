#ifndef ARRAY_UTILS_H
#define ARRAY_UTILS_H
#include <cstddef>

void initArray(double* a, int n, double min, double max);
void printArray(const double* a, int n);
//void reverseRange(double* a, size_t begin, size_t end);
void reverseThirdThird(double* a, int n);

void cyclicLeftShift(double* a, int n, int k);

void selectionSort(double* a, int n);

#endif
