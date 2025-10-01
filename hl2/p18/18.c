/*
  ************************************************************************

  Name         : 18.c
  Author       : Pankaj Deopa
  Description  : Program to find out total number of directories on the pwd. execute ls -l | grep ^d | wc.  Using dup2.
  Date         : 30 Sept, 2025

  ************************************************************************
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(){

    int fd1[2], fd2[2];
    pipe(fd1);
    pipe(fd2);

    if (!fork())
    {
        // write end of fd1
        dup2(fd1[1], 1); // fd1[1] --> STDOUT
        close(fd1[0]);
        close(fd2[0]);
        close(fd2[1]);
        execl("/bin/ls", "/bin/ls", "-l", NULL);
    }
    else
    {
        if (!fork())
        {
            // read end of fd1
            dup2(fd1[0], 0); // fd1[0] --> STDIN
            // write end of fd2
            dup2(fd2[1], 1); // fd2[1] --> STDOUT
            close(fd1[1]);
            close(fd2[0]);
            execl("/bin/grep", "/bin/grep", "^d", NULL);
        }
        else
        {
            // read end of fd1
            dup2(fd2[0], 0); // fd2[0] --> STDIN
            close(fd2[1]);
            close(fd1[0]);
            close(fd1[1]);
            execl("/bin/wc", "/bin/wc", "-l", NULL);
        }
    }

    return 0;
}

/*
 ************************************** OUTPUT ************************************

    piradians@3piradians:~/Documents/system_programming/hl2/p18$ cc 18.c
    piradians@3piradians:~/Documents/system_programming/hl2/p18$ ls
    18.c  a.out
    piradians@3piradians:~/Documents/system_programming/hl2/p18$ ./a.out
    0
    piradians@3piradians:~/Documents/system_programming/hl2/p18$ mkdir demo
    piradians@3piradians:~/Documents/system_programming/hl2/p18$ ./a.out
    1
    piradians@3piradians:~/Documents/system_programming/hl2/p18$ 

***********************************************************************************
*/
