/*
  ************************************************************************

  Name         : 13b.c
  Author       : Pankaj Deopa
  Description  : Program to send kill signal for a given PID.
  Date         : 29 Sept, 2025

  ************************************************************************
*/

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main() {

    int pid;
    printf("Enter pid of process to stop: \n");
    scanf("%d", &pid);

    printf("Sending SIGSTOP signal to process: %d\n", pid);
    kill(pid, SIGSTOP);

    printf("SIGSTOP signal sent\n");
    printf("Exiting current process (sender)\n");
    return (0);
}


/*
 **************************************** OUTPUT ***********************************

    piradians@3piradians:~/Documents/system_programming/hl2/p13$ cc 13b.c -o sender
    piradians@3piradians:~/Documents/system_programming/hl2/p13$ ./sender
    Enter pid of process to stop: 
    11542
    Sending SIGSTOP signal to process: 11542
    SIGSTOP signal sent
    Exiting current process (sender)
    piradians@3piradians:~/Documents/system_programming/hl2/p13$

************************************************************************************
*/
