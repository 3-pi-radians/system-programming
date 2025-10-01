/*
  ************************************************************************

  Name         : 29.c
  Author       : Pankaj Deopa
  Description  : Program to remove the message queue.
  Date         : 1 Oct, 2025

  ************************************************************************
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main(){

    key_t key = ftok("29.txt", 65);

    int msgid = msgget(key, 0666 | IPC_CREAT);

    if (msgid == -1) {
        printf("Failed to create or access the message queue.\n");
        return 1;
    } else
        printf("Message queue created with ID: %d\n", msgid);

    
    msgctl(msgid, IPC_RMID, NULL); // Now remove the message queue
    printf("Message queue removed.\n");

    return 0;
}

/*
 ********************************** OUTPUT **********************************

    piradians@3piradians:~/Documents/system_programming/hl2/p29$ cc 29.c
    piradians@3piradians:~/Documents/system_programming/hl2/p29$ ./a.out
    Message queue created with ID: 8
    Message queue removed.

******************************************************************************
*/
