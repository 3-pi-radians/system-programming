/*
  ************************************************************************

  Name         : 1a.c
  Author       : Pankaj Deopa
  Description  : Program to set a interval timer in 10sec and 10micro second (ITIMER_REAL)
  Date         : 1 Oct, 2025

  ************************************************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <signal.h>

void handle_t(int signum) {
    printf("Timer expired! (ITIMER_REAL)\n");
}

int main() {

    struct itimerval timer;
    signal(SIGALRM, handle_t);
    
    timer.it_value.tv_sec = 10;
    timer.it_value.tv_usec = 10;

    timer.it_interval.tv_sec = 10;
    timer.it_interval.tv_usec = 10;

    setitimer(ITIMER_REAL, &timer, NULL);
    while (1);

    return 0;
}
/*
 ******************************** OUTPUT ************************************

    piradians@3piradians:~/Documents/system_programming/hl2/p01$ cc 1a.c
    piradians@3piradians:~/Documents/system_programming/hl2/p01$ ./a.out
    Timer expired! (ITIMER_REAL)
    Timer expired! (ITIMER_REAL)
    Timer expired! (ITIMER_REAL)
    Timer expired! (ITIMER_REAL)
    ^C
    piradians@3piradians:~/Documents/system_programming/hl2/p01$ 

********************************************************************************
*/
