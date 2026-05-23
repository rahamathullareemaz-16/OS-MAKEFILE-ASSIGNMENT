#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8080

int main()
{
    int sock;
    struct sockaddr_in server_addr;

    char buffer[1024] = {0};

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock < 0)
    {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    printf("Socket created successfully\n");

    // Configure server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connect to server
    if (connect(sock,
                (struct sockaddr *)&server_addr,
                sizeof(server_addr)) < 0)
    {
        perror("Connection failed");
        close(sock);
        exit(EXIT_FAILURE);
    }

    printf("Connected to server\n");

    // Send message
    char *msg = "Hello";

    send(sock, msg, strlen(msg), 0);

    printf("Message sent: %s\n", msg);

    // Receive reply
    recv(sock, buffer, sizeof(buffer), 0);

    printf("Reply from server: %s\n", buffer);

    // Close socket
    close(sock);

    return 0;
}
