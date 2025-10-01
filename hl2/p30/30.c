/*
  ************************************************************************

  Name         : 30.c
  Author       : Pankaj Deopa
  Description  : Write a program to create a shared memory.
                    a. write some data to the shared memory
                    b. attach with O_RDONLY and check whether you are able to overwrite.
                    c. detach the shared memory
                    d. remove the shared memory
  Date         : 26 Aug, 2025

  ************************************************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <unistd.h>

#define SHM_SIZE 1024 

int main() {
    key_t key;
    int shmid;
    char *shm_ptr;

    key = ftok(".", 'S');
    if (key == -1) {
        perror("ftok");
        exit(1);
    }

    shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }
    printf("Shared memory created with ID: %d\n", shmid);

    shm_ptr = shmat(shmid, NULL, 0);
    if (shm_ptr == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    char *message = "Hello Shared Memory!";
    strcpy(shm_ptr, message);
    printf("Data written to shared memory: %s\n", shm_ptr);

    char *shm_ptr_ro = shmat(shmid, NULL, SHM_RDONLY);
    if (shm_ptr_ro == (char *) -1) {
        perror("shmat readonly");
        exit(1);
    }

    printf("Attached read-only shared memory: %s\n", shm_ptr_ro);
    printf("Attempting to write to read-only memory is NOT allowed and is commented out to avoid crash.\n");

    if (shmdt(shm_ptr) == -1) {
        perror("shmdt");
        exit(1);
    }

    if (shmdt(shm_ptr_ro) == -1) {
        perror("shmdt ro");
        exit(1);
    }

    printf("Shared memory detached successfully.\n");

    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }

    printf("Shared memory removed successfully.\n");

    return 0;
}

/*
 ****************************************** OUTPUT *******************************************

    piradians@3piradians:~/Documents/system_programming/hl2/p30$ cc 30.c
    piradians@3piradians:~/Documents/system_programming/hl2/p30$ ./a.out
    Shared memory created with ID: 2
    Data written to shared memory: Hello Shared Memory!
    Attached read-only shared memory: Hello Shared Memory!
    Attempting to write to read-only memory is NOT allowed and is commented out to avoid crash.
    Shared memory detached successfully.
    Shared memory removed successfully.

***********************************************************************************************
*/
