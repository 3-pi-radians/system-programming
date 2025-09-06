/*
  ************************************************************************

  Name         : execle.c
  Author       : Pankaj Deopa
  Description  : Program to execute ls -Rl using execle system call.
  Date         : 07 Sept, 2025

  ************************************************************************
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main () {
    printf("Executing ls -Rl using execle.. \n");
    char* env[] = {"3-pi-radians", NULL};
    execle("/bin/ls", "ls", "-Rl", (char*)NULL, env);
    
    perror("execle");
	return 1;
}

/*
 * ****************************************** OUTPUT *************************************

    piradians@3piradians:~/Documents/system_programming/solutions/p27$ cc execle.c
    piradians@3piradians:~/Documents/system_programming/solutions/p27$ ./a.out
    Executing ls -Rl using execle.. 
    .:
    total 36
    -rwxrwxr-x 1 piradians piradians 70504 Sep  6 19:02 a.out
    -rw-rw-r-- 1 piradians piradians  1390 Sep  6 19:00 execl.c
    -rw-rw-r-- 1 piradians piradians   641 Sep  6 18:58 execle.c
    -rw-rw-r-- 1 piradians piradians  1389 Sep  6 19:01 execlp.c
    -rw-rw-r-- 1 piradians piradians   610 Sep  6 18:58 execv.c
    -rw-rw-r-- 1 piradians piradians   605 Sep  6 18:54 execvp.c
    piradians@3piradians:~/Documents/system_programming/solutions/p27$ 

 **********************************************************************************************
*/
