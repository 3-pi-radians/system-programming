/*
  ************************************************************************

  Name         : 16.c
  Author       : Pankaj Deopa
  Description  : Program to send and receive data from parent to child vice versa. Using two way communication.
  Date         : 29 Sept, 2025

  ************************************************************************
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(void){
    int fd1[2]; 
    int fd2[2]; 
    char buff[100];
    
    pipe(fd1);
    pipe(fd2);

    if (fork()) { 
        //Parent
        close(fd1[0]); //closing unused read end
        close(fd2[1]); //closing unused write end

        char *parentMessage = "Data sent from parent process";
        write(fd1[1], parentMessage, strlen(parentMessage));

        read(fd2[0], buff, sizeof(buff));
        printf("Reading data sent from child: %s\n", buff);        

        close(fd1[1]);
        close(fd2[0]);
         
    } else { 
        //child
        close(fd1[1]);
        close(fd2[0]);

        read(fd1[0], buff, sizeof(buff));
        printf("Reading data sent from parent: %s\n", buff);

        char *childMessage = "Data sent from child process";
        write(fd2[1], childMessage, strlen(childMessage));

        close(fd1[0]);
        close(fd2[1]);
    }

    return 0;
}

/*
 ********************************* OUTPUT **********************************

    piradians@3piradians:~/Documents/system_programming/hl2/p16$ cc 16.c
    piradians@3piradians:~/Documents/system_programming/hl2/p16$ ./a.out
    Reading data sent from parent: Data sent from parent process
    Reading data sent from child: Data sent from child process
    piradians@3piradians:~/Documents/system_programming/hl2/p16$ 

****************************************************************************
*/
