/*
  ************************************************************************

  Name         : 21a.c
  Author       : Pankaj Deopa
  Description  : Write two programs so that both can communicate by FIFO -Use two way communications.
  Date         : 30 Sept, 2025

  ************************************************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {
    int fd_write, fd_read;
    char write_buf[100], read_buf[100];

    fd_write = open("a2b", O_WRONLY); // write to pipe (a2b) 
    fd_read  = open("b2a", O_RDONLY); // read from pipe (b2a)

    if (fd_write == -1 || fd_read == -1) {
        perror("open");
        exit(1);
    }

    while (1) {
        printf("Process A: Enter message: ");
        fgets(write_buf, sizeof(write_buf), stdin);
        write_buf[strcspn(write_buf, "\n")] = 0;

        write(fd_write, write_buf, strlen(write_buf) + 1);

        if (strcmp(write_buf, "exit") == 0) break;

        // Read reply from B
        read(fd_read, read_buf, sizeof(read_buf));
        printf("Process B says: %s\n", read_buf);
    }

    close(fd_write);
    close(fd_read);
    return 0;
}

/*
 ************************************ OUTPUT ************************************

                                      TERMINAL 1

    piradians@3piradians:~/Documents/system_programming/hl2/p21$ cc 21b.c -o b
    piradians@3piradians:~/Documents/system_programming/hl2/p21$ ./b
    Process A says: Hello
    Process B: Enter reply: Hi This is terminal 2
    Process A says: Message from terminal 1
    Process B: Enter reply: Message received.
    Process A says: Message from terminal 1
    Process B: Enter reply: 
    piradians@3piradians:~/Documents/system_programming/hl2/p21$ 

==================================================================================

                                    TERMINAL 2

    piradians@3piradians:~/Documents/system_programming/hl2/p21$ cc 21a.c -o a
    piradians@3piradians:~/Documents/system_programming/hl2/p21$ ./a
    Process A: Enter message: Hello
    Process B says: Hi This is terminal 2
    Process A: Enter message: Message from terminal 1
    fProcess B says: Message received.
    Process A: Enter message:^C  
    piradians@3piradians:~/Documents/system_programming/hl2/p21$ 

***********************************************************************************
*/

