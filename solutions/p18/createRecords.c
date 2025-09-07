#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd = open("records.dat", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    int arr[3] = {1, 2, 3};  // our records
    ssize_t written = write(fd, arr, sizeof(arr));
    if (written == -1) {
        perror("write");
        close(fd);
        exit(1);
    }

    printf("Created records.dat with 3 binary integers (1, 2, 3)\n");

    close(fd);
    return 0;
}
