/*
  ************************************************************************

  Name         : 8a.c
  Author       : Pankaj Deopa
  Description  : Program using signal system call to catch the SIGSEGV signal.
  Date         : 1 Oct, 2025

  ************************************************************************
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void segmentation_fault(int sig) {
    printf("Segmentation Fault\n");
    exit(1);
}

int main() {

    signal(SIGSEGV, segmentation_fault);

    int *p = NULL;
    *p = 10;

    return 0;
}

/*
 ************************************ OUTPUT **************************************

    piradians@3piradians:~/Documents/system_programming/hl2/p08$ cc 8a.c  -o 8a
    piradians@3piradians:~/Documents/system_programming/hl2/p08$ ./8a
    Segmentation Fault
    piradians@3piradians:~/Documents/system_programming/hl2/p08$ 

***********************************************************************************
*/
