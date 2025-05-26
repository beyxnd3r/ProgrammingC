#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000  
#define MAX_LENGTH 1024 

void reverse_lines(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Ошибка открытия файла");
        return;
    }

    char *lines[MAX_LINES];
    int count = 0;

    
    while (count < MAX_LINES) {
        lines[count] = malloc(MAX_LENGTH);
        if (!lines[count]) {
            perror("Ошибка выделения памяти");
            fclose(file);
            return;
        }
        
        if (!fgets(lines[count], MAX_LENGTH, file)) {
            free(lines[count]);
            break;
        }
        count++;
    }
    fclose(file);

    
    file = fopen(filename, "w");
    if (!file) {
        perror("Ошибка открытия файла для записи");
        return;
    }

    
    for (int i = count - 1; i >= 0; i--) {
        fputs(lines[i], file);
        free(lines[i]);
    }
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Использование: %s <файл>\n", argv[0]);
        return 1;
    }
    reverse_lines(argv[1]);
    return 0;
}
