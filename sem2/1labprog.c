#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 100 

struct Student {
    char name[65];
    int math;
    int physics;
    int informatics;
    int total;
};


struct Student addStudent(const char *name, int math, int physics, int informatics) {
    struct Student newStudent;
    strncpy(newStudent.name, name, 64);
    newStudent.name[64] = '\0'; 
    newStudent.math = math;
    newStudent.physics = physics;
    newStudent.informatics = informatics;
    newStudent.total = math + physics + informatics;
    return newStudent;
}


void printStudentInfo(struct Student student) {
    printf("Имя: %s, Мат.: %d, Физ.: %d, Инфа: %d, Общий: %d\n",
           student.name, student.math, student.physics, student.informatics, student.total);
}


void selectionSort(struct Student arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int maxIdx = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j].total > arr[maxIdx].total) {
                maxIdx = j;
            }
        }
        if (maxIdx != i) {
            struct Student temp = arr[i];
            arr[i] = arr[maxIdx];
            arr[maxIdx] = temp;
        }
    }
}


void countingSort(struct Student arr[], int size) {
    struct Student output[size];
    int count[301] = {0};

    for (int i = 0; i < size; i++)
        count[arr[i].total]++;

    for (int i = 1; i <= 300; i++)
        count[i] += count[i - 1];

    for (int i = size - 1; i >= 0; i--) {
        output[count[arr[i].total] - 1] = arr[i];
        count[arr[i].total]--;
    }

    for (int i = 0; i < size; i++)
        arr[i] = output[i];
}



int main() {
    srand(time(NULL));
    struct Student students[N];
    
    
    for (int i = 0; i < N; i++) {
        char name[65];
        snprintf(name, 65, "Студент№%d", i + 1);
        students[i] = addStudent(name, rand() % 101, rand() % 101, rand() % 101);
    }

    printf("До сортировки:\n");
    for (int i = 0; i < N; i++) printStudentInfo(students[i]);

    struct timespec start, end;
    double time_taken;

    clock_gettime(CLOCK_MONOTONIC, &start);
    selectionSort(students, N);
    clock_gettime(CLOCK_MONOTONIC, &end);
    time_taken = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("\nSelection Sort заняло времени %f \n", time_taken);
    printf("\nРазмер данных для Selection Sort: %lu байт\n", N * sizeof(struct Student));

    printf("Selection Sort:\n");
    for (int i = 0; i < N; i++) printStudentInfo(students[i]);

    clock_gettime(CLOCK_MONOTONIC, &start);
    countingSort(students, N);
    clock_gettime(CLOCK_MONOTONIC, &end);
    time_taken = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("\nCounting Sort заняло %f\n", time_taken);
    printf("Размер данных для Counting Sort: %lu байт\n", N * sizeof(struct Student));
    for (int i = 0; i < N; i++) printStudentInfo(students[i]);
    
    


    //system("cat /proc/cpuinfo");
    return 0;
}
