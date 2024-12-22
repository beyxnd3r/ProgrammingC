#include <stdio.h>
#include "structh.h"
#include <locale.h>
#include <wchar.h>


int main() {
    setlocale(LC_ALL, "");
    Time fullstart, fullend;
    int total = 0;
    for (int i=0; i<7; i++){
        printf("Введите часы и минуты начала и завершения работы на %d день\n", i+1);

        
        printf("Часы начала: ");
        scanf("%d", &fullstart.hours);
        printf("Минуты начала: ");
        scanf("%d", &fullstart.minutes);

        
        printf("Часы окончания: ");
        scanf("%d", &fullend.hours);
        printf("Минуты окончания: ");
        scanf("%d", &fullend.minutes);

        total += work(fullstart,fullend);


    }

    printf("Общее время работы: %d", total);

    return 0;

    





}