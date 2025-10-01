/*
  ************************************************************************

  Name         : 20_rd.c
  Author       : Pankaj Deopa
  Description  : Write two programs so that both can communicate by FIFO (Use one way communication)
  Date         : 30 Sept, 2025

  ************************************************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd;
    char buffer[100];

    fd = open("myfifo", O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    read(fd, buffer, sizeof(buffer));
    printf("Message received: %s\n", buffer);

    close(fd);
    return 0;
}

/*
 ************************************** OUTPUT **************************************

                                        TERMINAL 1 (writer)

    radians@3piradians:~/Documents/system_programming/hl2/p20$ cc 20_wrt.c -o writer
    piradians@3piradians:~/Documents/system_programming/hl2/p20$ ./writer
    Message sent: Hello from writer via FIFO!
    piradians@3piradians:~/Documents/system_programming/hl2/p20$ 

====================================================================================

                                        TERMINAL 2 (reader)


    piradians@3piradians:~/Documents/system_programming/hl2/p20$ cc 20_rd.c -o reader.c
    piradians@3piradians:~/Documents/system_programming/hl2/p20$ ./reader
    Message received: Hello from writer via FIFO!
    piradians@3piradians:~/Documents/system_programming/hl2/p20$

**************************************************************************************
*/
