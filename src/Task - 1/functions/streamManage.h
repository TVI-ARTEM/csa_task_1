#ifndef __streamManage__
#define __streamManage__

//------------------------------------------------------------------------------
// streamManage.h - содержит функцию, ищущую следующую корректную матрицу.
//------------------------------------------------------------------------------

#include <fstream>

//------------------------------------------------------------------------------
// Поиск следующей корректной матрицы.
inline void FindNextCorrect(ifstream &ifStream) {
    char* command = new char[matrix::MAX_LENGTH];

    while (!ifStream.eof()) {
        ifStream >> command;

        if (!strcmp(command, "end")) {
            break;
        } else if (!strcmp(command, "begin")) {
            ifStream.seekg(ifStream.tellg() - 12ll);
            break;
        }
    }
    delete[] command;
}

#endif //__streamManage__
