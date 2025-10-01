/*
  ************************************************************************

  Name         : 24.c
  Author       : Pankaj Deopa
  Description  : Program to create a message queue and print the key and message queue id.
  Date         : 1 Oct, 2025

  ************************************************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() {
    key_t key;
    int msgid;

    key = ftok(".", 'A');
    if (key == -1) {
        perror("ftok");
        exit(1);
    }

    msgid = msgget(key, IPC_CREAT | 0666);
    if (msgid == -1) {
        perror("msgget");
        exit(1);
    }

    printf("Message Queue created successfully!\n");
    printf("Key: %d\n", key);
    printf("Message Queue ID: %d\n", msgid);

    return 0;
}

/*
 ********************************* OUTPUT *********************************

    piradians@3piradians:~/Documents/system_programming/hl2/p24$ cc 24.c
    piradians@3piradians:~/Documents/system_programming/hl2/p24$ ./a.out
    Message Queue created successfully!
    Key: 1090533546
    Message Queue ID: 0
    piradians@3piradians:~/Documents/system_programming/hl2/p24$

**************************************************************************
 */
