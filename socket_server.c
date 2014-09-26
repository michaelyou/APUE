#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SERVPORT 3333
#define BACKLOG 10

int main()
{
    int sock_fd, client_fd;
    socklen_t sin_size;
    struct sockaddr_in my_addr;
    struct sockaddr_in remote_addr;
    if((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket create error!\n");
        exit(1);
    }
    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(SERVPORT);
    my_addr.sin_addr.s_addr = INADDR_ANY;
    bzero(&(my_addr.sin_zero), 8);
    if((bind(sock_fd, (struct sockaddr *)&my_addr, sizeof(struct sockaddr))) == -1) {
        perror("bind error!\n");
        exit(1);
    }
    if(listen(sock_fd, BACKLOG) == -1) {
        perror("listen error!\n");
        exit(-1);
    }
    while(1) {
        sin_size = sizeof(struct sockaddr_in);
        if((client_fd = accept(sock_fd, (struct sockaddr *)&remote_addr, &sin_size)) == -1) {
            perror("accept error!\n");
            continue;
        }
        printf("received a connection from %s\n", inet_ntoa(remote_addr.sin_addr));
        if(!fork()) {
            if(send(client_fd, "hello, you are connected!\n", 26, 0) == -1) {
                perror("send error!\n");
                exit(0);
            }
            close(client_fd);
            exit(0);
        }
        close(client_fd);
    }
    
     return 0; 
}
