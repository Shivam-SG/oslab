#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 5

sem_t room;            
sem_t chopstick[N];   

void *philosopher(void *arg);
void eat(int);

int main() {
    pthread_t tid[N];
    int i, a[N];

    sem_init(&room, 0, 4);   
    for (i = 0; i < N; i++)
        sem_init(&chopstick[i], 0, 1);

    for (i = 0; i < N; i++) {
        a[i] = i;
        pthread_create(&tid[i], NULL, philosopher, &a[i]);
    }

    for (i = 0; i < N; i++)
        pthread_join(tid[i], NULL);

    return 0;
}

void *philosopher(void *arg) {
    int phil = *(int *)arg;

    sem_wait(&room);
    printf("\nPhilosopher %d entered the room", phil);

    sem_wait(&chopstick[phil]);
    sem_wait(&chopstick[(phil + 1) % N]);

    eat(phil);
    sleep(2);

    printf("\nPhilosopher %d finished eating", phil);

    sem_post(&chopstick[phil]);
    sem_post(&chopstick[(phil + 1) % N]);

    sem_post(&room);
    return NULL;
}

void eat(int phil) {
    printf("\nPhilosopher %d is eating", phil);
}


// output 

// Philosopher 0 entered the room
// Philosopher 0 is eating
// Philosopher 1 entered the room
// Philosopher 1 is eating
// Philosopher 2 entered the room
// Philosopher 2 is eating
// Philosopher 3 entered the room
// Philosopher 3 is eating
// Philosopher 0 finished eating
// Philosopher 4 entered the room
// Philosopher 4 is eating
// Philosopher 1 finished eating
// Philosopher 2 finished eating
// Philosopher 3 finished eating
// Philosopher 4 finished eating
