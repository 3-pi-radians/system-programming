/*
  ************************************************************************

  Name         : 17a.c
  Author       : Pankaj Deopa
  Description  : Program to execute ls -l | wc using dup.
  Date         : 30 Sept, 2025

  ************************************************************************
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main () {
    int fd[2];
    pid_t pid;

    if (pipe(fd) == -1) {
        perror("pipe");
        exit(1);
    }

    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    }
    
    if (pid == 0) { // child process
        close(1);
        dup(fd[1]);

        close(fd[0]);
        close(fd[1]);
        execlp("ls", "ls", "-l", NULL);
        perror("execlp");
        exit(1);
    } else { // parent process
        close(0);
        dup(fd[0]);

        close(fd[0]);
        close(fd[1]);
        execlp("wc", "wc", NULL);
        perror("execlp");
        exit(1);
    }

	return 0;
}


/*
 ********************************** OUTPUT *********************************

    piradians@3piradians:~/Documents/system_programming/hl2/p17$ cc 17a.c
    piradians@3piradians:~/Documents/system_programming/hl2/p17$ ./a.out
          4      29     183
    piradians@3piradians:~/Documents/system_programming/hl2/p17$ 

*******************************************************************************
*/
