/*
  ************************************************************************

  Name         : 31.c
  Author       : Pankaj Deopa
  Description  : Program to create a semaphore and initialize value to the semaphore.
                    a. create a binary semaphore
                    b. create a counting semaphore
  Date         : 1 Oct, 2025

  ************************************************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>

union semun {
    int val;              
    struct semid_ds *buf; 
    unsigned short *array; 
    struct seminfo *__buf; 
};

int main() {
    key_t key;
    int semid;
    union semun sem_union;

    key = ftok(".", 'S');
    if (key == -1) {
        perror("ftok");
        exit(1);
    }

    // binary semaphore
    semid = semget(key, 1, IPC_CREAT | 0666);
    if (semid == -1) {
        perror("semget binary");
        exit(1);
    }
    printf("Binary semaphore created with ID: %d\n", semid);

    sem_union.val = 1;
    if (semctl(semid, 0, SETVAL, sem_union) == -1) {
        perror("semctl binary init");
        exit(1);
    }
    printf("Binary semaphore initialized to %d\n", sem_union.val);

    // Counting Semaphore
    key = ftok(".", 'C');
    if (key == -1) {
        perror("ftok counting");
        exit(1);
    }

    int n_sems = 5;
    semid = semget(key, n_sems, IPC_CREAT | 0666);
    if (semid == -1) {
        perror("semget counting");
        exit(1);
    }
    printf("Counting semaphore set created with ID: %d\n", semid);

    unsigned short sem_values[n_sems];
    for (int i = 0; i < n_sems; i++) {
        sem_values[i] = i + 1; // example initial values: 1,2,3,4,5
    }
    sem_union.array = sem_values;
    if (semctl(semid, 0, SETALL, sem_union) == -1) {
        perror("semctl counting init");
        exit(1);
    }

    printf("Counting semaphores initialized to: ");
    for (int i = 0; i < n_sems; i++) printf("%d ", sem_values[i]);
    printf("\n");

    return 0;
}

/*
 ************************************ OUTPUT **********************************

    piradians@3piradians:~/Documents/system_programming/hl2/p31$ cc 31.c
    piradians@3piradians:~/Documents/system_programming/hl2/p31$ ./a.out
    Binary semaphore created with ID: 1
    Binary semaphore initialized to 1
    Counting semaphore set created with ID: 2
    Counting semaphores initialized to: 1 2 3 4 5 
    piradians@3piradians:~/Documents/system_programming/hl2/p31$ 

********************************************************************************
*/
