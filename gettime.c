#include "philo.h"
#include <stdio.h>
#include <pthread.h>

// int shared_variable = 0;

void* increment(void* arg)
{
    int i = (int)arg;
    i++; // This is a read-modify-write operation

    return NULL;
}

int main() {
    pthread_t t1, t2;

    int i = 0;
    pthread_create(&t1, NULL, &increment, &i);
    // pthread_create(&t2, NULL, increment, NULL);

    // pthread_join(t1, NULL);
    pthread_join(t1, NULL);

    printf("Final value: %d\n", i);
    return 0;
}
