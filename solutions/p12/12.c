/*
  ************************************************************************

  Name         : 12.c
  Author       : Pankaj Deopa
  Description  : Program to find out the opening mode of a file using fcntl. 
  Date         : 02 Sept, 2025

  ************************************************************************
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main (int argc, char* argv[]) {

    if(argc != 2) {
        printf("Filename Required !!\n");
        return 1;
    }


    int fd = open(argv[1], O_CREAT | O_RDWR, 0644);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    int flag = fcntl(fd, F_GETFL);
    if (flag == -1) {
        perror("fcntl");
        close(fd);
        return 1;
    }

    int MODE = flag & O_ACCMODE;

    switch(MODE) {
        case O_RDONLY:
                printf("File opened in Read only mode. \n");
                break;
        case O_WRONLY:
                printf("File opened in Write only mode. \n");
                break;
        case O_RDWR: 
                printf("File opened in Read/Write mode. \n");
                break;
        default:
                printf("File opened in unknown mode. \n");
    }
    
    close(fd);

	return 0;
}

/*
 *********************************** OUTPUT ****************************************

  piradians@3piradians:~/Documents/system_programming/solutions$ cc 12.c
  piradians@3piradians:~/Documents/system_programming/solutions$ ./a.out mode_file.txt
  File opened in Read/Write mode. 
  piradians@3piradians:~/Documents/system_programming/solutions$ 

 ************************************************************************************** 
*/
