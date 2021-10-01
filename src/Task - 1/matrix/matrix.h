#ifndef __matrix__
#define __matrix__

//------------------------------------------------------------------------------
// matrix.h - содержит описание обобщающей квадратной матрицы.
//------------------------------------------------------------------------------

#include <fstream>
#include <iostream>


using std::ifstream;
using std::ofstream;
using std::string;

//------------------------------------------------------------------------------
// структура, обобщающая все имеющиеся квадратные матрицы.
struct matrix {
    enum {MAX_LENGTH = 1000000};
    // Значение ключей для каждой из фигур.
    enum matrixKey {SQUARE, DIAGONAL, L_TRIANGLE};
    matrixKey key;
    int dimension;
    bool correct;
};

// Ввод обобщенной матрицы.
matrix *In(ifstream &ifStream);

// Случайный ввод обобщенной матрицы.
matrix *InRandom();

// Вывод обобщенной матрицы.
void Out(matrix &m,ofstream &ofStream);

// Удаление обобщенной матрицы.
void Clear(matrix *m);

// Подсчет среднего значения элементов обобщенной матрицы.
double Average(matrix &m);

#endif