#include <stdio.h>
#include <pthread.h>
#include <string.h>

void* thread_func(void* arg) {
    char* msg = (char*)arg;
    for (int i = 0; i < 5; i++) {
        printf("%s %d\n", msg, i+1);
    }
    return NULL;
}

int main() {
    pthread_t threads[4];
    char* messages[] = {
        "Thread 1 says: line",
        "Thread 2 says: line",
        "Thread 3 says: line",
        "Thread 4 says: line"
    };
    
    for (int i = 0; i < 4; i++) {
        pthread_create(&threads[i], NULL, thread_func, messages[i]);
    }
    
    for (int i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }
    
    return 0;
}