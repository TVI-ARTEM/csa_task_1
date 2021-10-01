#ifndef __lTriangle__
#define __lTriangle__

//------------------------------------------------------------------------------
// lTriangle.h - содержит описание нижнетреугольной квадратной матрицы.
//------------------------------------------------------------------------------

#include "matrix.h"

using std::ifstream;
using std::ofstream;

//------------------------------------------------------------------------------
// Нижнетреугольная квадратная матрица.
struct lTriangle : matrix {
    // Элементы матрицы.
    double *array;
};

// Ввод нижнетреугольной матрицы.
void In (lTriangle &m, ifstream &ifStream);

// Случайный ввод нижнетреугольной матрицы.
void InRandom(lTriangle &m);

// Вывод нижнетреугольной матрицы.
void Out(lTriangle &m, ofstream &ofStream);

// Удаление нижнетреугольной матрицы.
void Clear(lTriangle &m);

// Подсчет среднего значения элементов нижнетреугольной матрицы.
double Average(lTriangle &m);

#endif //__lTriangle__
