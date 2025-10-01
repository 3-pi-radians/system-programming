/*
  ************************************************************************

  Name         : 8d.c
  Author       : Pankaj Deopa
  Description  : Program using signal system call to catch the SIGALRM signal. (use alarm system call)
  Date         : 1 Oct, 2025

  ************************************************************************
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sigALRM(int sig) {
    printf("Caught SIGALRM\n");
}

int main() {

    signal(SIGALRM, sigALRM);
    
    alarm(3); 

    printf("Waiting for the alarm...\n");
    pause();

    return 0;
}
/*
 ************************************ OUTPUT ***********************************

    piradians@3piradians:~/Documents/system_programming/hl2/p08$ cc 8d.c -o 8d
    piradians@3piradians:~/Documents/system_programming/hl2/p08$ ./8d
    Waiting for the alarm...
    Caught SIGALRM
    piradians@3piradians:~/Documents/system_programming/hl2/p08$ 

********************************************************************************
*/
