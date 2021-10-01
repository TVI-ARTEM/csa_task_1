cmake_minimum_required(VERSION 3.20)
project(Task___1)

set(BUILD_DIR "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/../bin")

set(BINARY_DIR "${CMAKE_BINARY_DIR}")
set(SOURCE_FILES
        # Headers
        functions/streamManage.h
        functions/random.h
        functions/tryParse.h
        matrix/matrix.h
        matrix/square.h
        matrix/diagonal.h
        matrix/lTriangle.h
        container/container.h

        # Sources
        matrix/matrix.cpp
        matrix/square.cpp
        matrix/diagonal.cpp
        matrix/lTriangle.cpp
        container/container.cpp
        main.cpp
)
add_executable(Task___1 "${SOURCE_FILES}")
