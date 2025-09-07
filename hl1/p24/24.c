/*
  ************************************************************************

  Name         : 24.c
  Author       : Pankaj Deopa
  Description  : Write a program to create an orphan process.
  Date         : 05 Sept, 2025

  ************************************************************************
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main () {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        printf("[PID : %d] Child process sleeping for 5 seconds \n",getpid());
        sleep(5);
        printf("[PID : %d] Child process:  parent process before termination (%d)\n", getpid(), getppid());
        sleep(6);
        printf("[PID : %d] Child process orphan now \n", getpid()); 
        printf("[PID : %d] Child process:  Parent process changed after termination (%d)\n", getpid(), getppid());
    } else {
        printf("[PID : %d] Parent proces. \n", getpid());
        sleep(10);
        exit(0);
    }

	return 0;
}

/*
 ******************************************* OUTPUT *********************************************************

    piradians@3piradians:~/Documents/system_programming/solutions/p24$ cc 24.c
    piradians@3piradians:~/Documents/system_programming/solutions/p24$ ./a.out
    [PID : 15655] Parent proces. 
    [PID : 15656] Child process sleeping for 5 seconds 
    [PID : 15656] Child process:  parent process before termination (15655)
    piradians@3piradians:~/Documents/system_programming/solutions/p24$ [PID : 15656] Child process orphan now 
    [PID : 15656] Child process:  Parent process changed after termination (1630)

 ************************************************************************************************************ 
*/
