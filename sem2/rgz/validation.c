#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validation.h"

int validate_input(int argc, char** argv, int* n) {
    if (argc != 2) {
        printf("Ошибка: Необходимо указать один аргумент - число n\n");
        return 0;
    }

    // Проверка, что аргумент - число
    for (int i = 0; argv[1][i] != '\0'; i++) {
        if (argv[1][i] < '0' || argv[1][i] > '9') {
            printf("Ошибка: Аргумент должен быть положительным целым числом\n");
            return 0;
        }
    }

    *n = atoi(argv[1]);
    
    if (*n <= 0) {
        printf("Ошибка: Число должно быть положительным\n");
        return 0;
    }

    if (*n > 20) {
        printf("Предупреждение: Для чисел больше 20 вывод треугольника может быть нечитаемым\n");
    }

    return 1;
}