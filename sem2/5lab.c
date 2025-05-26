#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#pragma pack(push, 1)
typedef struct {
    char destination[50];
    int trainNumber;
    int departureTime[2]; 
} Train;
#pragma pack(pop)

void createFile(const char* filename, int N) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        perror("Не удалось создать файл");
        exit(EXIT_FAILURE);
    }

    Train trains[N];
    printf("Введите данные о %d поездах:\n", N);
    for (int i = 0; i < N; i++) {
        printf("\nПоезд #%d\n", i + 1);
        
        printf("Название пункта назначения: ");
        scanf("%49s", trains[i].destination);
        
        printf("Номер поезда: ");
        scanf("%d", &trains[i].trainNumber);
        
        printf("Время отправления (часы минуты): ");
        scanf("%d %d", &trains[i].departureTime[0], &trains[i].departureTime[1]);
    }

    fwrite(trains, sizeof(Train), N, file);
    fclose(file);
    printf("\nФайл %s успешно создан.\n", filename);
}

void searchInFile(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        perror("Не удалось открыть файл");
        exit(EXIT_FAILURE);
    }

    int choice;
    printf("\nПо какому полю выполнить поиск?\n");
    printf("1. Название пункта назначения\n");
    printf("2. Номер поезда\n");
    printf("3. Время отправления\n");
    printf("Выберите вариант (1-3): ");
    scanf("%d", &choice);

    Train train;
    int found = 0;

    switch (choice) {
        case 1: {
            char searchDest[50];
            printf("Введите название пункта назначения: ");
            scanf("%49s", searchDest);
            
            while (fread(&train, sizeof(Train), 1, file)) {
                if (strcmp(train.destination, searchDest) == 0) {
                    printf("Найден поезд: %s, №%d, отправление в %02d:%02d\n",
                           train.destination, train.trainNumber,
                           train.departureTime[0], train.departureTime[1]);
                    found = 1;
                }
            }
            break;
        }
        case 2: {
            int searchNumber;
            printf("Введите номер поезда: ");
            scanf("%d", &searchNumber);
            
            while (fread(&train, sizeof(Train), 1, file)) {
                if (train.trainNumber == searchNumber) {
                    printf("Найден поезд: %s, №%d, отправление в %02d:%02d\n",
                           train.destination, train.trainNumber,
                           train.departureTime[0], train.departureTime[1]);
                    found = 1;
                }
            }
            break;
        }
        case 3: {
            int hours, minutes;
            printf("Введите время отправления (часы минуты): ");
            scanf("%d %d", &hours, &minutes);
            
            while (fread(&train, sizeof(Train), 1, file)) {
                if (train.departureTime[0] == hours && train.departureTime[1] == minutes) {
                    printf("Найден поезд: %s, №%d, отправление в %02d:%02d\n",
                           train.destination, train.trainNumber,
                           train.departureTime[0], train.departureTime[1]);
                    found = 1;
                }
            }
            break;
        }
        default:
            printf("Неверный выбор.\n");
    }

    if (!found) {
        printf("Поезда с указанными параметрами не найдены.\n");
    }

    fclose(file);
}

int main() {
    const char* filename = "Train.dat";
    int N;
    
    printf("Сколько записей о поездах вы хотите добавить? ");
    scanf("%d", &N);
    
    createFile(filename, N);
    searchInFile(filename);
    
    return 0;
}