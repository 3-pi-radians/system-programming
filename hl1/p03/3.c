/*
  ************************************************************************

  Name         : 3.c
  Author       : Pankaj Deopa
  Description  : Program to create a file and print the file descriptor value using creat() system call.
  Date         : 26 Aug, 2025

  ************************************************************************
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main () {
	int fd;

	fd = creat("creat_sys_call.txt", 0644);
	if (fd == -1) {
		perror("creat");
		return fd;
	}

	printf("File created using creat() system call \n");
	printf("File Descriptor: %d\n", fd);
        close(fd);
	return 0;
}


/*
 * ********************************* OUTPUT ***************************
  
  piradians@3piradians:~/Documents/system_programming/solutions$ cc 3.c
  piradians@3piradians:~/Documents/system_programming/solutions$ ./a.out
  File created using creat() system call 
  File Descriptor: 3
 
 ********************************************************************** 
*/
