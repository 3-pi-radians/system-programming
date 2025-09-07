/*
  ****************************************************************************************

   Name         : 13.c
   Author       : Pankaj Deopa
   Description  : Program to wait for a STDIN for 10 seconds using select.  Write a proper print statement to
                    verify whether the data is available within 10 seconds or not. 
   Date         : 05 Sept, 2025

  ***************************************************************************************
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/select.h>

int main () {
    fd_set readfds;
    struct timeval timeout;
    int r;

    char buffer[100];

    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO, &readfds);

    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    printf("Enter text (Waiting for 10 seconds ....) : ");
fflush(stdout);
    r = select(STDIN_FILENO + 1, &readfds, NULL, NULL, &timeout);

    if (r > 0) {
        printf("You have entered text "); 
        if (FD_ISSET(STDIN_FILENO, &readfds)) {
            if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
                printf(": %s", buffer);
            }
        }
   } else if (r == 0) {
        printf("\nTimeout: You have not entered any text within 10 seconds\n");
    } else {
        perror("select");
        return 1;
    }


    
	return 0;
}


/*
 ******************************************** OUTPUT *****************************************

   piradians@3piradians:~/Documents/system_programming/solutions$ cc 13.c
   piradians@3piradians:~/Documents/system_programming/solutions$ ./a.out
   Enter text (Waiting for 10 seconds ....) : 
   Timeout: You have not entered any text within 10 seconds
   piradians@3piradians:~/Documents/system_programming/solutions$ ./a.out
   Enter text (Waiting for 10 seconds ....) : Hello world
   You have entered text : Hello world
   piradians@3piradians:~/Documents/system_programming/solutions$ 
   
   **********************************************************************************************
*/


