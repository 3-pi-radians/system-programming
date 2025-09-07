/*
  **********************************************************************************************

  Name         : 11.c
  Author       : Pankaj Deopa
  Description  : Program to open a file, duplicate the file descriptor and append the file with both the
                      descriptors and check whether the file is updated properly or not.
                   a. using dup
                   b. using dup2
                   c. using fcntl 
  Date         : 2 Sept, 2025

  **********************************************************************************************
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main () {
    int fd1 = open("dup_file.txt", O_WRONLY | O_CREAT | O_APPEND, 0664);
    if (fd1 < 0) {
        perror("open");
        return 1;
     }

     int fd2 = dup(fd1);
     if (fd2 < 0) {
         perror("dup");
         return 1;
     }

     int fd3 = dup2(fd1, 100);
     if (fd3 < 0) {
         perror("dup2");
         return 1;
     }

     int fd4 = fcntl(fd1, F_DUPFD, 200);
     if (fd4 < 0) {
         perror("fcntl");
         return 1;
     }
    
     write(fd1,  "Message written by file descriptor : fd1\n",42); 
     write(fd1,  "Message written by file descriptor : fd2\n",42); 
     write(fd1,  "Message written by file descriptor : fd3\n",42); 
     write(fd1,  "Message written by file descriptor : fd4\n",42); 
        
     printf("Message appended successfully by file descriptors\n");

     close(fd1);
     close(fd2);
     close(fd3);
     close(fd4);

    return 0;
}

/*
 *********************************** OUTPUT ***************************************
  
  piradians@3piradians:~/Documents/system_programming/solutions$ cc 11.c
  piradians@3piradians:~/Documents/system_programming/solutions$ ./a.out
  Message appended successfully by file descriptors
  piradians@3piradians:~/Documents/system_programming/solutions$ cat dup_file.txt
  Message written by file descriptor : fd1
  Message written by file descriptor : fd2
  Message written by file descriptor : fd3
  Message written by file descriptor : fd4
  piradians@3piradians:~/Documents/system_programming/solutions$ 
 
 ***************************************************************************************
*/
