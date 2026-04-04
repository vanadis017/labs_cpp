#include <iostream>
using namespace std;


//проверка делится ли число на 4
bool filter(int value) {
	return value % 4 == 0;
}


//берем числа, которые подходят, и умножаем их на 2
int transform(int value) {
	return value * 2;
}


int* process(const int* src, int size,
    bool (*filter)(int),
    int (*transform)(int),
    int& outSize)
{
    if (size <= 0 || src == nullptr) {
        outSize = 0;
        return nullptr;
    }

    int count = 0;
    for (int i = 0; i < size; ++i)
        if (filter(src[i]))    // pure function: filter
            ++count;

    outSize = count;
    if (count == 0) {
        return  nullptr;
    }

    int* data = (count > 0) ? new int[count] : nullptr;
    int j = 0;
    for (int i = 0; i < size; ++i)
    {
        if (filter(src[i]))                 // pure function: filter
            data[j++] = transform(src[i]);  // pure function: transform
    }

    return data;
}


//сравнение массивов и вывод результатов теста
bool arraysEqual(const int* a, int sizeA, const int* b, int sizeB)
{
    if (sizeA != sizeB) return false;
    for (int i = 0; i < sizeA; ++i) {
        if (a[i] != b[i]) return false;
    }
    return true;
}


void testMultipleOfFourDouble() {
    int data[] = { 4, 7, 8, 10, 12 };
    int expected[] = { 8, 16, 24 };

    int outSize = 0;
    int* out = process(data, 5, filter, transform, outSize);

    if (arraysEqual(out, outSize, expected, 3)) {
        std::cout << "testNoMatchingElements PASSED\n";
    }

    else{
        std::cout << "testNoMatchingElements FAILED\n";
    }

    delete[] out;
}


void testNoMatches() {
    int data[] = { 1, 2, 3, 5, 6 };

    int outSize = 0;
    int* out = process(data, 5, filter, transform, outSize);

    if (outSize==0 && out==nullptr) {
        std::cout << "testNoMatchingElements PASSED\n";
    }

    else {
        std::cout << "testNoMatchingElements FAILED\n";
    }

    delete[] out;
}


void testEmptyArray() {
    int outSize = 0;
    int* out = process(nullptr, 5, filter, transform, outSize);

    if (outSize == 0 && out == nullptr) {
        std::cout << "testNoMatchingElements PASSED\n";
    }

    else {
        std::cout << "testNoMatchingElements FAILED\n";
    }

    delete[] out;
}


int main() {
    cout << "---------------------------------" << endl;
    testMultipleOfFourDouble();
    testNoMatches();
    testEmptyArray();
    
    return 0;
}