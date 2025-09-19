/*
  ************************************************************************

  Name         : 21.c
  Author       : Pankaj Deopa
  Description  : Program to fork a process and print parent PID and child PID.
  Date         : O6 Sept, 2025

  ************************************************************************
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

int main () {
    pid_t pid;
    pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;
    } else if (pid == 0) {
        printf("Child process PID (printed from child) - %d \n", getpid());
    } else {
        printf("Parent process PID - %d \n", getpid());
        printf("Child Process PID (printed from parent) - %d \n", pid);
    }

    return 0;
}

/*
 ********************************** OUTPUT *******************************************
    
Parent process PID - 3171 
Child Process PID (printed from parent) - 3172 
Child process PID (printed from child) - 3172 

**************************************************************************************

*/
