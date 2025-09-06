/*
  **********************************************************************************************************

  Name         : exec_file.c
  Author       : Pankaj Deopa
  Description  : Program to execute an executable program.
                   a. use some executable program
                   b. pass some input to an executable program. (for example execute an executable of $./a.out name)
  Date         : 06 Sept, 2025

  ********************************************************************************************************
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main () {
    char* name = "Heisenberg";
    execl("./a.out", "./a.out", name, NULL);

    perror("execl");
	return 0;
}


/*
 ********************************************** OUTPUT ***********************************************
    
    piradians@3piradians:~/Documents/system_programming/solutions/p26$ cc sample.c -o a.out
    piradians@3piradians:~/Documents/system_programming/solutions/p26$ cc exec_file.c -o exec_file
    piradians@3piradians:~/Documents/system_programming/solutions/p26$ ./exec_file
    Say my name 
    Heisenberg
    piradians@3piradians:~/Documents/system_programming/solutions/p26$

********************************************************************************************************
*/
