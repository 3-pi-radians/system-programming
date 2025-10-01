/*
  ************************************************************************

  Name         : 1b.c
  Author       : Pankaj Deopa
  Description  : Program to set a interval timer in 10sec and 10micro second (ITIMER_VIRTUAL)
  Date         : 1 Oct, 2025

  ************************************************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <signal.h>

void handle_t(int signum) {
    printf("Timer expired! (ITIMER_VIRTUAL)\n");
}

int main() {

    struct itimerval timer;
    signal(SIGVTALRM, handle_t);

    timer.it_value.tv_sec = 10;
    timer.it_value.tv_usec = 10;

    timer.it_interval.tv_sec = 10;
    timer.it_interval.tv_usec = 10;
    
    setitimer(ITIMER_VIRTUAL, &timer, NULL);

    while (1);
    return 0;
}

/*
 ******************************************* OUTPUT ********************************

    piradians@3piradians:~/Documents/system_programming/hl2/p01$ cc 1b.c
    piradians@3piradians:~/Documents/system_programming/hl2/p01$ ./a.out
    Timer expired! (ITIMER_VIRTUAL)
    Timer expired! (ITIMER_VIRTUAL)
    Timer expired! (ITIMER_VIRTUAL)
    Timer expired! (ITIMER_VIRTUAL)
    Timer expired! (ITIMER_VIRTUAL)

************************************************************************************
*/
