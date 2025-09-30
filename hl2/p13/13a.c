/*
  ************************************************************************

  Name         : 13a.c
  Author       : Pankaj Deopa
  Description  : Program waiting to catch the SIGSTOP signal.
  Date         : 29 Sept, 2025

  ************************************************************************
*/

#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <bits/sigaction.h>

void catch (int sig)
{
    printf("Signal Caught - %d\n", sig);
    exit(0);
}

int main() {

    printf("The PID of process: %d\n", getpid());

    struct sigaction ac;
    memset(&ac, 0, sizeof(ac));
    
    ac.sa_handler = catch; // The handler will be ignored, as SIGSTOP and SIGKILL can not be caught.
    for (;;)
    {
        sigaction(SIGSTOP, &ac, NULL);
    }
    return (0);
}
/*
 ************************************ OUTPUT ******************************************

    piradians@3piradians:~/Documents/system_programming/hl2/p13$ cc 13a.c -o catcher
    piradians@3piradians:~/Documents/system_programming/hl2/p13$ ./catcher
    The PID of process: 11542

    [1]+  Stopped                 ./catcher
    piradians@3piradians:~/Documents/system_programming/hl2/p13$ 

******************************************************************************************
*/


