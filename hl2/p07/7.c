/*
  ************************************************************************

  Name         : 7.c
  Author       : Pankaj Deopa
  Description  : Program to print the created thread ids
  Date         : 29 Sept, 2025

  ************************************************************************
*/

#include <stdio.h>
#include <fcntl.h>
#include <pthread.h>

void display() {
    printf("Message printed by thread : %ld\n", pthread_self());
}

int main () {
    pthread_t th1, th2, th3;

    pthread_create(&th1, NULL, (void*) display, NULL);
    pthread_create(&th2, NULL, (void*) display, NULL);
    pthread_create(&th3, NULL, (void*) display, NULL);
    pthread_join(th1, NULL);
    pthread_join(th2 ,NULL);
    pthread_join(th3, NULL);

	return 0;
}


/*
 ********************************* OUTPUT **********************************

    piradians@3piradians:~/Documents/system_programming/hl2/p07$ ./a.out
    Message printed by thread : 280742488895904
    Message printed by thread : 280742471987616
    Message printed by thread : 280742480441760

****************************************************************************
*/
