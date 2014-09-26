#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>          /*for struct hostent*/
#include <sys/types.h>
#include <netinet/in.h>     /*for struct sockaddr_in*/
#include <sys/socket.h>
#include <unistd.h>

#define SERVPORT 3333
#define MAXDATASIZE 100

int main(int argc, char **argv)
{
    int sock_fd, recvbypes;
    char buf[MAXDATASIZE];
    //struct hostent *host;
    struct sockaddr_in serv_addr;
    if(argc < 2) {
        fprintf(stderr, "please input the server hostname!\n");
        exit(1);
    }
    /*
    if((host = gethostbyname(argv[1])) == NULL) {
        herror("gethostname error!\n");
        exit(1);
    }
    */
    if((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket create error\n");
        exit(1);
    }
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port=htons(SERVPORT);
    serv_addr.sin_addr.s_addr=inet_addr(argv[1]);
    bzero(&(serv_addr.sin_zero), 8);
    if(connect(sock_fd, (struct sockaddr *)&serv_addr, sizeof(struct sockaddr)) == -1) {
        perror("connnet error!\n");
        exit(1);
    }
    if((recvbypes = recv(sock_fd, buf, MAXDATASIZE, 0)) == -1) {
        perror("recv error!\n");
        exit(0);
    }
    buf[recvbypes] = '\0';
    printf("received:%s", buf);
    close(sock_fd);
    return 0;
}
