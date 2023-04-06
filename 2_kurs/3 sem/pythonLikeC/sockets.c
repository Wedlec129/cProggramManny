#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char** argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <ip> <port>\n", argv[0]);
        return 1;
    }

    struct sockaddr_in addr;

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    addr.sin_family = AF_INET;
    addr.sin_port = htons(atoi(argv[2]));
    addr.sin_addr.s_addr = inet_addr(argv[1]); 
    if (sock < 0) {
        perror("create"); return -1;
    }
    if (connect(sock, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        perror("connect"); return -2;
    }

    const size_t recv_size = 4096;
    char *data = (char*)calloc(recv_size, sizeof(char));
    recv(sock, (void*)data, recv_size, 0);
    printf("%s\n", data);
    free(data);

    close(sock);
    return 0;
}