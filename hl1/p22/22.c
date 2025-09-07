/*
  *********************************************************************************************

  Name         : 22.c
  Author       : Pankaj Deopa
  Description  :  Write a program, open a file, call fork, and then write to the file by both the child as well as the
                  parent processes. Check output of the file.
  Date         : 06 Sept, 2025

  **********************************************************************************************
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

int main () {
    pid_t pid;

    int fd = open("sample.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open failed");
        exit(1);
    }

    pid = fork();
    if (pid < 0) {
        perror("fork failed");
        close(fd);
        exit(1);
    } else if (pid == 0) {
        char buf[50] = "Text written by child process\n";
        printf("PID - %d | child process writing to file \n",pid);
        write(fd, buf, strlen(buf));
        printf("Write complete by PID %d \n", pid);
    } else {
        char buf[50] = "Text written by parent process \n";
        printf("PID - %d | parent process wiritng to file\n",pid);
        write(fd, buf, strlen(buf));
        printf("Write complete by PID %d \n", pid);

        wait(NULL);
    }

    close(fd);
	return 0;
}


/*
 ************************************** OUTPUT ***********************************************

    piradians@3piradians:~/Documents/system_programming/solutions/p22$ cc 22.c
    piradians@3piradians:~/Documents/system_programming/solutions/p22$ ./a.out
    PID - 14690 | parent process wiritng to file
    Write complete by PID 14690 
    PID - 0 | child process writing to file 
    Write complete by PID 0 
    piradians@3piradians:~/Documents/system_programming/solutions/p22$ 

********************************************************************************************** 
*/
