/*
  ************************************************************************

  Name         : 1c.c
  Author       : Pankaj Deopa
  Description  : Program to set a interval timer in 10sec and 10micro second (ITIMER_PROF)
  Date         : 1 Oct, 2025

  ************************************************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>

void handle_t(int signum) {
    write(STDOUT_FILENO, "Timer expired! (ITIMER_PROF)\n", 29);
}

int main() {
    struct itimerval timer;
    signal(SIGPROF, handle_t);

    timer.it_value.tv_sec = 1;   
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 1;
    timer.it_interval.tv_usec = 0;

    if (setitimer(ITIMER_PROF, &timer, NULL) == -1) {
        perror("setitimer");
        exit(1);
    }

    while (1); // keep process busy

    return 0;
}

/*
 ******************************* OUTPUT **************************************

    piradians@3piradians:~/Documents/system_programming/hl2/p01$ ./a.out
    Timer expired! (ITIMER_PROF)
    Timer expired! (ITIMER_PROF)
    Timer expired! (ITIMER_PROF)
    Timer expired! (ITIMER_PROF)
    Timer expired! (ITIMER_PROF)
    Timer expired! (ITIMER_PROF)

*******************************************************************************
*/
