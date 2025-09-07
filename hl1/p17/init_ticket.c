/*
  ************************************************************************

  Name         : inti_ticket.c
  Author       : Pankaj Deopa
  Description  : Program to open a file, store a ticket number and exit.
  Date         : 06 Sept, 2025

  ************************************************************************
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main () {
    int fd;
    char buf[10];

    fd = open("initialize.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    snprintf(buf, sizeof(buf), "%d\n", 1);
    if (write(fd, buf, strlen(buf)) == -1) {
        perror("write");
        close(fd);
        exit(1);
    }

    printf("Ticket has been initialized with value 1\n");

	return 0;
}


/*
 * ************************************************ OUTPUT **********************************************

    piradians@3piradians:~/Documents/system_programming/solutions/p17$ cc init_ticket.c -o init_ticket
    piradians@3piradians:~/Documents/system_programming/solutions/p17$ ./init_ticket
    Ticket has been initialized with value 1
    piradians@3piradians:~/Documents/system_programming/solutions/p17$ 

 ******************************************************************************************************** 
*/
