/*
  ************************************************************************

  Name         : 10.c
  Author       : Pankaj Deopa
  Description  : Program to open a file with read write mode, write 10 bytes, move the file pointer by 10 bytes (use lseek) and write again 10 bytes.
                    a. check the return value of lseek
                    b. open the file with od and check the empty spaces in between the data
  Date         : 2 Sept, 2025

  ************************************************************************
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main () {
    int fd = open("File2.txt", O_RDWR | O_CREAT, 0644);
    if (fd < 0)  {
        perror("Failed to open file");
        return 1;
    }

    const char* first_bytes = "abcdefghij";
    const char* second_bytes = "0123456789";

    if (write(fd, first_bytes, 10) != 10) {
        perror("write");
        close(fd);
        return 1;
    }

    off_t pos = lseek(fd, 10, SEEK_CUR);
    if (pos == (off_t)-1) {
        perror("lseek");
        close(fd);
        return 1;
    }

    printf("The file offset is : %ld\n", (long)pos);

    if (write(fd, second_bytes, 10) != 10) {
        perror("write");
        close(fd);
        return 1;
    }

    printf("Write operation completed successfully\n");
	return 0;
}


/*
 **************************************** OUTPUT **********************************

  piradians@3piradians:~/Documents/system_programming/solutions$ cc 10.c
  piradians@3piradians:~/Documents/system_programming/solutions$ ./a.out
  The file offset is : 20
  Write operation completed successfully
  piradians@3piradians:~/Documents/system_programming/solutions$ od -c File2.txt
  0000000   a   b   c   d   e   f   g   h   i   j  \0  \0  \0  \0  \0  \0
  0000020  \0  \0  \0  \0   0   1   2   3   4   5   6   7   8   9
  0000036
  piradians@3piradians:~/Documents/system_programming/solutions$ 

 *********************************************************************************
 * 
*/
