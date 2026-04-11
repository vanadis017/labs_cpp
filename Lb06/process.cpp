#include <functional>


int* process(const int* src, int size,
    std::function<bool(int)> filter,
    std::function<int(int)> transform,
    int& outSize)
{
    if (size == 0)
    {
        outSize = 0;
        return nullptr;
    }

    int* buf = new int[size];
    int count = 0;

    for (int i = 0; i < size; ++i)
    {
        if (filter(src[i]))
            buf[count++] = transform(src[i]);
    }

    outSize = count;

    if (count == 0)
    {
        delete[] buf;
        return nullptr;
    }

    if (count == size)
        return buf;

    int* result = new int[count];
    for (int j = 0; j < count; ++j)
        result[j] = buf[j];
    delete[] buf;
    return result;
}



#include <iostream>
bool arraysEqual(const int* a, int sizeA, const int* b, int sizeB)
{
    if (sizeA != sizeB) return false;
    for (int i = 0; i < sizeA; ++i)
        if (a[i] != b[i]) return false;
    return true;
}


void testMultiplesOf4Double()
{
    int data[] = { 1, 4, 6, 8, 10, 12 };
    int expected[] = { 8, 16, 24 };

    int outSize = 0;
    int* out = process(
        data, 6,
        [](int x) { return x % 4 == 0; },   // filter
        [](int x) { return x * 2; },        // transform
        outSize
    );

    bool ok = arraysEqual(out, outSize, expected, 3);
    if (ok)
        std::cout << "testMultiplesOf4Double PASSED\n";
    else
        std::cout << "testMultiplesOf4Double FAILED\n";

    delete[] out;
}




void testEmptyArray()
{
    int data[] = { 1, 2, 3 };
    int outSize = 0;

    int* out = process(
        data, 0,
        [](int x) { return x % 4 == 0; },
        [](int x) { return x * 2; },
        outSize
    );

    bool ok = (outSize == 0 && out == nullptr);
    if (ok)
        std::cout << "testEmptyArray PASSED\n";
    else
        std::cout << "testEmptyArray FAILED\n";

    delete[] out;
}

void testNoMatchingElements()
{
    int data[] = { 1, 2, 3, 5, 6 };
    int outSize = 0;

    int* out = process(
        data, 5,
        [](int x) { return x % 4 == 0; },
        [](int x) { return x * 2; },
        outSize
    );

    bool ok = (outSize == 0);
    if (ok)
        std::cout << "testNoMatchingElements PASSED\n";
    else
        std::cout << "testNoMatchingElements FAILED\n";

    delete[] out;
}
void testAllMatch()
{
    int data[] = { 4, 8, 12 };
    int expected[] = { 8, 16, 24 };

    int outSize = 0;

    int* out = process(
        data, 3,
        [](int x) { return x % 4 == 0; },
        [](int x) { return x * 2; },
        outSize
    );

    bool ok = arraysEqual(out, outSize, expected, 3);
    if (ok)
        std::cout << "testAllMatch PASSED\n";
    else
        std::cout << "testAllMatch FAILED\n";

    delete[] out;
}


void testNegativeValues()
{
    int data[] = { -4, -8, -12 };
    int expected[] = { -8, -16, -24 };

    int outSize = 0;

    int* out = process(
        data, 3,
        [](int x) { return x % 4 == 0; },
        [](int x) { return x * 2; },
        outSize
    );

    bool ok = arraysEqual(out, outSize, expected, 3);
    if (ok)
        std::cout << "testNegativeValues PASSED\n";
    else
        std::cout << "testNegativeValues FAILED\n";

    delete[] out;
}


void testSingleMatch()
{
    int data[] = { 3, 4, 7 };
    int expected[] = { 8 };

    int outSize = 0;

    int* out = process(
        data, 3,
        [](int x) { return x % 4 == 0; },
        [](int x) { return x * 2; },
        outSize
    );

    bool ok = (outSize == 1 && out[0] == 8);
    if (ok)
        std::cout << "testSingleMatch PASSED\n";
    else
        std::cout << "testSingleMatch FAILED\n";

    delete[] out;
}


void testLargeArray()
{
    int data[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };
    int expected[] = { 8, 16, 24, 32 };

    int outSize = 0;

    int* out = process(
        data, 16,
        [](int x) { return x % 4 == 0; },
        [](int x) { return x * 2; },
        outSize
    );

    bool ok = arraysEqual(out, outSize, expected, 4);
    if (ok)
        std::cout << "testLargeArray PASSED\n";
    else
        std::cout << "testLargeArray FAILED\n";

    delete[] out;
}





int main()
{
    testMultiplesOf4Double();
    testEmptyArray();
    testNoMatchingElements();
    testAllMatch();
    testNegativeValues();
    testSingleMatch();
    testLargeArray();

    return 0;
}
