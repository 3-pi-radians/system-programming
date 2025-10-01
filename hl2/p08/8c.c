/*
  ************************************************************************

  Name         : 8c.c
  Author       : Pankaj Deopa
  Description  : Program using signal system call to catch SIGFPE signal.
  Date         : 1 Oct, 2025

  ************************************************************************
*/


#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handle_sigfpe(int sig) {
    printf("\nCaught SIGFPE");
    exit(1);
}

int main() {
    
    signal(SIGFPE, handle_sigfpe);

    int x = 1 / 0;

    return 0;
}


/*
 ********************************* OUTPUT *************************************

    piradians@3piradians:~/Documents/system_programming/hl2/p08$ cc 8c.c -o 8c
    8c.c: In function ‘main’:
    8c.c:26:15: warning: division by zero [-Wdiv-by-zero]
       26 |     int x = 1 / 0;
          |               ^
    piradians@3piradians:~/Documents/system_programming/hl2/p08$ 

*******************************************************************************
*/
