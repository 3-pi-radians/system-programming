/*
  ************************************************************************

  Name         : 16_wrlck.c
  Author       : Pankaj Deopa
  Description  : Implement write lock.
  Date         : 06 Sept, 2025

  ************************************************************************
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main (int argc, char* argv[]) {
    if (argc != 2) {
        printf("Filename required to acquire a wirte lock!!\n");
        return 1;
    }

    int fd =  open(argv[1], O_RDWR | O_CREAT, 0644);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    struct flock lock;
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;

    printf("Trying to acquire write lock.. \n");

    if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("fcntl");
        close(fd);
        exit(1);
    }

    printf("Lock successfully acquired\n");
    printf("\nEnter any character to release : ");
    getchar();
    printf("\nLock released..\n");

    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);
    close(fd);

	return 0;
}


/*
 ********************************************* OUTPUT *******************************************

    piradians@3piradians:~/Documents/system_programming/solutions$ cc 16_wrlck.c
    piradians@3piradians:~/Documents/system_programming/solutions$ ./a.out
    Filename required to acquire a wirte lock!!
    piradians@3piradians:~/Documents/system_programming/solutions$ ./a.out 14.c
    Trying to acquire write lock.. 
    Lock successfully acquired
    
    Enter any character to release : k
    
    Lock released..
 
 ***********************************************************************************************
 * 
*/
