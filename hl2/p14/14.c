/*
  ************************************************************************

  Name         : 14.c
  Author       : Pankaj Deopa
  Description  : Program to create a pipe, write to the pipe, read from pipe and display on the monitor
  Date         : 29 Sept, 2025

  ************************************************************************
*/

#include  <stdio.h>
#include  <unistd.h>
#include  <string.h>

int main(void){
    int fd[2];
    char buff[100];

    char *message = "Hi there!! Welcome to Linux system Programming\n";
   
   pipe(fd);
    
    write(fd[1], message, strlen(message));
    int bytes_read = read(fd[0], buff, sizeof(buff));
    buff[bytes_read] = '\0';
    printf("Reading from pipe: %s\n", buff);
    return 0;
}

/*
 **************************** OUTPUT *****************************************

    piradians@3piradians:~/Documents/system_programming/hl2/p14$ cc 14.c
    piradians@3piradians:~/Documents/system_programming/hl2/p14$ ./a.out
    Reading from pipe: Hi there!! Welcome to Linux system Programming

    piradians@3piradians:~/Documents/system_programming/hl2/p14$

******************************************************************************
*/
