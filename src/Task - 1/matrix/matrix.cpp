//------------------------------------------------------------------------------
// matrix.cpp - содержит функции обработки обобщенной квадратной матрицы.
//------------------------------------------------------------------------------

#include <cstring>
#include "matrix.h"
#include "square.h"
#include "diagonal.h"
#include "lTriangle.h"
#include "../functions/tryParse.h"
#include "../functions/random.h"
#include "../functions/streamManage.h"

//------------------------------------------------------------------------------
// Ввод обобщенной матрицы.
matrix* In(ifstream &ifStream) {
    char* command = new char[matrix::MAX_LENGTH];
    ifStream >> command;

    // Проверка комманды на корректность или поиск следующей корректной матрицы.
    if (strcmp(command, "begin") != 0) {
        FindNextCorrect(ifStream);
        delete[] command;
        return nullptr;
    }
    delete[] command;

    int key, dimension;

    char* temp = new char[matrix::MAX_LENGTH];
    ifStream >> temp;

    // Проверка значения на корректность или поиск следующей корректной матрицы.
    if (!TryParse(temp, &key) && key > 0) {
        FindNextCorrect(ifStream);
        delete[] temp;
        return nullptr;
    }

    ifStream >> temp;
    // Проверка значения на корректность или поиск следующей корректной матрицы.
    if (!TryParse(temp, &dimension) || !(dimension > 0 && dimension < 101)) {
        FindNextCorrect(ifStream);
        delete[] temp;
        return nullptr;
    }
    delete[] temp;

    switch (key) {
        case 1: {
            auto* m_square = new square;
            m_square->correct = true;
            m_square->key =matrix::SQUARE;
            m_square->dimension = dimension;
            In(*m_square, ifStream);
            return m_square->correct ? m_square : nullptr;
        }
        case 2: {
            auto* m_diagonal = new diagonal;
            m_diagonal->correct = true;
            m_diagonal->key =matrix::DIAGONAL;
            m_diagonal->dimension = dimension;
            In(*m_diagonal, ifStream);
            return m_diagonal->correct ? m_diagonal : nullptr;
        }
        case 3: {
            auto* m_lTriangle = new lTriangle;
            m_lTriangle->correct = true;
            m_lTriangle->key =matrix::L_TRIANGLE;
            m_lTriangle->dimension = dimension;
            In(*m_lTriangle, ifStream);
            return m_lTriangle->correct ? m_lTriangle : nullptr;

        }
        default:
            return nullptr;
    }
}

//------------------------------------------------------------------------------
// Случайный ввод обобщенной матрицы.
matrix *InRandom() {
    auto key = Random(1, 4);
    auto dimension = Random(1, 21);

    switch(key) {
        case 1: {
            auto* m_square = new square;
            m_square->correct = true;
            m_square->key =matrix::SQUARE;
            m_square->dimension = dimension;
            InRandom(*m_square);
            return m_square;
        }
        case 2: {
            auto* m_diagonal = new diagonal;
            m_diagonal->correct = true;
            m_diagonal->key =matrix::DIAGONAL;
            m_diagonal->dimension = dimension;
            InRandom(*m_diagonal);
            return m_diagonal;

        }
        case 3: {
            auto* m_lTriangle = new lTriangle;
            m_lTriangle->correct = true;

            m_lTriangle->key =matrix::L_TRIANGLE;
            m_lTriangle->dimension = dimension;
            InRandom(*m_lTriangle);
            return m_lTriangle;

        }
        default:
            return nullptr;
    }
}

//------------------------------------------------------------------------------
// Вывод обобщенной матрицы.
void Out(matrix &m, ofstream &ofStream) {
    switch(m.key) {
        case matrix::SQUARE:
            Out(*((square*)&m), ofStream);
            break;
        case matrix::DIAGONAL:
            Out(*((diagonal*)&m), ofStream);
            break;
        case matrix::L_TRIANGLE:
            Out(*((lTriangle*)&m), ofStream);
            break;
        default:
            ofStream << "Error: " << "Incorrect matrix" ;
    }
}

//------------------------------------------------------------------------------
// Удаление обобщенной матрицы.
void Clear(matrix *m) {
    switch (m->key) {
        case matrix::SQUARE:
            Clear(*((square *) m));
            delete (square *) m;
            break;
        case matrix::DIAGONAL:
            Clear(*((diagonal *) m));
            delete (diagonal *) m;
            break;
        case matrix::L_TRIANGLE:
            Clear(*((lTriangle *) m));
            delete (diagonal *) m;
            break;
        default:
            break;
    }
}

//------------------------------------------------------------------------------
// Подсчет среднего значения элементов обобщенной матрицы.
double Average(matrix &m) {
    switch(m.key) {
        case matrix::SQUARE:
            return Average(*((square*)&m));
        case matrix::DIAGONAL:
            return Average(*((diagonal*)&m));
        case matrix::L_TRIANGLE:
            return Average(*((lTriangle*)&m));
        default:
            return 0.0;
    }
}
