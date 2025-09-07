/*
  ************************************************************************

  Name         : reservation.c
  Author       : Pankaj Deopa
  Description  : Program to open the file, implement write lock, read the ticket number, increment the number and print
                  the new ticket number then close the file
  Date         : 06 Sept, 2025

  ************************************************************************
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main () {
   int fd;
   char buf[20];
   struct flock lock;
   
   fd = open("initialize.txt", O_RDWR);
   if (fd == -1) {
       perror("open");
       exit(1);
    }

   lock.l_type = F_WRLCK;
   lock.l_whence = SEEK_SET;
   lock.l_start = 0;
   lock.l_len = 0;

   printf("Trying to acquire write lock...\n");

   if (fcntl(fd, F_SETLKW, &lock) == -1) {
       perror("fcntl lock");
       close(fd);
       exit(1);
   }

   printf("Write lock acquired successfully. \n");

   // set the seek position at the begining of file.
   lseek(fd, 0, SEEK_SET);

   // read the content of file into a buffer
   int n = read(fd, buf, sizeof(buf)-1);
   if (n <= 0) {
       perror("read");
       close(fd);
       exit(1);
   }

   buf[n] = '\n'; // manually add null terminator

   int ticket = atoi(buf);
   printf("Ticket number before updating : %d\n", ticket);
   ticket++;

   // convert ticket into the string format and store into buffer.
   snprintf(buf, sizeof(buf),"%d\n", ticket);

   // write the ticket number into the file.
   lseek(fd, 0, SEEK_SET);
   ftruncate(fd, 0);
   if(write(fd, buf, strlen(buf)) == -1) {
       perror("write");
       close(fd);
       exit(1);
   }

   printf("Your ticket number has been updated successfully : %d\n",ticket);

   // release the lock
   lock.l_type = F_UNLCK;
   if (fcntl(fd, F_SETLK, &lock) == -1) {
       perror("fcntl unlock");
       close(fd);
       exit(1);
   }

   printf("Lock released. \n");
   close(fd);

   return 0;
}


/*
 ************************************************* OUTPUT ********************************************

    piradians@3piradians:~/Documents/system_programming/solutions/p17$ cc reservation.c -o reservation
    piradians@3piradians:~/Documents/system_programming/solutions/p17$ ./reservation
    Trying to acquire write lock...
    Write lock acquired successfully. 
    Ticket number before updating : 1
    Your ticket number has been updated successfully : 2
    Lock released. 
    piradians@3piradians:~/Documents/system_programming/solutions/p17$ ./reservation
    Trying to acquire write lock...
    Write lock acquired successfully. 
    Ticket number before updating : 2
    Your ticket number has been updated successfully : 3
    Lock released. 
    piradians@3piradians:~/Documents/system_programming/solutions/p17$ 

 ******************************************************************************************************
*/
