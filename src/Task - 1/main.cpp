//------------------------------------------------------------------------------
// main.cpp - содержит главную функцию, выполняющую тестирование.
//------------------------------------------------------------------------------

#include <iostream>
#include <ctime>
#include <cstring>
#include "container/container.h"

using std::cout;

void commandLineError() {
    cout << "incorrect command line!\n"
            "  Waited:\n"
            "     command -f infile outfile01 outfile02\n"
            "  Or:\n"
            "     command -n number outfile01 outfile02\n";
}

void qualifierValueError() {
    cout <<"incorrect qualifier value!\n"
            "  Waited:\n"
            "     command -f infile outfile01 outfile02\n"
            "  Or:\n"
            "     command -n number outfile01 outfile02\n";
}

int main(int argCount, char* argValues[]) {
    auto start = clock();

    if (argCount != 5) {
        commandLineError();
        return 1;
    }

    std::cout <<"Start" << std::endl;

    container c{};
    Init(c);

    if(!strcmp(argValues[1], "-f")) {
        ifstream ifStream(argValues[2]);
        // Проверка файла на существование.
        if (!ifStream) {
            cout << "Incorrect In-file";
            return 2;
        }
        In(c, ifStream);
        ifStream.close();
    }
    else if(!strcmp(argValues[1], "-n")) {
        auto length = atoi(argValues[2]);
        if((length < 1) || (length > 10000)) {
            cout << "incorrect number of matrixes = "
                 << length
                 << ". Set 0 < number <= 10000\n";
            return 3;
        }
        srand(static_cast<unsigned int>(time(nullptr)));
            InRandom(c, length);
    }
    else {
        qualifierValueError();
        return 4;
    }

    // Вывод контейнера до сортировки.
    ofstream ofStreamFirst(argValues[3]);
    Out(c, ofStreamFirst);
    ofStreamFirst << "\n" << "Time: " << (clock() - start) * 1.0 / CLOCKS_PER_SEC << "s" << "\n";
    ofStreamFirst.close();

    // Вывод контейнера после сортировки.
    ofstream ofStreamSecond(argValues[4]);
    ofStreamSecond << "---Sorted container---" << '\n';
    Sort(c);
    Out(c, ofStreamSecond);
    ofStreamSecond << "\n" << "Time sorted: " << (clock() - start) * 1.0 / CLOCKS_PER_SEC << "s" << "\n";

    Clear(c);
    ofStreamSecond << "Time after clearing: " << (clock() - start) * 1.0 / CLOCKS_PER_SEC << "s" << "\n";
    ofStreamSecond.close();

    std::cout <<"End" << "\n";

    return 0;
}
