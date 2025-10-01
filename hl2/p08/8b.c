/*
  ************************************************************************

  Name         : 8b.c
  Author       : Pankaj Deopa
  Description  : Program using signal system call to catch the SIGINT signal.
  Date         : 1 Oct, 2025

  ************************************************************************
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void sigINT(int sig) {
    printf("Caught SIGINT\n");
    exit(0);
}

int main() {

    signal(SIGINT, sigINT);

    while (1) {
        printf("Process is running... \n Press Ctrl+C to stop\n");
        sleep(1);
    }

    return 0;
}

/*
 ************************************ OUTPUT *******************************

    piradians@3piradians:~/Documents/system_programming/hl2/p08$ ./8b
    Process is running... 
     Press Ctrl+C to stop
    Process is running... 
     Press Ctrl+C to stop
    Process is running... 
     Press Ctrl+C to stop
    ^CCaught SIGINT
    piradians@3piradians:~/Documents/system_programming/hl2/p08$ 

****************************************************************************
*/
