#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4
#define RANGE 100

pthread_mutex_t lock;

void *print_range(void *arg) {
    int thread_part = *((int *)arg);

    int start = thread_part * (RANGE / NUM_THREADS);
    int end = (thread_part + 1) * (RANGE / NUM_THREADS);

    for (int i = start; i < end; i++) {
        pthread_mutex_lock(&lock);
        printf("%d ", i);
        pthread_mutex_unlock(&lock);
    }

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS];

    if (pthread_mutex_init(&lock, NULL) != 0) {
        printf("\n mutex init has failed\n");
        return 1;
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_args[i] = i;
        if (pthread_create(&threads[i], NULL, print_range, (void *)&thread_args[i]) != 0) {
            printf("Failed to create thread\n");
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&lock);

    return 0;
}
