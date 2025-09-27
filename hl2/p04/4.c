/*
  ************************************************************************

  Name         : 4.c
  Author       : Pankaj Deopa
  Description  : Program to measure how much time is taken to execute 100 getppid()
                    system call using time stamp counter
  Date         : 27 Sept, 2025

  ************************************************************************
*/

#include <unistd.h>
#include <stdio.h>
#include <time.h>

int main() {

    clock_t start, end;
    start = clock();

    for (int i = 0; i < 100; i++) {
        getppid();
    }

    end = clock();
    double duration = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("The Time taken for 100 getppid system calls: %lf seconds\n", duration);
    return 0;
}

/*
 ******************************* OUTPUT **************************************
    
    piradians@3piradians:~/Documents/system_programming/hl2/p04$ cc 4.c
    piradians@3piradians:~/Documents/system_programming/hl2/p04$ ./a.out
    The Time taken for 100 getppid system calls: 0.000019 seconds
    piradians@3piradians:~/Documents/system_programming/hl2/p04$ 

*********************************************************************************
*/

