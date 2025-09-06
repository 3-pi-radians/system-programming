/*
  ************************************************************************

  Name         : execvp.c
  Author       : Pankaj Deopa
  Description  : Program to execute ls -Rl using execvp system call
  Date         : 07 Sept, 2025

  ************************************************************************
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main () {
    printf("Executing ls -Rl using execvp.. \n");
    char* args[] = {"ls", "-Rl", NULL};
    execvp("ls", args); 
    perror("execvp");
	return 1;
}


/*
 ******************************************** OUTPUT ***************************************

    piradians@3piradians:~/Documents/system_programming/solutions/p27$ cc execvp.c
    piradians@3piradians:~/Documents/system_programming/solutions/p27$ ./a.out
    Executing ls -Rl using execvp.. 
    .:
    total 36
    -rwxrwxr-x 1 piradians piradians 70552 Sep  6 19:04 a.out
    -rw-rw-r-- 1 piradians piradians  1390 Sep  6 19:00 execl.c
    -rw-rw-r-- 1 piradians piradians  1446 Sep  6 19:03 execle.c
    -rw-rw-r-- 1 piradians piradians  1389 Sep  6 19:01 execlp.c
    -rw-rw-r-- 1 piradians piradians  1411 Sep  6 19:04 execv.c
    -rw-rw-r-- 1 piradians piradians   605 Sep  6 18:54 execvp.c
    piradians@3piradians:~/Documents/system_programming/solutions/p27$ 

******************************************************************************************* 
*/
