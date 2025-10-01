/*
  ************************************************************************

  Name         : 27a.c 
  Author       : Pankaj Deopa
  Description  : Program to receive messages from the message queue.
		            a. With 0 as a flag
		            b. with IPC_NOWAIT as a flag
  Date         : 1 Oct, 2025

  ************************************************************************
*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>

struct msg {
    long type;
    char text[50];
};

int main() {

    key_t key = ftok(".", 'A');
    struct msg message;
    int msqid = msgget(key, 0);
   
   int flag, mtype;
    printf("Choose flag:\n1.) 0 (blocking)\n2.) IPC_NOWAIT (non-blocking)\n=> ");
    scanf("%d", &flag);

    printf("Enter message type:\n");
    scanf("%d", &mtype);
    int recv_flag;
    if(flag == 2){
        recv_flag = IPC_NOWAIT;
    }else{
        recv_flag = 0;
    }
    if (msgrcv(msqid, &message, sizeof(message.text), mtype, recv_flag) == -1) {
        perror("msgrcv");
    }else {
        printf("Message: %s\n", message.text);
    }

    return 0;
}

/*
 ********************************************** OUTPUT **************************************

                                            TERMINAL 1

    piradians@3piradians:~/Documents/system_programming/hl2/p27$ cc 27a.c
    piradians@3piradians:~/Documents/system_programming/hl2/p27$ ./a.out
    Choose flag:
    1.) 0 (blocking)
    2.) IPC_NOWAIT (non-blocking)
    => 1
    Enter message type:
    3
    Message: sending message to message queue

    piradians@3piradians:~/Documents/system_programming/hl2/p27$ 

=============================================================================================

                                           TERMINAL 2

    piradians@3piradians:~/Documents/system_programming/hl2/p27$ cc 27b.c 
    piradians@3piradians:~/Documents/system_programming/hl2/p27$ ./a.out Enter 
    message type (positive integer): 3 
    Enter message text: sending message to message queue
    Message sent successfully.
    piradians@3piradians:~/Documents/system_programming/hl2/p27$ 

**********************************************************************************************
*/
