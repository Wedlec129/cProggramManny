#include <pthread.h>
#include <stdio.h>

typedef struct {
    int from;
    int to;
} Arg;

void* func (void* arg) {
    Arg args = *(Arg*)arg;
    for (int i = args.from; i < args.to; i++) {
        fprintf(stderr, "%d ", i);
    }
    return NULL;
}

int main () {
    pthread_t thread1, thread2;
    Arg arg1 = {10, 100};
    Arg arg2 = {0, 90};
    pthread_create(&thread1, NULL, func, (void*)&arg1);
    pthread_create(&thread2, NULL, func, (void*)&arg2);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    fprintf(stderr, "\n");
    return 0;
}