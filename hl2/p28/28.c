/*
  ******************************************************************************

  Name         : 28.c
  Author       : Pankaj Deopa
  Description  : Program to change the exiting message queue permission (using msqid_ds structure)
  Date         : 1 Oct, 2025

  ******************************************************************************
*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>

int main()
{
    key_t key = ftok(".", 'a');

    int msqid = msgget(key, IPC_CREAT | 0666);
    struct msqid_ds st;

    msgctl(msqid, IPC_STAT, &st);
    printf("Current access Permissions - %o\n", st.msg_perm.mode);

    st.msg_perm.mode = 0777;
    msgctl(msqid, IPC_SET, &st);
    msgctl(msqid, IPC_STAT, &st);
    printf("New access Permissions - %o\n", st.msg_perm.mode);
    return 0;
}

/*
 ********************************* OUTPUT *******************************

    piradians@3piradians:~/Documents/system_programming/hl2/p28$ cc 28.c
    piradians@3piradians:~/Documents/system_programming/hl2/p28$ ./a.out
    Current access Permissions - 666
    New access Permissions - 777
    piradians@3piradians:~/Documents/system_programming/hl2/p28$ 

************************************************************************
*/
