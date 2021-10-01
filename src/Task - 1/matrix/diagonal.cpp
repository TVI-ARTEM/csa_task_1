//------------------------------------------------------------------------------
// diagonal.cpp - содержит функции обработки диагональной квадратной матрицы.
//------------------------------------------------------------------------------

#include "diagonal.h"
#include <cstring>
#include "../functions/tryParse.h"
#include "../functions/random.h"
#include "../functions/streamManage.h"

//------------------------------------------------------------------------------
// Случайный ввод обобщенной матрицы.
void In(diagonal &m, ifstream &ifStream) {
    m.array = new double[m.dimension];
    for (int i = 0; i < m.dimension; ++i) {
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
// Случайный ввод диагональной матрицы.
void InRandom(diagonal &m) {
    m.array = new double[m.dimension];
    for (int i = 0; i < m.dimension; ++i) {
        m.array[i] = Random(-10.0, 11.0);
    }
}

//------------------------------------------------------------------------------
// Вывод диагональной матрицы.
void Out(diagonal &m, ofstream &ofStream) {
    if (m.correct) {
        ofStream << "It's diagonal matrix: dimension = " << m.dimension << "\n";
        for (int i = 0; i < m.dimension; ++i) {
            for (int j = 0; j < m.dimension; ++j) {
                if (i == j) {
                    ofStream << m.array[i] << " ";
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
// Удаление диагональной матрицы.
void Clear(diagonal &m) {
    delete[] m.array;
    m.array = nullptr;
    m.dimension = 0;
    m.correct = false;
}

//------------------------------------------------------------------------------
// Подсчет среднего значения элементов диагональной матрицы.
double Average(diagonal &m) {
    double average = 0;
    for (int i = 0; i < m.dimension; ++i) {
        average += m.array[i];
    }
    return average / (m.dimension * m.dimension);
}

