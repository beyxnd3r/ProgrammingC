#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
    struct Node* special;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    newNode->special = NULL;
    return newNode;
}

void append(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

Node* getTail(Node* head) {
    if (head == NULL) return NULL;
    while (head->next != NULL) {
        head = head->next;
    }
    return head;
}

void navigateList(Node* start, Node* s, Node* a0) {
    Node* current = s;
    char command;

    printf("Управление: W/8 - ведет к a_0, S/2 - ведет к S, A/4 - влево, D/6 - вправо\n");
    printf("Начинаем с S (a_n): %d\n", current->data);

    while (1) {
        printf("Текущий узел: %d\n", current->data);
        printf("Введите команду (WASD/8462, Q - выход): ");
        scanf(" %c", &command);

        switch (command) {
            case 'D': case 'd': case '6': 
                if (current->next) {
                    current = current->next;
                } else {
                    printf("Достигнут конец списка. Вернуться в S? (Y/N): ");
                    char choice;
                    scanf(" %c", &choice);
                    if (choice == 'Y' || choice == 'y') {
                        current = s;
                    }
                }
                break;

            case 'A': case 'a': case '4':
                if (current->prev) {
                    current = current->prev;
                } else {
                    printf("Вы в начале списка!\n");
                }
                break;

            case 'W': case 'w': case '8':
                current = a0;
                break;

            case 'S': case 's': case '2':
                current = s;
                break;

            case 'Q': case 'q':
                return;

            default:
                printf("Некорректная команда!\n");
        }
    }
}

int main() {
    Node* head = NULL;
    Node* S = NULL;
    Node* a0 = NULL;
    int value;

    printf("Введите элементы списка (0 для завершения ввода):\n");
    while (1) {
        scanf("%d", &value);
        if (value == 0) break;
        append(&head, value);
    }

    if (head == NULL) {
        printf("Список пуст!\n");
        return 0;
    }

    a0 = createNode(-1);
    printf("Создан узел a_0 со значением %d\n", a0->data);

    S = getTail(head);

    printf("Указатель S установлен на a_n: %d\n", S->data);

    Node* temp = head;
    while (temp != NULL) {
        temp->special = a0;
        temp = temp->next;
    }

    navigateList(head, S, a0);

    temp = head;
    while (temp != NULL) {
        Node* next = temp->next;
        free(temp);
        temp = next;
    }
    free(a0);

    return 0;
}