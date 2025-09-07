/*
  ************************************************************************

  Name         : 1a.c
  Author       : Pankaj Deopa
  Description  : Create a soft link using system call
  Date         : 26 Aug, 2025

  ************************************************************************
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main () {

    if (symlink("sample.txt", "softlink_sys.txt") == 0) {
        printf("Soft link created: %s -> %s\n", "softlink_sys.txt", "sample.txt");
    } else {
        perror("symlink failed");
    }

	return 0;
}

/*
 ************************************ OUTPUT ****************************************
    
    piradians@3piradians:~/Documents/system_programming/hl1/p01$ cc 1a.c
    piradians@3piradians:~/Documents/system_programming/hl1/p01$ ./a.out
    Soft link created: softlink_sys.txt -> sample.txt
    piradians@3piradians:~/Documents/system_programming/hl1/p01$ 

 *********************************************************************************** 
*/
