/*
  ************************************************************************

  Name         : client.c
  Author       : Pankaj Deopa
  Description  : Program to communicate between two machines using socket.
  Date         : 1 Oct, 2025

  ************************************************************************
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8081

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    const char *message = "Hello from client";
    char buffer[1024] = {0};

    sock = socket(AF_INET, SOCK_STREAM, 0);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);
    
    connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    send(sock, message, strlen(message), 0);
    printf("Message sent to server\n");

    read(sock, buffer, 1024);
    printf("Received from server: %s\n", buffer);

    close(sock);

    return 0;
}

/*
 * *************************************** OUTPUT ***************************************

                                    TERMINAL 1 (server)

    piradians@3piradians:~/Documents/system_programming/hl2/p33$ cc server.c -o server
    piradians@3piradians:~/Documents/system_programming/hl2/p33$ ./server
    Server is listening on port 8081
    Received from client: Hello from client
    Response sent to client
    piradians@3piradians:~/Documents/system_programming/hl2/p33$ 

======================================================================================

                                    TERMINAL 2 (client)

    piradians@3piradians:~/Documents/system_programming/hl2/p33$ cc client.c -o client
    piradians@3piradians:~/Documents/system_programming/hl2/p33$ ./client
    Message sent to server
    Received from server: Hello from server

    piradians@3piradians:~/Documents/system_programming/hl2/p33$

******************************************************************************************
*/

