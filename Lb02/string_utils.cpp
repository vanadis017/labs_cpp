#include "string_utils.h"
#include <cwctype>
#include <cmath>

bool isRussianUpper(wchar_t c)
{
    return (c >= L'À' && c <= L'ß') || c == L'¨';
}

bool isRussianVowel(wchar_t c)
{
    const wchar_t vowels[] = L"àå¸èîóûýþÿÀÅ¨ÈÎÓÛÝÞß";
    for (int i = 0; vowels[i] != L'\0'; i++)
        if (c == vowels[i])
            return true;
    return false;
}

bool isRussianConsonant(wchar_t c)
{
    if ((c >= L'À' && c <= L'ß') || (c >= L'à' && c <= L'ÿ') || c == L'¨' || c == L'¸')
        return !isRussianVowel(c);

    return false;
}

bool isDigit(wchar_t c)
{
    return c >= L'0' && c <= L'9';
}

bool isSeparator(wchar_t c)
{
    return iswspace(c) || iswpunct(c);
}

int harmonicMeanEvenUpperRussian(const wchar_t* str)
{
    double sum = 0.0;
    int count = 0;

    for (int i = 0; str[i] != L'\0'; i++)
    {
        wchar_t c = str[i];

        if (isRussianUpper(c) && ((int)c % 2 == 0))
        {
            sum += 1.0 / (int)c;
            count++;
        }
    }

    if (count == 0)
        return 0;

    double h = count / sum;

    return (int)h;
}

int firstWordConsonantHarmonic(const wchar_t* str)
{
    int i = 0;

    while (str[i] != L'\0')
    {
        while (str[i] != L'\0' && isSeparator(str[i]))
            i++;

        if (str[i] == L'\0')
            break;

        int start = i;

        while (str[i] != L'\0' && !isSeparator(str[i]))
            i++;

        int end = i;

        if (isRussianConsonant(str[start]))
        {
            double sum = 0;
            int count = 0;

            for (int j = start; j < end; j++)
            {
                sum += 1.0 / (int)str[j];
                count++;
            }

            if (count == 0)
                return 0;

            double h = count / sum;

            return (int)h;
        }
    }

    return 0;
}

int countDigitSeparatorVowel(const wchar_t* str)
{
    int count = 0;

    for (int i = 0; str[i + 2] != L'\0'; i++)
    {
        if (isDigit(str[i]) &&
            isSeparator(str[i + 1]) &&
            isRussianVowel(str[i + 2]))
        {
            count++;
        }
    }

    return count;
}