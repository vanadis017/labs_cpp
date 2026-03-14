#ifndef STRING_UTILS_H
#define STRING_UTILS_H

int harmonicMeanEvenUpperRussian(const wchar_t* str);

int firstWordConsonantHarmonic(const wchar_t* str);

int countDigitSeparatorVowel(const wchar_t* str);

bool isRussianUpper(wchar_t c);
bool isRussianVowel(wchar_t c);
bool isRussianConsonant(wchar_t c);
bool isDigit(wchar_t c);
bool isSeparator(wchar_t c);

#endif