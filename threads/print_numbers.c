#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4
#define NUMBERS_PER_THREAD 25

void *print_numbers(void *arg) {
    int start = *((int *)arg);
    int end = start + NUMBERS_PER_THREAD - 1;

    for (int i = start; i <= end; i++) {
        printf("%d\n", i);
    }

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int start_points[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        start_points[i] = i * NUMBERS_PER_THREAD;
        pthread_create(&threads[i], NULL, print_numbers, (void *)&start_points[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
