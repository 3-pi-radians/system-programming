/*
  ************************************************************************

  Name         : 2.c
  Author       : Pankaj Deopa
  Description  : Program to print the system resource limits. Use getrlimit system call.
  Date         : 27 Sept, 2025

  ************************************************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>

void rsrc_lmt(int resource, const char *resource_name) {

    struct rlimit limit;

    if (getrlimit(resource, &limit) == 0) {
        printf("%s:\n", resource_name);
        printf("  Soft limit: %ld\n", limit.rlim_cur);
        printf("  Hard limit: %ld\n\n", limit.rlim_max);
    } else {
        perror("getrlimit failed");
        exit(EXIT_FAILURE);
    }
}

int main () {
    rsrc_lmt(RLIMIT_CPU, "CPU TIME LIMIT");
    rsrc_lmt(RLIMIT_FSIZE, "FILE SIZE LIMIT");
    rsrc_lmt(RLIMIT_STACK, "STACK SIZE LIMIT");
    rsrc_lmt(RLIMIT_NOFILE, "NUMBER OF OPEN FILES");
    rsrc_lmt(RLIMIT_NPROC, "NUMBER OF PROCESS FILES");

	return 0;
}


/*
 ******************************* OUTPUT ****************************
     
     CPU TIME LIMIT:
      Soft limit: -1
      Hard limit: -1

    FILE SIZE LIMIT:
      Soft limit: -1
      Hard limit: -1

    STACK SIZE LIMIT:
      Soft limit: 8388608
      Hard limit: -1

    NUMBER OF OPEN FILES:
      Soft limit: 1024
      Hard limit: 1048576

    NUMBER OF PROCESS FILES:
      Soft limit: 7355
      Hard limit: 7355

*************************************************************************
 */
