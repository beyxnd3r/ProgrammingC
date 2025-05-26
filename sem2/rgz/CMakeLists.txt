cmake_minimum_required(VERSION 3.10)
project(TriangleProject C)

set(CMAKE_C_STANDARD 99)

# Библиотека из triangle.c
add_library(triangle STATIC triangle.c)

# Основная программа
add_executable(Triangle main.c)
target_link_libraries(Triangle triangle)

# Unit-тесты
enable_testing()
add_executable(test_triangle test_triangle.c)
target_link_libraries(test_triangle triangle)
add_test(NAME TriangleTests COMMAND test_triangle)
