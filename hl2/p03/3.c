/*
  ************************************************************************

  Name         : 3.c
  Author       : Pankaj Deopa
  Description  : Program to set (any one) system resource limit using  setrlimit system call.
  Date         : 27 Sept, 2025

  ************************************************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>

int main() {
    
    struct rlimit rl;

    rl.rlim_cur = 1; // Soft limit
    rl.rlim_max = 2; // Hard limit

    setrlimit(RLIMIT_CPU, &rl);

    printf("CPU time limit set to 1 second.\n");
    while (1);
    return EXIT_SUCCESS;
}

/*
 ********************************** OUTPUT ********************************
  
  piradians@3piradians:~/Documents/system_programming/hl2/p03$ ./a.out
  CPU time limit set to 1 second.
  CPU time limit exceeded (core dumped)

***************************************************************************
*/
