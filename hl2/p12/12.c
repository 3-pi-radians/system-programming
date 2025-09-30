/*
  ************************************************************************

  Name         : 12.c
  Author       : Pankaj Deopa
  Description  : Program to create an orphan process. Use kill system call to send SIGKILL signal to
                    the parent process from the child process
  Date         : 29 Sept, 2025

  ************************************************************************
*/

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

int main () {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(1);
    } 

    if (pid == 0) {
        // child process

        printf("[PID: %d] Child Process - Parent process PID - %d\n", getpid(), getppid());
        kill(getppid(), SIGKILL);
        sleep(2);
        printf("\nParent process terminated. Child process [PID: %d]  adopted by parent [PID: %d]\n", getpid(), getppid());
    } else {
        // parent process
        sleep(10);
    }

	return 0;
}


/*
 ***************************************** OUTPUT ***********************************

    piradians@3piradians:~/Documents/system_programming/hl2/p12$ ./a.out
    [PID: 10606] Child Process - Parent process PID - 10605
    Killed
    piradians@3piradians:~/Documents/system_programming/hl2/p12$ 
    Parent process terminated. Child process [PID: 10606]  adopted by parent [PID: 2085]
    piradians@3piradians:~/Documents/system_programming/hl2/p12$ 

***************************************************************************************
*/

