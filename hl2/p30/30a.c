/*
  ************************************************************************

  Name         : 30a.c
  Author       : Pankaj Deopa
  Description  : Write a program to create a shared memory and  write some data to the shared memory
  Date         : 1 Oct, 2025

  ************************************************************************
*/

#include <stdio.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/ipc.h>

int main() {
    key_t key = ftok(".", 'a');
    int shmid = shmget(key, 1024, IPC_CREAT | 0666); 
    char *data = shmat(shmid, (void *)0, 0);
    printf("Enter text to put in shared memory: ");
    scanf("%[^\n]s", data);
    printf("Write successful\n");
    
    return 0;
}

/*
 ******************************** OUTPUT *************************************

    piradians@3piradians:~/Documents/system_programming/hl2/p30$ cc 30a.c -o a
    piradians@3piradians:~/Documents/system_programming/hl2/p30$ ./a
    Enter text to put in shared memory: Hi There
    Write successful
    piradians@3piradians:~/Documents/system_programming/hl2/p30$ 

******************************************************************************
*/
