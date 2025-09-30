/*
  ************************************************************************

  Name         : 15.c
  Author       : Pankaj Deopa
  Description  : Program to send some data from parent to the child process.
  Date         : 29 Sept, 2025

  ************************************************************************
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(void){
    int fd[2];
    char buff[100];

    pipe(fd);

    if(fork()){
        close(fd[0]);
        char *message = "Hi There! Welcome to Linux System Programming\n";
        write(fd[1], message, strlen(message));

    } else {
        close(fd[1]);
        read(fd[0], buff, sizeof(buff));
        printf("Reading data sent from parent to child: %s\n", buff);
    }
    return 0;
}

/*
 ************************************ OUTPUT **********************************************

    piradians@3piradians:~/Documents/system_programming/hl2/p15$ ./a.out
    Reading data sent from parent to child: Hi There! Welcome to Linux System Programming

    piradians@3piradians:~/Documents/system_programming/hl2/p15$ 

*******************************************************************************************
*/
