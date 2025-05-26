#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void cleanup_handler(void* arg) {
    printf("Cleanup: thread %d is being canceled\n", *(int*)arg);
}

void* thread_func(void* arg) {
    int id = *(int*)arg;
    pthread_cleanup_push(cleanup_handler, arg);
    
    for (int i = 0; i < 5; i++) {
        printf("Thread %d: line %d\n", id, i+1);
        sleep(1);
    }
    
    pthread_cleanup_pop(0);
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