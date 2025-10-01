/*
  ************************************************************************

  Name         : 22.c
  Author       : Pankaj Deopa
  Description  : Write a program to wait for data to be written into FIFO within 10 seconds, use select system call with FIFO
  Date         : 30 Sept, 2025

  ************************************************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/select.h>
#include <string.h>

int main() {
    int fd;
    char buffer[100];
    fd_set readfds;
    struct timeval timeout;

    fd = open("myfifo", O_RDONLY | O_NONBLOCK);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    printf("Waiting for data on FIFO 'myfifo' for 10 seconds...\n");

    FD_ZERO(&readfds);
    FD_SET(fd, &readfds);

    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    int ret = select(fd + 1, &readfds, NULL, NULL, &timeout);

    if (ret == -1) {
        perror("select");
        close(fd);
        exit(1);
    } else if (ret == 0) {
        printf("No data within 10 seconds.\n");
    } else {
        if (FD_ISSET(fd, &readfds)) {
            int n = read(fd, buffer, sizeof(buffer)-1);
            if (n > 0) {
                buffer[n] = '\0';
                printf("Data received: %s\n", buffer);
            } else {
                printf("FIFO closed or no data.\n");
            }
        }
    }

    close(fd);
    return 0;
}

/*
 ************************************* OUTPUT *********************************

                                TERMINAL 1

    piradians@3piradians:~/Documents/system_programming/hl2/p22$ ./a.out
    Waiting for data on FIFO 'myfifo' for 10 seconds...
    Data received: Hi There. Sending data throgh fifo

    piradians@3piradians:~/Documents/system_programming/hl2/p22$

==============================================================================

                                TERMINAL 2

    piradians@3piradians:~/Documents/system_programming/hl2/p22$ echo "Hi There. Sending data throgh fifo" > myfifo


***********************************************************************************
*/
