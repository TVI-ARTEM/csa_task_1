#ifndef __container__
#define __container__

//------------------------------------------------------------------------------
// container.h - содержит тип данных - матрица,
// представляющий простейший контейнер
//------------------------------------------------------------------------------

#include "../matrix/matrix.h"

//------------------------------------------------------------------------------
// Простейший контейнер на основе одномерного массива.
struct container {
    enum {MAX_LEN = 10000};
    int currentLength;
    matrix *cont[MAX_LEN];
};

// Инициализация контейнера.
void Init(container &c);

// Очистка контейнера от элементов.
void Clear(container &c);

// Ввод содержимого контейнера из указанного потока.
void In(container &c, ifstream & ifStream);

// Случайный ввод содержимого контейнера.
void InRandom(container &c, int length);

// Вывод содержимого контейнера в указанный поток.
void Out(container &c, ofstream &ofStream);

// Сортировка контейнера методом вставки - straight sort.
void Sort(container &c);

#endif //__container__
