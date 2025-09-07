/*
  ************************************************************************

  Name         : 20.c
  Author       : Pankaj Deopa
  Description  : Find out the priority of your running program. Modify the priority with nice command.
  Date         : 07 sept, 2025

  ************************************************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char* argv[]) {

	if(argc !=  2){
		perror("ERROR: priority missing !!\n");
		exit(1);
	}

	int new_priority = atoi(argv[1]);
	int priority = nice(0);

	printf("Current Priority: %d\n", priority);
	priority = nice(new_priority);
	printf("New Priority:  %d\n", priority);
    
    return 0;
}


/*
 ********************************************* OUTPUT ******************************************

    piradians@3piradians:~/Documents/system_programming/solutions/p20$ cc 20.c
    piradians@3piradians:~/Documents/system_programming/solutions/p20$ ./a.out
    ERROR: priority missing !!
    piradians@3piradians:~/Documents/system_programming/solutions/p20$ ./a.out 2
    Current Priority: 0
    New Priority: 2 
    piradians@3piradians:~/Documents/system_programming/solutions/p20$ 

 *************************************************************************************************
*/
