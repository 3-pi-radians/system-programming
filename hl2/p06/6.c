/*
  ************************************************************************

  Name         : 6.c
  Author       : Pankaj Deopa
  Description  : Program to create three threads
  Date         : 27 Sept, 2025

  ************************************************************************
*/

#include <pthread.h>
#include <stdio.h>

void show_thread(void)
{
    printf("This is a thread\n");
}

int main()
{
    pthread_t th1, th2, th3;

    pthread_create(&th1, NULL, (void *)show_thread, NULL);
    pthread_create(&th2, NULL, (void *)show_thread, NULL);
    pthread_create(&th3, NULL, (void *)show_thread, NULL);
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    pthread_join(th3, NULL);

    return 0;
}

/*
 ****************************** OUTPUT **************************************
    
    piradians@3piradians:~/Documents/system_programming/hl2/p06$ ./a.out
    This is a thread
    This is a thread
    This is a thread

*****************************************************************************
*/
