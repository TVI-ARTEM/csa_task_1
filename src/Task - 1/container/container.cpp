//------------------------------------------------------------------------------
// container.cpp - содержит функции обработки контейнера.
//------------------------------------------------------------------------------

#include "container.h"

//------------------------------------------------------------------------------
// Инициализация контейнера.
void Init(container &c) {
    c.currentLength = 0;

}

//------------------------------------------------------------------------------
// Очистка контейнера от элементов.
void Clear(container &c) {
    for (int i = 0; i < c.currentLength; ++i) {
        Clear(c.cont[i]);
    }
    c.currentLength = 0;
}

//------------------------------------------------------------------------------
// Ввод содержимого контейнера из указанного потока.
void In(container &c, ifstream &ifStream) {
    while (!ifStream.eof()) {
        if (((c.cont)[c.currentLength] = In(ifStream)) != nullptr) {
            ++c.currentLength;
        }
    }
}

//------------------------------------------------------------------------------
// Случайный ввод содержимого контейнера.
void InRandom(container &c, int length) {
    for (; c.currentLength < length; ++c.currentLength) {
        c.cont[c.currentLength] = InRandom();
    }
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в указанный поток.
void Out(container &c, ofstream &ofStream) {
    if (c.currentLength > 0) {
        ofStream << "Filled container:" << "\n";
        ofStream << "Container contains " << c.currentLength << " elements." << '\n';
        for (int i = 0; i < c.currentLength; i++) {
            ofStream << i + 1 << ": ";
            Out(*c.cont[i], ofStream);
        }
    } else {
        ofStream << "Empty container. " << "\n";
        ofStream << "Container contains " << c.currentLength << " elements." << '\n';
    }


}

//------------------------------------------------------------------------------
// Сортировка контейнера методом вставки - straight sort.
void Sort(container &c) {
    for (int i = 1; i < c.currentLength; ++i) {
        for (auto j = i; j > 0 && Average(*c.cont[j - 1]) < Average(*c.cont[j]); --j) {
            auto temp = c.cont[j - 1];
            c.cont[j - 1] = c.cont[j];
            c.cont[j] = temp;
        }
    }
}
