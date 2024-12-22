#include <stdio.h>

int main() {
    int rows;
    printf("Введите размер матрицы (2 или 3): ");
    scanf("%d", &rows);

    if (rows != 2 && rows != 3) {
        printf("Неверный размер матрицы. Пожалуйста, введите 2 или 3");
        return 0;
    }

    int a[3][3]; 
    int b[3];    
    
    
    printf("Введите элементы матрицы %d x %d", rows, rows);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows; j++) {
            printf("Элемент a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    
    printf("Введите элементы b (размер %d):", rows);
    for (int i = 0; i < rows; i++) {
        printf("Элемент b[%d]: ", i);
        scanf("%d", &b[i]);
    }

    int delta1, delta2, delta;
    int deltax, deltay, deltaz;
    int realx, realy, realz;

    //2x2
    if (rows == 2) {
        delta1 = a[0][0] * a[1][1];
        delta2 = a[0][1] * a[1][0];
        delta = delta1 - delta2;

        if (delta == 0) {
            printf("Определитель равен 0, матрица не решается");
            return 0;
        }

        deltax = b[0] * a[1][1] - b[1] * a[1][0];
        deltay = a[0][0] * b[1] - a[0][1] * b[0];
        realx = deltax / delta;
        realy = deltay / delta;

        printf("Определитель: %d\n x1=%d\n x2=%d\n", delta, realx, realy);
    } 
    //3x3
    else if (rows == 3) {
        delta = a[0][0] * (a[1][1] * a[2][2] - a[1][2] * a[2][1])
              - a[0][1] * (a[1][0] * a[2][2] - a[1][2] * a[2][0])
              + a[0][2] * (a[1][0] * a[2][1] - a[1][1] * a[2][0]);

        if (delta == 0) {
            printf("Определитель равен 0, матрица не решается");
            return 0;
        }

        deltax = b[0] * (a[1][1] * a[2][2]) + (a[1][0] * a[2][1] * b[2]) + (a[2][0] * b[1] * a[1][2])
                - (a[2][0] * a[1][1] * b[2]) - (b[0] * a[2][1] * a[1][2]) - (a[1][0] * b[1] * a[2][2]);

        deltay = (a[0][0] * b[1] * a[2][2]) + (b[0] * a[2][1] * a[0][2]) + (a[2][0] * a[0][1] * b[2])
                - (a[2][0] * b[1] * a[0][2]) - (a[0][0] * a[2][1] * b[2]) - (b[0] * a[0][1] * a[2][2]);

        deltaz = (a[0][0] * a[1][1] * b[2]) + (a[1][0] * b[1] * a[0][2]) + (b[0] * a[0][1] * a[1][2])
                - (b[0] * a[1][1] * a[0][2]) - (a[0][0] * b[1] * a[1][2]) - (a[1][0] * a[0][1] * b[2]);

        realx = deltax / delta;
        realy = deltay / delta;
        realz = deltaz / delta;

        printf("Определитель: %d\n x1=%d\n x2=%d\n x3=%d\n", delta, realx, realy, realz);
    } else {
        printf("Неверный размер матрицы.n");
    }

    return 0;
}
