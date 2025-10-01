/*
  ************************************************************************

  Name         : 25.c
  Author       : Pankaj Deopa
  Description  : Program to print a message queue's (use msqid_ds and ipc_perm structures)
                    a. access permission
                    b. uid, gid
                    c. time of last message sent and received
                    d. time of last change in the message queue
                    d. size of the queue
                    f. number of messages in the queue
                    g. maximum number of bytes allowed
                    h. pid of the msgsnd and msgrcv
  Date         : 1 Oct, 2025

  ************************************************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <time.h>

int main() {
    key_t key;
    int msqid;
    struct msqid_ds buf;

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

    if (msgctl(msqid, IPC_STAT, &buf) == -1) {
        perror("msgctl");
        exit(1);
    }

    printf("Message Queue ID: %d\n", msqid);
    printf("Access Permissions: %o\n", buf.msg_perm.mode);
    printf("UID: %d, GID: %d\n", buf.msg_perm.uid, buf.msg_perm.gid);

    printf("Time of last message sent: %s", buf.msg_stime ? ctime(&buf.msg_stime) : "Not yet sent\n");
    printf("Time of last message received: %s", buf.msg_rtime ? ctime(&buf.msg_rtime) : "Not yet received\n");
    printf("Time of last change: %s", buf.msg_ctime ? ctime(&buf.msg_ctime) : "Not yet changed\n");

    printf("Current number of bytes in queue: %lu\n", buf.__msg_cbytes);
    printf("Number of messages in queue: %lu\n", buf.msg_qnum);
    printf("Maximum number of bytes allowed: %lu\n", buf.msg_qbytes);

    printf("PID of last msgsnd: %d\n", buf.msg_lspid);
    printf("PID of last msgrcv: %d\n", buf.msg_lrpid);

    return 0;
}

/*
 *********************************** OUTPUT *********************************

    piradians@3piradians:~/Documents/system_programming/hl2/p25$ cc 25.c
    piradians@3piradians:~/Documents/system_programming/hl2/p25$ ./a.out
    Message Queue ID: 1
    Access Permissions: 666
    UID: 1000, GID: 1000
    Time of last message sent: Not yet sent
    Time of last message received: Not yet received
    Time of last change: Wed Oct  1 09:47:58 2025
    Current number of bytes in queue: 0
    Number of messages in queue: 0
    Maximum number of bytes allowed: 16384
    PID of last msgsnd: 0
    PID of last msgrcv: 0
    piradians@3piradians:~/Documents/system_programming/hl2/p25$

*****************************************************************************
*/
