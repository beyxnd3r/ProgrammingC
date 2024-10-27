#include <stdio.h>

int main() {
    int A[] = {3, -2, 7, 5, -1, -4}; 
    int B[] = {-1, 3, 4, -1, 6, -2};  
    int C[6];
    
    for (int i = 0; i < 6; i++) {
        C[i] = A[i] + B[i];
    }
    
    int maximum_real_A = A[0];
    for (int i = 0; i < 6; i += 2) {
        if (A[i] > maximum_real_A) {
            maximum_real_A = A[i];
        }
    }
    
    int negative_imaginary_count_B = 0;
    for (int i = 1; i < 6; i += 2) {
        if (B[i] < 0) {
            negative_imaginary_count_B++;
        }
    }
    
    double sum_C = 0;
    for (int i = 0; i < 6; i++) {
        sum_C += C[i];
    }
    double average_C = sum_C / 6;

    printf("Максимальная реальная часть в массиве A: %d\n", maximum_real_A);
    printf("Количество мнимых частей, которые меньше 0 в массиве B: %d\n", negative_imaginary_count_B);
    printf("Среднее арифметическое всех элементов массива C: %.2f\n", average_C);

    return 0;
}






