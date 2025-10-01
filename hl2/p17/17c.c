/*
  ************************************************************************

  Name         : 17c.c
  Author       : Pankaj Deopa
  Description  : Program to execute ls - l | wc using fcntl. 
  Date         : 30 Sept, 2025

  ************************************************************************
*/

#include <stdio.h>
#include <fcntl.h>
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

    if (pid == 0) {
        close(fd[0]);
        close(STDOUT_FILENO);
        
        fcntl(fd[1], F_DUPFD, STDOUT_FILENO);

        close(fd[1]);
        execlp("ls", "ls", "-l", NULL);
        perror("execlp");
        exit(1);
    } else {
        close(fd[1]);
        close(STDIN_FILENO);

        fcntl(fd[0], F_DUPFD, STDIN_FILENO);

        close(fd[0]);
        execlp("wc", "wc", NULL);
        perror("execlp");
        exit(1);
    }

	return 0;
}

/*
 ******************************** OUTPUT ***********************************

    piradians@3piradians:~/Documents/system_programming/hl2/p17$ cc 17c.c
    piradians@3piradians:~/Documents/system_programming/hl2/p17$ ./a.out
          5      38     241
    piradians@3piradians:~/Documents/system_programming/hl2/p17$ 

*****************************************************************************
*/
