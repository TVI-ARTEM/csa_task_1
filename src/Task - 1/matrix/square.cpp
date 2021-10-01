//------------------------------------------------------------------------------
// square.cpp - содержит функции обработки обычной квадратной матрицы.
//------------------------------------------------------------------------------

#include "square.h"
#include "../functions/tryParse.h"
#include "../functions/random.h"
#include "../functions/streamManage.h"

//------------------------------------------------------------------------------
// Ввод квадратной матрицы.
void In(square &m, ifstream &ifStream) {
    m.array = new double *[m.dimension];

    for (int i = 0; i < m.dimension; ++i) {
        m.array[i] = new double [m.dimension];
        for (int j = 0; j < m.dimension; ++j) {
            char* temp = new char[matrix::MAX_LENGTH];

            // Проверка значения на корректность или поиск следующей корректной матрицы.
            if (!ifStream.eof()) {
                ifStream >> temp;
            } else {
                Clear(m);
                FindNextCorrect(ifStream);
                return;
            }

            if (!TryParse(temp, &m.array[i][j])) {
                Clear(m);
                FindNextCorrect(ifStream);
                return;
            }

            delete[] temp;
        }
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
// Случайный ввод квадратной матрицы.
void InRandom(square &m) {
    m.array = new double *[m.dimension];

    for (int i = 0; i < m.dimension; ++i) {
        m.array[i] = new double [m.dimension];
        for (int j = 0; j < m.dimension; ++j) {
            m.array[i][j] = Random(-10.0, 11.0);
        }
    }
}

//------------------------------------------------------------------------------
// Вывод квадратной матрицы.
void Out(square &m, ofstream &ofStream) {
    if (m.correct) {
        ofStream << "It's square matrix: dimension = " << m.dimension << "\n";
        for (int i = 0; i < m.dimension; ++i) {
            for (int j = 0; j < m.dimension; ++j) {
                ofStream << m.array[i][j] << " ";
            }
            ofStream << "\n";
        }
        ofStream << "Average: " << Average(m) << "\n";
    } else {
        ofStream << "Incorrect matrix" << "\n";
    }
}

//------------------------------------------------------------------------------
// Удаление квадратной матрицы.
void Clear(square &m) {
    for (int i = 0; i < m.dimension; ++i) {
        delete[] m.array[i];
    }
    delete[] m.array;
    m.array = nullptr;
    m.dimension = 0;
    m.correct = false;
}

//------------------------------------------------------------------------------
// Подсчет среднего значения элементов квадратной матрицы.
double Average(square &m) {
    double average = 0;
    for (int i = 0; i < m.dimension; ++i) {
        for (int j = 0; j < m.dimension; ++j) {
            average += m.array[i][j];
        }
    }
    return average / (m.dimension * m.dimension);
}
