#include <stdio.h>
#include <pthread.h>

void* thread_func(void* arg) {
    for (int i = 0; i < 5; i++) {
        printf("Child thread: line %d\n", i+1);
    }
    return NULL;
}

int main() {
    pthread_t thread;
    pthread_create(&thread, NULL, thread_func, NULL);
    
    for (int i = 0; i < 5; i++) {
        printf("Main thread: line %d\n", i+1);
    }
    
    pthread_join(thread, NULL);
    return 0;
}