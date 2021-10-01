#ifndef __tryParse__
#define __tryParse__

//------------------------------------------------------------------------------
// tryParse.h - содержит парсер строки в целое число или число с плавающей точкой.
//------------------------------------------------------------------------------

#include <iostream>
#include <cstring>

using std::isdigit;

//------------------------------------------------------------------------------
// Парсинг строки в число с плавающей точкой.
inline bool TryParse(char *str, double *number) {
    int countDot = 0;
    for (int index = 0; index < strlen(str); ++index) {

        auto letter = str[index];
        if (letter == '-' && index == 0 || isdigit(letter)){
            continue;
        } else if (letter == '.' && countDot == 0) {
            ++countDot;
            continue;
        }
        return false;

    }

    *number = atof(str);
    return true;
}

//------------------------------------------------------------------------------
// Парсинг строки в целое число.
inline bool TryParse(const char* str, int* number) {
    for (int index = 0; index < strlen(str); ++index) {
        auto letter = str[index];
        if (letter == '-' && index == 0 || isdigit(letter)){
            continue;
        }
        return false;
    }

    *number = std::stoi(str);
    return true;
}

#endif //__tryParse__
