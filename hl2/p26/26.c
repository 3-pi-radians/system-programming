/*
  ************************************************************************

  Name         : 26.c
  Author       : Pankaj Deopa
  Description  : Program to send messages to the message queue. Check $ipcs -q
  Date         : 1 Oct, 2025

  ************************************************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msg_buffer {
    long msg_type;
    char msg_text[256];  
};

int main() {
    key_t key;
    int msqid;
    struct msg_buffer message;

    key = ftok(".", 'A');
    if (key == -1) {
        perror("ftok");
        exit(1);
    }

    msqid = msgget(key, IPC_CREAT | 0666);
    if (msqid == -1) {
        perror("msgget");
        exit(1);
    }

    printf("Message Queue ID: %d\n", msqid);

    message.msg_type = 1;
    printf("Enter message to send: ");
    if (fgets(message.msg_text, 256, stdin) == NULL) {
        perror("fgets");
        exit(1);
    }

    if (msgsnd(msqid, &message, strlen(message.msg_text) + 1, 0) == -1) {
        perror("msgsnd");
        exit(1);
    }

    printf("Message sent to queue successfully!\n");

    return 0;
}


/*
 ******************************** OUTPUT **********************************

    piradians@3piradians:~/Documents/system_programming/hl2/p26$ cc 26.c
    piradians@3piradians:~/Documents/system_programming/hl2/p26$ ./a.out
    Message Queue ID: 2
    Enter message to send: Hi There
    Message sent to queue successfully!
    piradians@3piradians:~/Documents/system_programming/hl2/p26$ ipcs -q

    ------ Message Queues --------
    key        msqid      owner      perms      used-bytes   messages    
    0x410038aa 0          piradians  666        0            0           
    0x41003a23 1          piradians  666        0            0           
    0x41003a24 2          piradians  666        10           1           

    piradians@3piradians:~/Documents/system_programming/hl2/p26$ ./a.out
    Message Queue ID: 2
    Enter message to send: Sending message to message queue id 2
    Message sent to queue successfully!
    piradians@3piradians:~/Documents/system_programming/hl2/p26$ ipcs -q

    ------ Message Queues --------
    key        msqid      owner      perms      used-bytes   messages    
    0x410038aa 0          piradians  666        0            0           
    0x41003a23 1          piradians  666        0            0           
    0x41003a24 2          piradians  666        49           2           

    piradians@3piradians:~/Documents/system_programming/hl2/p26$ 

*****************************************************************************
    */
