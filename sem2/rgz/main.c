#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "triangle.h"

// Проверка, что строка — это положительное целое число
int is_positive_integer(const char *str) {
    if (str == NULL || *str == '\0')
        return 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit((unsigned char)str[i]))
            return 0;
    }
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <positive integer n>\n", argv[0]);
        return 1;
    }

    // Проверка входных данных
    if (!is_positive_integer(argv[1])) {
        printf("Error: argument must be a positive integer.\n");
        return 1;
    }

    // Динамическое выделение памяти под n
    int *n = (int *)malloc(sizeof(int));
    if (n == NULL) {
        printf("Error: memory allocation failed.\n");
        return 1;
    }

    *n = atoi(argv[1]);
    if (*n <= 0) {
        printf("Error: n must be greater than zero.\n");
        free(n);
        return 1;
    }

    // Вычисляем треугольное число
    int result = compute_triangle_recursive(*n);
    printf("The %d-th triangular number is: %d\n", *n, result);

    // Выводим треугольник в терминал
    print_triangle(*n);

    // Записываем треугольник в файл
    print_triangle_to_file(*n, "triangle_output.txt");
    printf("Triangle pattern written to triangle_output.txt\n");

    // Освобождаем память
    free(n);
    return 0;
}
