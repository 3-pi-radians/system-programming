/*
  ************************************************************************

   Name         : 14.c 
   Author       : Pankaj Deopa
   Description  : Program to find the type of a file.
                     a. Input should be taken from command line.
                     b. program should be able to identify any type of a file.
   Date         : 26 Aug, 2025

  ************************************************************************
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main (int argc, char* argv[]) {
    if (argc != 2) {
        printf("Filename Required !!\n");
        return 1;
    };

    struct stat filestat;

    if (lstat(argv[1], &filestat) == -1) {
        perror("lstat");
        return 1;
    };

    if (S_ISREG(filestat.st_mode)) {
        printf("%s is a regular file \n", argv[1]);
    } else if (S_ISDIR(filestat.st_mode)) {
        printf("%s is directory \n",argv[1]);
    } else if (S_ISCHR(filestat.st_mode)) {        
        printf("%s is a character device \n", argv[1]);
    } else if (S_ISBLK(filestat.st_mode)) { 
        printf("%s is a block device \n",argv[1]);
    } else if (S_ISFIFO(filestat.st_mode)) { 
        printf("%s is a FIFO/Pipe \n", argv[1]);
    } else if (S_ISLNK(filestat.st_mode)) {
        printf("%s is a link \n", argv[1]);
    } else if (S_ISSOCK(filestat.st_mode)) {
        printf("%s is a socket \n", argv[1]);
    } else {
        printf("%s is file of unknown type \n", argv[1]);
    }


	return 0;
}

/************************************** OUTPUT ***********************************
 
  piradians@3piradians:~/Documents/system_programming/solutions$ cc 14.c
  piradians@3piradians:~/Documents/system_programming/solutions$ ./a.out
  Filename Required !!
  piradians@3piradians:~/Documents/system_programming/solutions$ ./a.out 12.c
  12.c is a regular file 
  piradians@3piradians:~/Documents/system_programming/solutions$ ./a.out a.out
  a.out is a regular file 
  piradians@3piradians:~/Documents/system_programming/solutions$ ./a.out /dev/stdin
  /dev/stdin is a link 
  piradians@3piradians:~/Documents/system_programming/solutions$ ./a.out /dev/vcs
  /dev/vcs is a character device 
  piradians@3piradians:~/Documents/system_programming/solutions$ ./a.out /dev/vda
  /dev/vda is a block device 
  piradians@3piradians:~/Documents/system_programming/solutions$ ./a.out  /dev/ttyS5
  /dev/ttyS5 is a character device 
  piradians@3piradians:~/Documents/system_programming/solutions$ ./a.out /dev/block/11:0
  /dev/block/11:0 is a link 

 ********************************************************************************** 
*/
