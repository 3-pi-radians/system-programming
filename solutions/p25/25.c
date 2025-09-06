/*
  ****************************************************************************************************

  Name         : 25.c
  Author       : Pankaj Deopa
  Description  : Write a program to create three child processes. The parent should wait for a particular child (use
                     waitpid system call).
  Date         : 06 Sept, 2025

  **************************************************************************************************
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main () {
	pid_t pid_1, pid_2, pid_3;
	pid_t child_ter;
	int wait;

	if((pid_1 = fork()) == -1){
		perror("Error while creating child 1\n");
		return 0;
	}
	if(pid_1 == 0){
		printf("[PID : %d] Child process 1 created\n", getpid());
		printf("[PID : %d] Child 1 going to sleep for 5 seconds\n",getpid());
		sleep(5);
		printf("[PID: %d] Child process 1 is awake\n", getpid());
		exit(0);
	}

	if((pid_2 = fork()) == -1){
		perror("Error while creating child 2\n");
		return 0;
	}
	if(pid_2 == 0){
		printf("[PID : %d] Child process 2 created\n", getpid());
		printf("[PID : %d] Child 2 going to sleep for 10  seconds\n", getpid());
		sleep(10);
		printf("[PID: %d] Child process 2 is awake\n", getpid());
		exit(0);
	}

	if((pid_3 = fork()) == -1){
		perror("Error while creating child 3\n");
		return 0;
	} else if(pid_3 == 0){
		printf("[PID : %d] Child process 3 created\n", getpid());
		printf("[PID : %d] Child 3 going to sleep for 15 seconds\n", getpid());
		sleep(15);
		printf("[PID: %d] Child process 3 is awake\n", getpid());
		exit(0);
    }

	printf("Parent waiting for Child 3\n");
	child_ter = waitpid(pid_3, &wait, 0);
	
	if(child_ter == pid_3){
		printf("Child 3 exited with exit status: %d\n", wait);
	}else{
		perror("waitpid");
	}

	return 0;
}


/*
 ********************************* OUTPUT **************************************************
    
    piradians@3piradians:~/Documents/system_programming/solutions/p25$ ./a.out
    [PID : 16025] Child process 1 created
    [PID : 16025] Child 1 going to sleep for 5 seconds
    [PID : 16026] Child process 2 created
    [PID : 16026] Child 2 going to sleep for 10  seconds
    Parent waiting for Child 3
    [PID : 16027] Child process 3 created
    [PID : 16027] Child 3 going to sleep for 15 seconds
    [PID: 16025] Child process 1 is awake
    [PID: 16026] Child process 2 is awake
    [PID: 16027] Child process 3 is awake
    Child 3 exited with exit status: 0
    piradians@3piradians:~/Documents/system_programming/solutions/p25$ 

*************************************************************************************************
*/
