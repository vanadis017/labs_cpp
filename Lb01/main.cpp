#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
#include "array_utils.h"
using namespace std;

//тесты
bool equals(double a, double b, double eps = 1e-9) {
	return fabs(a - b) < eps;
}
void printTestResult(const string& testName, bool result) {
	cout << "[TEST] " << testName << ": "
		<< (result ? "PASS" : "FAIL") << endl;
}

bool testinitArrayRange() {
	double a[5];
	initArray(a, 5, -2.0, 3.0);

	for (int i = 0; i < 5; ++i) {
		if (a[i] < -2.0 || a[i] > 3.0) return false;
	}
	return true;
}

bool testreverseThirdThird() {
	double a[] = { 1, 2, 3, 4, 5, 6 };
	double expected[] = { 1, 2, 3, 4, 6, 5 };

	reverseThirdThird(a, 6);

	for (int i = 0; i < 6; ++i) {
		if (!equals(a[i], expected[i])) return false;
	}
	return true;
}

bool testcyclicLeftShift() {
	double a[] = { 10, 1, 20, 2, 30, 3 };
	double expected[] = { 10, 2, 20, 3, 30, 1 };

	cyclicLeftShift(a, 6, 1);

	for (int i = 0; i < 6; ++i) {
		if (!equals(a[i], expected[i])) return false;
	}
	return true;
}

bool testselectionSort() {
	double a[] = { 5, 9, -1, 7, 3, 2 };
	double expected[] = { 5, 2, -1, 7, 3, 9 };

	selectionSort(a, 6);

	for (int i = 0; i < 6; ++i) {
		if (!equals(a[i], expected[i])) return false;
	}
	return true;
}

///

int main() {
	setlocale(LC_ALL, "Russian");
	int n, k;
	double minValue, maxValue;
	cout << "Введи размер массива: " << endl;
	cin >> n;
	if (n <= 0) {
		cout << "Введи пложительное число";
		return 0;
	}
	cout << "Введи максимальное и минимальное число: ";
	cin >> maxValue >> minValue;

	double* a = new double[n];

	initArray(a, n, minValue, maxValue);
	cout << "Исходный массив: ";
	printArray(a, n);

	cout << "Реверс третьей трети: ";
	reverseThirdThird(a, n);
	printArray(a, n);

	cout << "введи k: ";
	cin >> k;
	cout << endl;
	cout << "Сдвиг элементов массива с нечетными индексами: ";
	cyclicLeftShift(a, n, k);
	printArray(a, n);

	cout << "Положительные элементы массива с нечетными индексами по возрастанию: ";
	selectionSort(a, n);
	printArray(a, n);
	delete[] a;



	printTestResult("initArray range", testinitArrayRange());
	printTestResult("reverse third third", testreverseThirdThird());
	printTestResult("cyclic left shift", testcyclicLeftShift());
	printTestResult("selection sort", testselectionSort());

	return 0;
}


