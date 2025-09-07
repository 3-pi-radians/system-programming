/*
  ************************************************************************

  Name         : template.c
  Author       : Pankaj Deopa
  Description  : Template File
  Date         : 26 Aug, 2025

  ************************************************************************
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>

static __inline__ uint64_t rdtsc(void) {
    unsigned int lo, hi;
    __asm__ __volatile__("rdtsc" : "=a"(lo), "=d"(hi));
    return ((uint64_t)hi << 32) | lo;
}

int main () {
    uint64_t start, end;
    pid_t pid;

    start = rdtsc();
    pid = getpid();
    end = rdtsc();

    printf("PID %d\n", pid);
    printf("Time taken by process : %lu", end-start);

	return 0;
}


/*
 * **************** OUTPUT *******************
 *
 *
 *
 * 
*/
