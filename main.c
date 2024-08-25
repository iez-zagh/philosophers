#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct s_philo
{
    int index;
    int meals_eaten;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
}   t_philo;

int main() {
    int num_philosophers = 5;

    // Step 1: Allocate memory for an array of t_philo structs
    t_philo *philosophers = malloc(num_philosophers * sizeof(t_philo));
    if (!philosophers) {
        perror("Failed to allocate memory for philosophers");
        exit(EXIT_FAILURE);
    }

    // Step 2: Initialize the struct members for each philosopher
    for (int i = 0; i < num_philosophers; i++) {
        philosophers[i].index = i + 1;
        philosophers[i].meals_eaten = 0;
        philosophers[i].left_fork = NULL;  // Initialize to NULL or assign pointers to actual forks
        philosophers[i].right_fork = NULL; // Initialize to NULL or assign pointers to actual forks
    }

    // Step 3: Use the structs in the array
    for (int i = 0; i < num_philosophers; i++) {
        printf("Philosopher %d has eaten %d meals.\n", philosophers[i].index, philosophers[i].meals_eaten);
    }

    // Step 4: Free the allocated memory
    free(philosophers);

    return 0;
}
