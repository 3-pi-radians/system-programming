/*
  ************************************************************************

  Name         : 7.c
  Author       : Pankaj Deopa
  Description  : Program to copy the contents of file1 to file 2 ($cp File1.txt File2.txt)
  Date         : 07 Sept, 2025

  ************************************************************************
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define BUF_SIZE 1024

int main (int argc, char* argv[]) {
    int fd_source, fd_dest;
    char buf[BUF_SIZE];
    ssize_t bytesread, byteswritten;

    if (argc != 3) {
        printf("ERROR: sourcefile and destination file required!!\n");
        exit(1);
    }

    fd_source = open(argv[1], O_RDONLY);
    if (fd_source < 0) {
        perror("open source");
        exit(1);
    } 

    fd_dest = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd_dest < 0) {
        perror("open destination");
        close(fd_source);
        exit(1);
    }

    while ((bytesread = read(fd_source, buf, BUF_SIZE)) > 0) {
        byteswritten = write(fd_dest, buf, bytesread);
        if (bytesread != byteswritten) {
            perror("write error");
            close(fd_source);
            close(fd_dest);
            exit(1);
        }
    }

    if (bytesread < 0) {
        perror("read");
        close(fd_source);
        close(fd_dest);
        exit(1);
    }

    printf("Contents of %s copied to %s successfully\n", argv[1], argv[2]);
	return 0;
}

/*
 ****************************************** OUTPUT ********************************************
  
    piradians@3piradians:~/Documents/system_programming/solutions/p07$ cc 7.c
    piradians@3piradians:~/Documents/system_programming/solutions/p07$ ./a.out
    ERROR: sourcefile and destination file required!!
     1 piradians@3piradians:~/Documents/system_programming/solutions/p07$ ./a.out sourcefile.txt destfile.txt
    Contents of sourcefile.txt copied to destfile.txt successfully
    piradians@3piradians:~/Documents/system_programming/solutions/p07$ cat sourcefile.txt
    Contents of sourcefile.txt

    The read system call in Linux is a low-level function used to read data from files, devices, or standard input. 
    It interacts directly with the kernel and is defined in <unistd.h>



    piradians@3piradians:~/Documents/system_programming/solutions/p07$ cat destfile.txt
    Contents of sourcefile.txt

    The read system call in Linux is a low-level function used to read data from files, devices, or standard input.
    It interacts directly with the kernel and is defined in <unistd.h>



    piradians@3piradians:~/Documents/system_programming/solutions/p07$ 
 
 ************************************************************************************************
*/
