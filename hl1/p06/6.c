/*
  ************************************************************************

  Name         : 6c.c
  Author       : Pankaj Deopa
  Description  : Program to take input from STDIN and display on STDOUT. Use only read/write system calls
  Date         : 07 Sept, 2025

  ************************************************************************
*/

#include <unistd.h>

int main () {
    char buffer[1024];
    ssize_t bytesRead;

    bytesRead = read(0, buffer, sizeof(buffer)-1);

    if(bytesRead>0){
        buffer[bytesRead]= '\0';
        write(1, buffer, bytesRead);
    }

	return 0;
}


/*
 *********************************** OUTPUT *****************************************

    piradians@3piradians:~/Documents/system_programming/solutions/p06$ cc 6.c
    piradians@3piradians:~/Documents/system_programming/solutions/p06$ ./a.out
    hello world
    hello world
    piradians@3piradians:~/Documents/system_programming/solutions/p06$ 

*************************************************************************************
*/
