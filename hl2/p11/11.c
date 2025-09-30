/*
  ************************************************************************

  Name         : 11.c
  Author       : Pankaj Deopa
  Description  : Program to ignore a SIGINT signal then reset the default action of the SIGINT signal -
                    using sigaction system call
  Date         : 29 Sept, 2025

  ************************************************************************
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

int main () {
    struct sigaction act;

    memset(&act, 0, sizeof(act));
    act.sa_handler = SIG_IGN;
    printf("Ignoring SIGING\n");
    sigaction(SIGINT, &act, NULL);
    sleep(5);

    memset(&act, 0, sizeof(act));
    act.sa_handler = SIG_DFL;
    sigaction(SIGINT, &act, NULL);
    printf("\nDefaul SIGINT action\n");
    sleep(5);

	return 0;
}


/*
 ************************************** OUTPUT ***********************************

    piradians@3piradians:~/Documents/system_programming/hl2/p11$ ./a.out
    Ignoring SIGING
    ^C^C^C^C
    Defaul SIGINT action
    ^C
    piradians@3piradians:~/Documents/system_programming/hl2/p11$ 

*******************************************************************************
*/
