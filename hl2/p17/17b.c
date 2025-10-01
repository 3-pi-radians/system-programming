/*
  ************************************************************************

  Name         : 17a.c
  Author       : Pankaj Deopa
  Description  : Program to execute ls -l | wc using dup2.
  Date         : 30 Sept, 2025

  ************************************************************************
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    int fd[2];
    pipe(fd);

    if (fork() == 0) { // Child
        dup2(fd[1], STDOUT_FILENO);
        close(fd[0]);
        execlp("ls", "ls", "-l", NULL);
    } else { // Parent
        dup2(fd[0], STDIN_FILENO);
        close(fd[1]);
        execlp("wc", "wc", NULL);
    }
    return 0;
}


/*
 ********************************** OUTPUT ************************************

    piradians@3piradians:~/Documents/system_programming/hl2/p17$ cc 17b.c
    piradians@3piradians:~/Documents/system_programming/hl2/p17$ ./a.out
          3      20     125
    piradians@3piradians:~/Documents/system_programming/hl2/p17$

*******************************************************************************
*/
