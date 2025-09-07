/*
  ************************************************************************

  Name         : 28.c
  Author       : Pankaj Deopa
  Description  : Program to get maximum and minimum real time priority.
  Date         : 07 Sept, 2025

  ************************************************************************
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sched.h>

int main () {
    int max_priority, min_priority;

	if((max_priority = sched_get_priority_max(SCHED_RR)) == -1){
		perror("Error while getting Max Priority\n");
		return 0;
	}
	printf("Max Priority: %d\n",max_priority);

	if((min_priority = sched_get_priority_min(SCHED_RR)) == -1){
		perror("Error while getting Min Priority\n");
		return 0;
	}

	printf("Min Priority: %d\n",min_priority);
	return 0;
}

/*
 * **************** OUTPUT *********************************************************

    piradians@3piradians:~/Documents/system_programming/solutions/p28$ cc 28.c
    piradians@3piradians:~/Documents/system_programming/solutions/p28$ ./a.out
    Max Priority: 99
    Min Priority: 1
    piradians@3piradians:~/Documents/system_programming/solutions/p28$*

*************************************************************************************** 
*/
