/*
  ************************************************************************

  Name         : 19.c
  Author       : Pankaj Deopa
  Description  : Create a FIFO file by
                  a. mknod command
                  b. mkfifo command
                  c. Use strace command to find out, which command (mknod or mkfifo) is better.
                  d. mknod system call
                  e. mkfifo library function
  Date         : 1 Oct, 2025

  ************************************************************************
*/


#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main(){

    char name[50];
    printf("Enter the name of fifo file: ");
    scanf("%s", name);

    int ch;
    printf("Choose an option:\n1.) mknod system call\n2.) mkfifo system call\n=> ");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
        printf("Using mknod .\n");
        mknod(name, __S_IFIFO | 0744, 0);
        printf("FIFO file created using mknod\n");
        break;
    case 2:
        printf("Using mkfifo .\n");
        mkfifo(name, 0744);
        printf("FIFO file created using mkfifo\n");
        break;

    default:
        printf("Invalid choice\n");
        break;
    }

    return 0;
}

/*
 ********************************** OUTPUT ********************************

    piradians@3piradians:~/Documents/system_programming/hl2/p19$ cc 19.c
    piradians@3piradians:~/Documents/system_programming/hl2/p19$ ./a.out
    Enter the name of fifo file: fifo1
    Choose an option:
    1.) mknod system call
    2.) mkfifo system call
    => 1
    Using mknod .
    FIFO file created using mknod
    piradians@3piradians:~/Documents/system_programming/hl2/p19$ ls -l
    total 20
    -rw-rw-r-- 1 piradians piradians  1059 Oct  1 15:08 19.c
    -rwxrwxr-x 1 piradians piradians 70592 Oct  1 15:08 a.out
    prwxr--r-- 1 piradians piradians     0 Oct  1 15:08 fifo1
    piradians@3piradians:~/Documents/system_programming/hl2/p19$ ./a.out
    Enter the name of fifo file: fifo2
    Choose an option:
    1.) mknod system call
    2.) mkfifo system call
    => 2
    Using mkfifo .
    FIFO file created using mkfifo
    piradians@3piradians:~/Documents/system_programming/hl2/p19$ ls -l
    total 20
    -rw-rw-r-- 1 piradians piradians  1059 Oct  1 15:08 19.c
    -rwxrwxr-x 1 piradians piradians 70592 Oct  1 15:08 a.out
    prwxr--r-- 1 piradians piradians     0 Oct  1 15:08 fifo1
    prwxr--r-- 1 piradians piradians     0 Oct  1 15:09 fifo2
    piradians@3piradians:~/Documents/system_programming/hl2/p19$

***************************************************************************
*/
