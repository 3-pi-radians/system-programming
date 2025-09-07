/*
  ******************************************************************************

  Name         : 8.c
  Author       : Pankaj Deopa
  Description  : Program to read a file and print the lines in terminal line by line.
  Date         : 2 Sept, 2025

  *****************************************************************************
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("ERROR: Filename required!!\n");
        exit(1);
    }

    int fd  = open(argv[1], O_RDONLY); // open the file in read only mode;
    if (fd < 0 ) {
        perror("Unable to open file \n");
        return 1;
     }

    char buffer[256];
    ssize_t bytesread;

    while ((bytesread = read(fd, buffer, sizeof(buffer) -1)) > 0) {
        buffer[bytesread] = '\0';
        printf("%s", buffer);
    }

     close(fd);
     return 0;
}

/*
 ************************************* OUTPUT ******************************************

    piradians@3piradians:~/Documents/system_programming/solutions/p08$ cc 8.c
    piradians@3piradians:~/Documents/system_programming/solutions/p08$ ./a.out
    ERROR: Filename required!!
    piradians@3piradians:~/Documents/system_programming/solutions/p08$ ./a.out sample.txt
    This is a sample text form sample.txt
    piradians@3piradians:~/Documents/system_programming/solutions/p08$ 

 ****************************************************************************************
*/
