/*
  ************************************************************************

  Name         : 23.c
  Author       : Pankaj Deopa
  Description  : Write a program to create a Zombie state of the running program.
  Date         : 06 Sept, 2025

  ************************************************************************
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main () {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork error");
        exit(1);
    } else if (pid > 0) {
        printf("[PID : %d] Parent Process\n",getpid());
        printf("[PID : %d] parent process sleeping for 20 seconds\n",getpid());
        sleep(20);
        wait(NULL);
        printf("[PID : %d]Parent exiting now\n",getpid());
    } else {
        printf("[PID : %d] Child process\n", getpid());
        printf("[PID : %d] Child process exiting now\n", getpid());
        exit(0);
    }

	return 0;
}


/*
 **************************************** OUTPUT ****************************************************

                                         TERMINAL 1

    piradians@3piradians:~/Documents/system_programming/solutions/p23$ ./a.out
    [PID : 15324] Parent Process
    [PID : 15324] parent process sleeping for 20 seconds
    [PID : 15325] Child process
    [PID : 15325] Child process exiting now
    [PID : 15324]Parent exiting now

===================================================================================================

                                        TERMINAL 2

    piradians@3piradians:~/Documents/system_programming/solutions/p18$ top -p 15325

    top - 16:10:08 up  8:02,  1 user,  load average: 0.06, 0.12, 0.10
    Tasks:   1 total,   0 running,   0 sleeping,   0 stopped,   1 zombie
    %Cpu(s):  8.8 us,  1.9 sy,  0.0 ni, 89.3 id,  0.0 wa,  0.0 hi,  0.0 si,  0.0 st 
    MiB Mem :   1956.3 total,    159.5 free,   1072.9 used,    966.3 buff/cache     
    MiB Swap:   2048.0 total,   1480.0 free,    568.0 used.    883.4 avail Mem 

    PID USER      PR  NI    VIRT    RES    SHR S  %CPU  %MEM     TIME+ COMMAND                                                          
  15325 piradia+  20   0       0      0      0 Z   0.0   0.0   0:00.00 a.out                                                            

******************************************************************************************************* 
*/
