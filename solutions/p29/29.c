/*
  ************************************************************************

  Name         : 29.c 
  Author       : Pankaj Deopa
  Description  : Program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,SCHED_RR).
  Date         : 07 Sept, 2025

  ************************************************************************
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sched.h>

void showSchedulingPolicy(int policy) {
    switch(policy) {
        case SCHED_RR:
                printf("The current scheduling policy is SCHED_RR\n");
                break;
        case SCHED_FIFO:
                printf("The current scheduling policy is SCHED_FIFO\n");
                break;
        case SCHED_OTHER:
                printf("The current scheduling policy is SCHED_OTHER\n");
                break;
        default:
                printf("Unknown scheduling policy");
    }
}

int main () {
    int policy;
    struct sched_param param;

    policy = sched_getscheduler(getpid());
    showSchedulingPolicy(policy);

    param.sched_priority = 20;
    if (sched_setscheduler(getpid(), SCHED_FIFO, &param) == -1) {
        perror("sched_setscheduler");
        exit(1);
    }

    policy = sched_getscheduler(getpid());
    if (policy == -1) {
        perror("sched_getscheduler");
        exit(1);
    }
    showSchedulingPolicy(policy);

	return 0;
}


/*
 ************************************************ OUTPUT ******************************

    piradians@3piradians:~/Documents/system_programming/solutions/p29$ cc 29.c
    piradians@3piradians:~/Documents/system_programming/solutions/p29$ sudo ./a.out
    [sudo] password for piradians: 
    The current scheduling policy is SCHED_OTHER
    The current scheduling policy is SCHED_FIFO
    piradians@3piradians:~/Documents/system_programming/solutions/p29$ 
    
******************************************************************************************
*/
