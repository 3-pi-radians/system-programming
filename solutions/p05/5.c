/*
  ************************************************************************

  Name         : 5.c
  Author       : Pankaj Deopa
  Description  : Program to create five new files with infinite loop. Execute the program in the background
                 and check the file descriptor table at /proc/pid/fd.
  Date         : 26 Aug, 2025

  ************************************************************************
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main () {
	int fd[5];
	
	 char *files[5] = {
        	"File1.txt",
	       	"File2.txt", 
		"File3.txt",
	       	"File4.txt", 
		"File5.txt"
    	};

	printf("Process Id :  %d\n", getpid());

	for (int i = 0; i < 5; i++) {
		fd[i] = creat(files[i], 0644);
		if (fd[i] == -1) {
			perror("creat");
			return 1;
		}

		printf("%s created successfully with file descriptor - %d\n", files[i], fd[i]);
	}

	for (;;);

	return 0;
}


/*
 ********************************************** OUTPUT *****************************************
  
  piradians@3piradians:~/Documents/system_programming/solutions$ cc 5.c
  piradians@3piradians:~/Documents/system_programming/solutions$ ./a.out
  Process Id :  3844
  File1.txt created successfully with file descriptor - 3
  File2.txt created successfully with file descriptor - 4
  File3.txt created successfully with file descriptor - 5
  File4.txt created successfully with file descriptor - 6
  File5.txt created successfully with file descriptor - 7
 
  piradians@3piradians:~/Documents/system_programming/solutions$ cd /proc/3844/fd
  piradians@3piradians:/proc/3844/fd$ ls -l
  total 0
  lrwx------ 1 piradians piradians 64 Aug 26 18:24 0 -> /dev/pts/0
  lrwx------ 1 piradians piradians 64 Aug 26 18:24 1 -> /dev/pts/0
  lrwx------ 1 piradians piradians 64 Aug 26 18:24 2 -> /dev/pts/0
  l-wx------ 1 piradians piradians 64 Aug 26 18:24 3 -> /home/piradians/Documents/system_programming/solutions/File1.txt
  l-wx------ 1 piradians piradians 64 Aug 26 18:24 4 -> /home/piradians/Documents/system_programming/solutions/File2.txt
  l-wx------ 1 piradians piradians 64 Aug 26 18:24 5 -> /home/piradians/Documents/system_programming/solutions/File3.txt
  l-wx------ 1 piradians piradians 64 Aug 26 18:24 6 -> /home/piradians/Documents/system_programming/solutions/File4.txt
  l-wx------ 1 piradians piradians 64 Aug 26 18:24 7 -> /home/piradians/Documents/system_programming/solutions/File5.txt
  piradians@3piradians:/proc/3844/fd$ 

 **************************************************************************************************** 
*/
