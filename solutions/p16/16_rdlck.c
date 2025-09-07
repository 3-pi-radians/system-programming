/*
  ************************************************************************

  Name         : 16_rdlck.c
  Author       : Pankaj Deopa
  Description  : Implement read lock.
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
        printf("Filename required to acquire a read lock!!\n");
        return 1;
    }

    int fd =  open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    struct flock lock;
    lock.l_type = F_RDLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;

    printf("Trying to acquire read lock.. \n");

    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("fcntl");
        close(fd);
        exit(1);
    }

    printf("Read lock acquired\n");
    printf("\nHit enter to release the lock -> ");
    getchar();

    lock.l_type = F_UNLCK;
   if(fcntl(fd, F_SETLK, &lock) == -1){
        perror("fcntl");
    } else {
        printf("\nLock released..\n");
    }

    close(fd);
	return 0;
}

/*
 *********************************************************** OUTPUT *******************************************
                                                                         
                                             TERMINAL 1 (Reader #1)

    ###   Acquiring read lock on file sample.txt  ###
    
    piradians@3piradians:~/Documents/system_programming/solutions/p16$ ./a.out sample.txt
    Trying to acquire read lock.. 
    Read lock acquired

    Hit enter to release the lock ->

    Lock released..
    piradians@3piradians:~/Documents/system_programming/solutions/p16$ 

=============================================================================================================

                                             TERMINAL 2 (Reader #2)

    ###   Simultaneously acquiring read lock on file sample.txt - Allowed   ###

    piradians@3piradians:~/Documents/system_programming/solutions/p16$ ./a.out sample.txt
    Trying to acquire read lock..
    Read lock acquired

    Hit enter to release the lock ->
    
    Lock released..
    piradians@3piradians:~/Documents/system_programming/solutions/p16$

=============================================================================================================

                                             TERMINAL 3 (Writer #1)

    ###  Trying to acquire lock on file sample.txt when read lock is already acquired by another process. ###

    piradians@3piradians:~/Documents/system_programming/solutions/p16$ ./a.out sample.txt
    Trying to acquire write lock.. 
    fcntl: Resource temporarily unavailable

    ###  Acquiring write lock successful after the read lock is released. ###
     
    piradians@3piradians:~/Documents/system_programming/solutions/p16$ ./a.out sample.txt
    Trying to acquire write lock.. 
    Lock successfully acquired

    Hit enter to release the lock ->

    Lock released..
    piradians@3piradians:~/Documents/system_programming/solutions/p16$ 

 ***********************************************************************************************************
*/
