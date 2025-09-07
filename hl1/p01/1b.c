/*
  ************************************************************************

  Name         : 1b.c
  Author       : Pankaj Deopa
  Description  : Create a hard link using system call.
  Date         : 26 Aug, 2025

  ************************************************************************
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main () {
    if (link("sample.txt", "hardlink_sys.txt") == 0) {
        printf("Hard link created: %s -> %s\n","hardlink_sys.txt", "sample.txt");
    } else {
        perror("link failed");
    }

	return 0;
}

/*
 ********************************************* OUTPUT *************************************
    
    piradians@3piradians:~/Documents/system_programming/hl1/p01$ cc 1b.c
    piradians@3piradians:~/Documents/system_programming/hl1/p01$ ./a.out
    Hard link created: hardlink_sys.txt -> sample.txt
    piradians@3piradians:~/Documents/system_programming/hl1/p01$

************************************************************************************* *
*/
