//------------------------------------------------------------------------------
// lTriangle.cpp - содержит функции обработки нижнетреугольной квадратной матрицы.
//------------------------------------------------------------------------------

#include "lTriangle.h"
#include "../functions/tryParse.h"
#include "../functions/random.h"
#include "../functions/streamManage.h"

//------------------------------------------------------------------------------
// Ввод нижнетреугольной матрицы.
void In(lTriangle &m, ifstream &ifStream) {
    m.array = new double [m.dimension*(m.dimension + 1) /2];
    for (int i = 0; i < m.dimension*(m.dimension + 1) /2; ++i) {
        char* temp = new char[matrix::MAX_LENGTH];

        // Проверка значения на корректность или поиск следующей корректной матрицы.
        if (!ifStream.eof()) {
            ifStream >> temp;
        } else {
            Clear(m);
            FindNextCorrect(ifStream);
            return;
        }

        if (!TryParse(temp, &m.array[i])) {
            Clear(m);
            FindNextCorrect(ifStream);
            return;
        }
        delete[] temp;
    }

    if (ifStream.eof()) {
        Clear(m);
        return;
    }

    char* command = new char[matrix::MAX_LENGTH];
    ifStream >> command;
    if (strcmp(command, "end") != 0) {
        Clear(m);
        FindNextCorrect(ifStream);
    }
    delete[] command;
}

//------------------------------------------------------------------------------
// Случайный ввод нижнетреугольной матрицы.
void InRandom(lTriangle &m) {
    m.array = new double [m.dimension*(m.dimension + 1) /2];
    for (int i = 0; i < m.dimension*(m.dimension + 1) /2; ++i) {
        m.array[i] = Random(-10.0, 11.0);
    }
}

//------------------------------------------------------------------------------
// Вывод нижнетреугольной матрицы.
void Out(lTriangle &m, ofstream &ofStream) {
    if (m.correct) {
        ofStream << "It's low triangle matrix: dimension = " << m.dimension << "\n";
        int count = 0;
        for (int i = 0; i < m.dimension; ++i) {
            for (int j = 0; j < m.dimension; ++j) {
                if (i >= j) {
                    ofStream << m.array[count] << " ";
                    ++count;
                } else {
                    ofStream << 0 << " ";
                }
            }
            ofStream << "\n";
        }
        ofStream << "Average: " << Average(m) << "\n";
    } else {
        ofStream << "Incorrect matrix" << "\n";
    }
}

//------------------------------------------------------------------------------
// Удаление нижнетреугольной матрицы.
void Clear(lTriangle &m) {
    delete[] m.array;
    m.array = nullptr;
    m.dimension = 0;
    m.correct = false;
}

//------------------------------------------------------------------------------
// Подсчет среднего значения элементов нижнетреугольной матрицы.
double Average(lTriangle &m) {
    double average = 0;
    for (int i = 0; i < m.dimension*(m.dimension + 1) /2; ++i) {
        average += m.array[i];
    }
    return average / (m.dimension * m.dimension);
}
