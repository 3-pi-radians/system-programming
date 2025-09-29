/*
  ************************************************************************

  Name         : 9.c
  Author       : Pankaj Deopa
  Description  : Program to ignore a SIGINT signal then reset the default action of the SIGINT
                   signal - Use signal system call
  Date         : 29 Sept, 2025

  ************************************************************************
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>

int main () {
    printf("Ignoring SIGINT\n");
    signal(SIGINT, SIG_IGN);
    // ignored ctrl+c
    sleep(5);
    printf("\nDefault SIGINT action\n");
    signal(SIGINT, SIG_DFL);
    
    sleep(5);
    return(0);
}


/*
 **************************************** OUTPUT ***********************************

    piradians@3piradians:~/Documents/system_programming/hl2/p09$ cc 9.c
    piradians@3piradians:~/Documents/system_programming/hl2/p09$ ./a.out
    Ignoring SIGINT
    ^C^C^C^C^C^C^C
    Default SIGINT action
    ^C
    piradians@3piradians:~/Documents/system_programming/hl2/p09$

************************************************************************************
*/
