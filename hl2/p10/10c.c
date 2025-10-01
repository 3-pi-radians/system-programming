/*
  ************************************************************************

  Name         : 10c.c
  Author       : Pankaj Deopa
  Description  : Program using sigaction system call to catch the SIGFPE sigal.
  Date         : 29 Sept, 2025

  ************************************************************************
*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void handle_sigfpe(int sig) {
    printf("\nFloating-Point Exception caught! Signal number: %d. Exiting cleanly.\n", sig);
    exit(EXIT_FAILURE);
}

int main() {
    struct sigaction sa = { .sa_handler = handle_sigfpe };
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    if (sigaction(SIGFPE, &sa, NULL) == -1) {
        perror("sigaction");
        return 1;
    }

    printf("Handler installed. Program will now cause a floating-point exception...\n");
    volatile int x = 0;
    volatile int y = 0;
    int z = x / y;

    printf("This message will not be printed.\n");

    return 0;
}

/*
*********************************** OUTPUT ***********************************
    
    piradians@3piradians:~/Documents/system_programming/hl2/p10$ ./a.out
    Handler installed. Program will now cause a floating-point exception...

    Floating-Point Exception caught! Signal number: 8. Exiting cleanly.
    piradians@3piradians:~/Documents/system_programming/hl2/p10$ 

******************************************************************************
*/
