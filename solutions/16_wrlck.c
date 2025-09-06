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
        printf("Filename required to acquire a write lock!!\n");
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
    printf("\nHit enter to release the lock -> ");
    getchar();
    printf("\nLock released..\n");

    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);
    close(fd);

	return 0;
}

/*
 *********************************************** OUTPUT ********************************************

                                                TERMINAL 1 (Writer #1)

    piradians@3piradians:~/Documents/system_programming/solutions$ cc 16_wrlck.c -o wrlock.out
    piradians@3piradians:~/Documents/system_programming/solutions$ ./wrlock.out 14.c
    Trying to acquire write lock..
    Lock successfully acquired

    Hit enter to release the lock ->

    Lock released..
    piradians@3piradians:~/Documents/system_programming/solutions$
 
 ==================================================================================================

                                                TERMINAL 2 (Reader #1)

    ###  Reader waiting for the resource to be free for acquiring read lock  ###

    piradians@3piradians:~/Documents/system_programming/solutions$ cc 16_rdlck.c -o rdlock.out
    piradians@3piradians:~/Documents/system_programming/solutions$ ./rdlock.out 14.c
    Trying to acquire read lock..      ## waiting

    ###  Read lock is acquired after the write lock is released by the writer. ###

    Read lock acquired

    Hit enter to release the lock ->

    Lock released..
    piradians@3piradians:~/Documents/system_programming/solutions$

===================================================================================================

                                                TERMINAL 3 (Writer #2)

    ###  Trying to acquire a write lock when other process has a lock on it - Denied   ###
    
    piradians@3piradians:~/Documents/system_programming/solutions$ ./wrlock.out 14.c
    Trying to acquire write lock.. 
    fcntl: Resource temporarily unavailable

    ###  Trying to acquire write lock when other process has a read lock on the file - Denied  ###

    piradians@3piradians:~/Documents/system_programming/solutions$ ./wrlock.out 14.c
    Trying to acquire write lock.. 
    fcntl: Resource temporarily unavailable

    ###   Write lock acquired when there is no read or write lock by any other process  ###

    piradians@3piradians:~/Documents/system_programming/solutions$ ./wrlock.out 14.c
    Trying to acquire write lock.. 
    Lock successfully acquired

    Hit enter to release the lock ->

    Lock released..
    piradians@3piradians:~/Documents/system_programming/solutions$ 

****************************************************************************************************
*/
