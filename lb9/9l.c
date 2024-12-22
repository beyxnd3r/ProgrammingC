#include <stdio.h>
#include <stdlib.h>

// Поиск масимального
int max_in_strok(int* row, int cols) {
    int max = row[0];
    for (int j = 1; j < cols; j++) {
        if (row[j] > max) {
            max = row[j];
        }
    }
    return max;
}

// 0
int nol(int* matrix, int rows, int cols) {
    for (int i = 0; i < rows * cols; i++) {
        if (matrix[i] == 0) {
            return 1; 
        }
    }
    return 0;
}

// Умножение
void multiply_matrix_vector(int* matrix, int rows, int cols, int* vector, int* result) {
    for (int i = 0; i < rows; i++) {
        result[i] = 0;
        for (int j = 0; j < cols; j++) {
            result[i] += matrix[i * cols + j] * vector[j];
        }
    }
}

// Ввод
void print_array(int* array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Вывод 
void print_matrix(int* matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i * cols + j]);
        }
        printf("\n");
    }
}

// Основная функция
int main() {
    int rows, cols;

    
    printf("Введите количество строк и столбцов матрицы A: ");
    scanf("%d %d", &rows, &cols);

    // Выделение памяти A
    int* matrix_A = (int*)malloc(rows * cols * sizeof(int));
   

    
    printf("Введите элементы матрицы A:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix_A[i * cols + j]);
        }
    }

    // Выделение B
    int* vec_B = (int*)malloc(rows * sizeof(int));
    if (vec_B == NULL) {
        printf("Ошибка выделения памяти");
        free(matrix_A);
        return 1;
    }
    for (int i = 0; i < rows; i++) {
        vec_B[i] = max_in_strok(&matrix_A[i * cols], cols);
    }

    // C
    int* matrix_C = (int*)malloc(rows * sizeof(int));
    if (matrix_C == NULL) {
        printf("Ошибка выделения памяти");
        free(matrix_A);
        free(vec_B);
        return 1;
    }
    multiply_matrix_vector(matrix_A, rows, cols, vec_B, matrix_C);

    
    printf("Матрица A:\n");
    print_matrix(matrix_A, rows, cols);

    printf("Вектор B:\n");
    print_array(vec_B, rows);

    printf("Результат умножения (матрица C):\n");
    print_array(matrix_C, rows);

    
    if (nol(matrix_A, rows, cols)) {
        printf("Матрица A содержит нули. Массив B в обратном порядке:\n");
        for (int i = rows - 1; i >= 0; i--) {
            printf("%d ", vec_B[i]);
        }
        printf("\n");
    }

    free(matrix_A);
    free(vec_B);
    free(matrix_C);

    return 0;
}
