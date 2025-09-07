/*
  ********************************************************************************

  Name         : 30.c
  Author       : Pankaj Deopa
  Description  : Program to run a script at a specific time using a Daemon process.
  Date         : 07 Sept, 2025

  *********************************************************************************
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>

int main () {

    if(!fork()){
        setsid();
        chdir("/");
        umask(0);
            while(1){
                sleep(4);
                printf("Child PID: %d\n", getpid());
                printf("Daemon Process is running...\n");
            }
    }
    else    
        exit(0);

	return 0;
}


/*
 ************************************* OUTPUT *******************************************
    
    piradians@3piradians:~/Documents/system_programming/solutions/p30$ cc 30.c
    piradians@3piradians:~/Documents/system_programming/solutions/p30$ ./a.out
    piradians@3piradians:~/Documents/system_programming/solutions/p30$ cat Child PID: 3730
    Daemon Process is running...
    Child PID: 3730
    Daemon Process is running...
    Child PID: 3730
    Daemon Process is running...
    Child PID: 3730
    Daemon Process is running...
    Child PID: 3730
    Daemon Process is running...

******************************************************************************************
*/
