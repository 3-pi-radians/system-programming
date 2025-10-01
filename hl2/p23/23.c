/*
  ************************************************************************

  Name         : 23.c
  Author       : Pankaj Deopa
  Description  : Program to print the maximum number of files can be opened within a process and size of a pipe (circular buffer).
  Date         : 30 Sept, 2025

  ************************************************************************
*/

#define _GNU_SOURCE
#include <unistd.h>
#include <sys/resource.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    struct rlimit rl;

    if (getrlimit(RLIMIT_NOFILE, &rl) == -1) {
        perror("getrlimit");
        exit(1);
    }

    printf("Maximum number of open files per process: %ld\n", (long) rl.rlim_cur);

    int fd[2];
    if (pipe(fd) == -1) {
        perror("pipe");
        exit(1);
    }

    int pipe_size = fcntl(fd[0], F_GETPIPE_SZ);
    if (pipe_size == -1) {
        perror("fcntl");
        exit(1);
    }

    printf("Default pipe buffer size: %d bytes\n", pipe_size);

    close(fd[0]);
    close(fd[1]);
    return 0;
}


/*
 *********************************** OUTPUT *************************************

    piradians@3piradians:~/Documents/system_programming/hl2/p23$ cc 23.c
    piradians@3piradians:~/Documents/system_programming/hl2/p23$ ./a.out
    Maximum number of open files per process: 1024
    Default pipe buffer size: 65536 bytes
    piradians@3piradians:~/Documents/system_programming/hl2/p23$ 

*********************************************************************************
*/
