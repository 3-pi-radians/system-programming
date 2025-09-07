/*
  ****************************************************************************

  Name         : 1c.c
  Author       : Pankaj Deopa
  Description  : Create a FIFO using mkfifo
  Date         : 26 Aug, 2025

  ***************************************************************************
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main () {
    // create FIFO with read/write permissions
    if (mkfifo("myfifo", 0666) == 0) {
        printf("FIFO created: %s\n", "myfifo");
    } else {
        perror("mkfifo failed");
    }

	return 0;
}


/*
 *********************************************** OUTPUT ******************************************

    piradians@3piradians:~/Documents/system_programming/hl1/p01$ cc 1c.c
    piradians@3piradians:~/Documents/system_programming/hl1/p01$ ./a.out
    FIFO created: myfifo
    piradians@3piradians:~/Documents/system_programming/hl1/p01$ ls -l myfifo
    prw-rw-r-- 1 piradians piradians 0 Sep  7 17:57 myfifo
    piradians@3piradians:~/Documents/system_programming/hl1/p01$ 

***************************************************************************************************
*/
