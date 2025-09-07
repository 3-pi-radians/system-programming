/*
  **********************************************************************************************

  Name         : sample.c
  Author       : Pankaj Deopa
  Description  : Program to execute an executable program.
                    a. use some executable program
                    b. pass some input to an executable program. (for example execute an executable of $./a.out name)
  Date         : 06 Sept, 2025

  **********************************************************************************************
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main (int argc, char* argv[]) {
    if (argc > 1) {
        printf("Say my name \n");
        printf("%s\n", argv[1]);
    } else {
        printf("Hi there !\n");
    }

	return 0;
}


/*
 **************************************************** OUTPUT *********************************
    
    piradians@3piradians:~/Documents/system_programming/solutions/p26$ cc sample.c -o a.out
    piradians@3piradians:~/Documents/system_programming/solutions/p26$ cc exec_file.c -o exec_file
    piradians@3piradians:~/Documents/system_programming/solutions/p26$ ./exec_file
    Say my name 
    Heisenberg
    piradians@3piradians:~/Documents/system_programming/solutions/p26$ 

********************************************************************************************
*/
