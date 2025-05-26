#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* thread_func(void* arg) {
    int id = *(int*)arg;
    for (int i = 0; i < 5; i++) {
        printf("Thread %d: line %d\n", id, i+1);
        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t threads[4];
    int ids[] = {1, 2, 3, 4};
    
    for (int i = 0; i < 4; i++) {
        pthread_create(&threads[i], NULL, thread_func, &ids[i]);
    }
    
    sleep(2);
    for (int i = 0; i < 4; i++) {
        pthread_cancel(threads[i]);
    }
    
    printf("Main thread: all child threads canceled\n");
    return 0;
}