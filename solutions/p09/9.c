/*
  ************************************************************************

  Name         : 9.c
  Author       : Pankaj Deopa
  Description  : Program to print the following information about a given file.
                      a. inode
                      b. number of hard links
                      c. uid
                      d. gid
                      e. size
                      f. block size
                      g. number of blocks
                      h. time of last access
                      i. time of last modification
                      j. time of last change
  Date         : 2 Sept, 2025

  ************************************************************************
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <sys/stat.h>

int main (int argc, char *argv[]) {
    if (argc != 2) {
        printf("File name required!! \n");
        return 1;
    }

    struct stat filestat;
    if (stat(argv[1], &filestat) < 0) {
        perror("stat");
        return 1;
    }

    printf("File : %s\n", argv[1]);
    printf("Inode : %ld\n", (long)filestat.st_ino);
    printf("Number of Hard Links : %ld\n", (long)filestat.st_nlink);
    printf("uid : %d\n", filestat.st_uid);
    printf("gid : %d\n", filestat.st_gid);
    printf("Size : %ld\n", (long)filestat.st_size);
    printf("Block Size : %ld\n", (long)filestat.st_blksize);
    printf("Number of blocks : %ld\n", (long)filestat.st_blocks);
    printf("Last accessed on : %s\n", ctime(&filestat.st_atime));
    printf("Last Modified on : %s\n", ctime(&filestat.st_mtime));
    printf("Last Changed on : %s\n", ctime(&filestat.st_ctime));

	return 0;
}


/*
 * **************** OUTPUT *********************************************************

   piradians@3piradians:~/Documents/system_programming/solutions$ cc 9.c
   piradians@3piradians:~/Documents/system_programming/solutions$ ./a.out
   File name required!! 
   piradians@3piradians:~/Documents/system_programming/solutions$ ./a.out File1.txt
   File : File1.txt
   Inode : 10629
   Number of Hard Links : 1
   uid : 1000
   gid : 1000
   Size : 113
   Block Size : 4096
   Number of blocks : 8
   Last accessed on : Tue Sep  2 10:27:33 2025
   Last Modified on : Tue Sep  2 10:27:29 2025
   Last Changed on : Tue Sep  2 10:27:29 2025

 ***************************************************************************************
 *
 * 
*/
