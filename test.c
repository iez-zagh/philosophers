#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/wait.h>
#include <semaphore.h>
#include <fcntl.h>  // for O_* constants

#define NUM_PROCESSES 5

sem_t *sem;

void critical_section(int process_id) {
    printf("Process %d entering critical section.\n", process_id);
    sleep(1);  // Simulate some work
    printf("Process %d leaving critical section.\n", process_id);
}

void create_processes() {
    for (int i = 0; i < NUM_PROCESSES; i++) {
        pid_t pid = fork();
        if (pid == 0) {
            // Child process
            sem_wait(sem);  // Wait (lock semaphore)
            critical_section(i);
            sem_post(sem);  // Signal (unlock semaphore)
            exit(0);  // Terminate child process
        }
    }
    // Parent process waits for all child processes to finish
    for (int i = 0; i < NUM_PROCESSES; i++) {
        wait(0);
    }
}

int main() {
    sem = sem_open("/mysem", O_CREAT, 0644, 1);  // Named semaphore with initial value 1
    if (sem == SEM_FAILED) {
        perror("sem_open");
        exit(EXIT_FAILURE);
    }
	while(1);
	create_processes();
	sem_close(sem);
	sem_unlink("/mysem");  // Remove named semaphore
	return 0;
}