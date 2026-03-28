#include <iostream>
using namespace std;
int calculateCriterion(const int* row, int lenght) {
	int count = 0;
	for (int i = 0; i < lenght;++i) {
		if (row[i] % 2 != 0) {
			count++;
		}
	}
	return count;
}

void swapRaws(int** matrix, int* rowSizes, int i, int j) {
	int* tempRow = matrix[i];
	matrix[i] = matrix[j];
	matrix[j] = tempRow;
	int tempSizes = rowSizes[i];
	rowSizes[i] = rowSizes[j];
	rowSizes[j] = tempSizes;



}

void sortRows(int** matrix, int* rowSizes, int rowCount) {
	for (int i = 0; i < rowCount;++i) {
		for (int j = 0; j < rowCount - i - 1;++j) {
			int c1 = calculateCriterion(matrix[j], rowSizes[j]);
			int c2 = calculateCriterion(matrix[j + 1], rowSizes[j + 1]);

			if (c1 > c2) {
				swapRaws(matrix, rowSizes, j, j + 1);
			}
		}

	}
}

void printMatrix(int** matrix, int* rowSizes, int rowCount) {
	for (int i = 0; i < rowCount;++i) {
		cout << "Row" << i << ": ";
		for (int j = 0;j < rowSizes[i]; ++j) {
			cout << matrix[i][j] << " ";
			
		}
		cout << endl;
	}
}

void freeMatrix(int** matrix, int* rowSizes, int rowCount)
{
	for (int i = 0; i < rowCount; ++i)
		delete[] matrix[i];

	delete[] matrix;
	delete[] rowSizes;
}






#include <locale> 


int main() {
	setlocale(LC_ALL, "Russian");

	int rowCount;
	cout << "введите числа: ";
	cin >> rowCount;

	int** matrix = new int*[rowCount];
	int* rowSizes = new int[rowCount];

	for (int i = 0; i < rowCount;++i) {
		cout << "Введи номер ряда: ";
		cin >> rowSizes[i];
		cout << endl;

		matrix[i] = new int[rowSizes[i]];

		cout << "Введи элементы: ";
		for (int j = 0; j < rowSizes[i]; ++j) {
			cin >> matrix[i][j];
		}

	}
	cout << "\nИсходная матрица:\n";
	printMatrix(matrix, rowSizes, rowCount);

	sortRows(matrix, rowSizes, rowCount);

	cout << "\nСортированная матрица:\n";
	printMatrix(matrix, rowSizes, rowCount);
	freeMatrix(matrix, rowSizes, rowCount);

	return 0;
}