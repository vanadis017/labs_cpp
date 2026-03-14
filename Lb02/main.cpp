#include <iostream>
#include <locale>
#include "string_utils.h"

using namespace std;

int main()
{
    locale::global(locale("Russian_Russia.utf8"));
    wcin.imbue(locale());
    wcout.imbue(locale());

    const int StrLen = 250;
    wchar_t* str = new wchar_t[StrLen];

    wcout << L"Введите строку: ";
    wcin.getline(str, StrLen);

    int result1 = harmonicMeanEvenUpperRussian(str);
    int result2 = firstWordConsonantHarmonic(str);
    int result3 = countDigitSeparatorVowel(str);

    wcout << L"\nРезультаты:\n";

    wcout << L"Часть 1 (среднее гармоническое кодов русских заглавных четных): "
        << result1 << endl;

    wcout << L"Часть 2 (среднее гармоническое кодов символов первого слова, начинающегося с согласной): "
        << result2 << endl;

    wcout << L"Часть 3 (количество комбинаций 'цифра-разделитель-гласная'): "
        << result3 << endl;

    delete[] str;

    return 0;
}