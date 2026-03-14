using namespace std;
#include "array_utils.h"
#include <iostream>
#include <cstdlib>


void initArray(double* a, int n, double min, double max) {
	for (int i = 0; i < n; ++i) {
		double r = static_cast<double>(rand()) / RAND_MAX;
		a[i] = min + r * (max - min);
	}
}

void printArray(const double* a, int n) {
	for (int i = 0; i < n; ++i) {
		cout << a[i] << ' ';
	}
	cout << endl;
}
/*
void reverseRange(double* a, size_t begin, size_t end) {
	while (begin < end) {
		double tmp = a[begin];
		a[begin] = a[end];
		a[end] = tmp;
		++begin;
		--end;
	}
}*/

void reverseThirdThird(double* a, int n) {
	if (n <= 1) return;
	int third = n / 3;
	/*
	size_t t = static_cast<size_t>(n);
	size_t third = t / 3;
	*/
	if (third <= 1) return;
	int begin = n - third;
	int end = n - 1;
	//reverseRange(a, begin, end);
	while (begin < end) {
		double tmp = a[begin];
		a[begin] = a[end];
		a[end] = tmp;
		++begin;
		--end;
	}
}

void cyclicLeftShift(double* a, int n, int k){
	if (n <= 1) return;

	int count = n / 2;
	if (count <= 1) return;

	k = k % count;
	if (k == 0) return;

	double* t = new double[count];
	int index = 0;

	for (int i = 1; i < n; i += 2) {
		t[index++] = a[i];
	}

	index = 0;

	for (int i = 1; i < n; i += 2) {
		a[i] = t[(index + k) % count];
		++index;
	}
	delete[] t;
}


void selectionSort(double* a, int n) {
	int count = 0;
	for (int i = 1; i < n; i += 2) {
		if (a[i] > 0) {
			++count;
		}
	}
	if (count <= 1) return;
	double* t = new double[count];
	int index = 0;

	for (int i = 1; i < n; i += 2) {
		if (a[i] > 0) {
			t[index++] = a[i];
		}
	}

	for (int i = 0; i < count - 1; ++i) {
		int minindex = i;
		for (int j = 1 + i; j < count; ++j) {
			if (t[j] < t[minindex]) {
				minindex = j;
			}
		}
		double tr = t[i];
		t[i] = t[minindex];
		t[minindex] = tr;
	}

	index = 0;
	for (int i = 1; i < n; i += 2) {
		if (a[i] > 0) {
			a[i] = t[index++];
		}
	}
	delete[] t;
}
///
