/*
  ************************************************************************

  Name         : 8e.c
  Author       : Pankaj Deopa
  Description  : Program using signal system call to catch SIGALRM signal (use setitimer system call).
  Date         : 1 Oct, 2025

  ************************************************************************
*/

#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void sigALRM(int sig) {
    printf("Caught SIGALRM\n");
}

int main() {

    struct itimerval timer;
    signal(SIGALRM, sigALRM);

    // Set timer for 3 seconds, no repeating
    timer.it_value.tv_sec = 3;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_REAL, &timer, NULL);

    printf("Waiting for the alarm...\n");
    pause();
    return 0;
}

/*
 ************************************** OUTPUT *********************************

    piradians@3piradians:~/Documents/system_programming/hl2/p08$ cc 8e.c -o 8e
    piradians@3piradians:~/Documents/system_programming/hl2/p08$ ./8e
    Waiting for the alarm...
    Caught SIGALRM
    piradians@3piradians:~/Documents/system_programming/hl2/p08$

*******************************************************************************
 */
