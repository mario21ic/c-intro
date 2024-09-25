#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h>

#define NUM_PROCESSES 4
#define NUM_THREADS 5
#define NUMBERS_PER_THREAD 5

void *print_numbers(void *arg) {
    int start = *((int *)arg);
    int end = start + NUMBERS_PER_THREAD - 1;

    for (int i = start; i <= end; i++) {
        printf("%d\n", i);
    }

    return NULL;
}

void create_threads(int start, int end) {
    pthread_t threads[NUM_THREADS];
    int start_points[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        start_points[i] = start + i * NUMBERS_PER_THREAD;
        pthread_create(&threads[i], NULL, print_numbers, (void *)&start_points[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
}

int main() {
    pid_t pids[NUM_PROCESSES];
    int start, end;

    for (int i = 0; i < NUM_PROCESSES; i++) {
        start = i * NUM_THREADS * NUMBERS_PER_THREAD;
        end = start + NUM_THREADS * NUMBERS_PER_THREAD - 1;

        if ((pids[i] = fork()) < 0) {
            perror("fork");
            exit(1);
        } else if (pids[i] == 0) {
            create_threads(start, end);
            exit(0);
        }
    }

    for (int i = 0; i < NUM_PROCESSES; i++) {
        waitpid(pids[i], NULL, 0);
    }

    return 0;
}
