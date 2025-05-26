#include "triangle.h"
#include <stdio.h>
#include <stdlib.h>

int steps = 0;
// Рекурсивная функция для вычисления треугольного числа
int compute_triangle_recursive(int n) {
    steps += 1;

    if (n == 1)
        return 1;
    else
        return n + compute_triangle_recursive(n - 1);
    
}

// Выводит треугольник в файл и в терминал
void print_triangle(int n) {
    // Выводим треугольник в терминал
    printf("Triangle in terminal:\n");
    for (int row = 1; row <= n; row++) {
        for (int i = 0; i < row; i++) {
            printf("* ");
        }
        printf("\n");
    }
}

// Выводит треугольник в файл
void print_triangle_to_file(int n, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: cannot open file %s for writing.\n", filename);
        exit(1);
    }

    // Выводим треугольник в файл
    
    for (int row = 1; row <= n; row++) {
        for (int i = 0; i < row; i++) {
            fprintf(file, "* ");
        }
        fprintf(file, "\n");
    }

    fclose(file);
printf("%d", steps);
}
