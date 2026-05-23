#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8080

int main()
{
    int server_fd, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len;

    char buffer[1024] = {0};

    // Create socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (server_fd < 0)
    {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    printf("Socket created successfully\n");

    // Configure server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Bind socket
    if (bind(server_fd,
             (struct sockaddr *)&server_addr,
             sizeof(server_addr)) < 0)
    {
        perror("Bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Bind successful\n");

    // Listen for clients
    if (listen(server_fd, 5) < 0)
    {
        perror("Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Server listening on 127.0.0.1:%d\n", PORT);

    addr_len = sizeof(client_addr);

    // Accept client
    client_socket = accept(server_fd,
                           (struct sockaddr *)&client_addr,
                           &addr_len);

    if (client_socket < 0)
    {
        perror("Accept failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Client connected\n");

    // Receive message
    recv(client_socket, buffer, sizeof(buffer), 0);

    printf("Message from client: %s\n", buffer);

    // Send reply
    char *reply = "Hello from Server";

    send(client_socket, reply, strlen(reply), 0);

    printf("Reply sent\n");

    // Close sockets
    close(client_socket);
    close(server_fd);

    return 0;
}
