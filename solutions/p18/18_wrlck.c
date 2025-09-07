/*
  ************************************************************************

  Name         : template.c
  Author       : Pankaj Deopa
  Description  : Template File
  Date         : 26 Aug, 2025

  ************************************************************************
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define RECORD_SIZE sizeof(int)

int main () {
    int fd, record_no, record_value;
    
    if ((fd = open("records.dat", O_RDWR | O_CREAT, 0664)) == -1) {
        perror("open");
        exit(1);
    }

    printf("Enter the record number to write [0, 1 or 2] : ");
    scanf("%d", &record_no);

    if (record_no < 0 || record_no > 2) {
        printf("error: record must be [0, 1. or 2] \n");
        close(fd);
        exit(1);
    }

    ssize_t offset = RECORD_SIZE * record_no;
    struct flock lock;
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = offset;
    lock.l_len = RECORD_SIZE;
    lock.l_pid = getpid();
    
    // acquire write lock
    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("fcntl lock");
        close(fd);
        exit(1);
    }

    // read the record form the file
    lseek(fd, offset, SEEK_SET);
    read(fd, &record_value, RECORD_SIZE);
    printf("The current value for record number %d is %d  \n", record_no, record_value);

    // update the record value
   record_value++;
    
    // write the value back to the file
    lseek(fd, offset, SEEK_SET);
    if (write(fd, &record_value, RECORD_SIZE) <= 0) {
        perror("write");
        close(fd);
        exit(1);
    }

    printf("PID - %d update the record value. New value :  %d\n",lock.l_pid,  record_value);

    // release the lock
    printf("Hit enter to release the lock -> ");
    getchar();
    getchar();

    lock.l_type = F_UNLCK;
    if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("fcntl unlock");
        close(fd);
        exit(1);
    }

    printf("\nLock released...\n");
    close(fd);

    return 0;
}


/*
 * **************** OUTPUT *******************
 *
 *
 *
 * 
*/
