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
        printf("Child process PID - %d \n", pid);
    } else {
        printf("Parent process PID - %d \n", pid);
    }

    return 0;
}

/*
 ********************************** OUTPUT *******************************************
    
    piradians@3piradians:~/Documents/system_programming/solutions/p21$ cc 21.c
    piradians@3piradians:~/Documents/system_programming/solutions/p21$ ./a.out
    Parent process PID - 13954 
    Child process PID - 0 

**************************************************************************************
*/
