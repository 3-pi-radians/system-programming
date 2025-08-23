#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
	fork();
	fork();
	fork();
	printf("Hello World ....\n");

	wait(0);
	return 0;
}

