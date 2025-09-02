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

int main() {
    int fd  = open("File1.txt", O_RDONLY); // open the file in read only mode;

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

  piradians@3piradians:~/Documents/system_programming/solutions$ cc 8.c
  piradians@3piradians:~/Documents/system_programming/solutions$ ./a.out
  Contents of file 1
  Neque porro quisquam est qui dolorem ipsum quia dolor sit amet, consectetur, adipisci velit..
  piradians@3piradians:~/Documents/system_programming/solutions$ 

 ****************************************************************************************
*/
