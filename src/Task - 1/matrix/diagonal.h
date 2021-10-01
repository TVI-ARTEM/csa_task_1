#ifndef __diagonal__
#define __diagonal__

//------------------------------------------------------------------------------
// diagonal.h - содержит описание диагональной квадратной матрицы.
//------------------------------------------------------------------------------

#include "matrix.h"
using std::ifstream;
using std::ofstream;

//------------------------------------------------------------------------------
// Диагональная квадратная матрица.
struct diagonal : matrix {
    // Элементы матрицы.
    double *array;
};

// Ввод диагональной матрицы.
void In (diagonal &m, ifstream &ifStream);

// Случайный ввод диагональной матрицы.
void InRandom(diagonal &m);

// Вывод диагональной матрицы.
void Out(diagonal &m, ofstream &ofStream);

// Удаление диагональной матрицы.
void Clear(diagonal &m);

// Подсчет среднего значения элементов диагональной матрицы.
double Average(diagonal &m);

#endif