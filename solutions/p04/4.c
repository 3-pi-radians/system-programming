/*
  ************************************************************************

  Name         : 4.c
  Author       : Pankaj Deopa
  Description  : Program to open an existing file with read write mode
  Date         : 26 Aug, 2025

  ************************************************************************
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main (int argc, char* argv[]) {
	int fd;
    if (argc != 2) {
        printf("Filename required!!\n");
        exit(1);
    }

	fd = open(argv[1], O_RDWR);
	if (fd == -1) {
		perror("open");
		return fd;
	};

	printf("File opened successfully \n");
	printf("File Descriptor : %d\n", fd);

	close(fd);
	return 0;
}


/*
 * **************** OUTPUT *******************
  
  piradians@3piradians:~/Documents/system_programming/solutions$ cc 4.c
  piradians@3piradians:~/Documents/system_programming/solutions$ ./a.out sample.txt
  File opened successfully  
  File Descriptor : 3

 *****************************************************************************I 
*/
