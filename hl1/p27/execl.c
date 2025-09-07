/*
  ************************************************************************

  Name         : execl.c
  Author       : Pankaj Deopa
  Description  : Program to execute ls -Rl using execl system call.
  Date         : 07 Sept, 2025

  ************************************************************************
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main () {
    printf("Executing ls -Rl using execl.. \n");
    execl("/bin/ls", "ls", "-Rl", (char*)NULL);
    perror("execl");
	return 1;
}


/*
 ******************************************** OUTPUT ***************************************

    piradians@3piradians:~/Documents/system_programming/solutions/p27$ cc execl.c
    piradians@3piradians:~/Documents/system_programming/solutions/p27$ ./a.out
    Executing ls -Rl using execl.. 
    .:
    total 36
    -rwxrwxr-x 1 piradians piradians 70400 Sep  6 18:59 a.out
    -rw-rw-r-- 1 piradians piradians   585 Sep  6 18:55 execl.c
    -rw-rw-r-- 1 piradians piradians   641 Sep  6 18:58 execle.c
    -rw-rw-r-- 1 piradians piradians   591 Sep  6 18:57 execlp.c
    -rw-rw-r-- 1 piradians piradians   610 Sep  6 18:58 execv.c
    -rw-rw-r-- 1 piradians piradians   605 Sep  6 18:54 execvp.c
    piradians@3piradians:~/Documents/system_programming/solutions/p27$ 

 * ********************************************************************************************
*/
