#include "apue.h"
#include "error.c"
#define BUFFSIZE 40

int main()
{
    int n;
    int fd;
    
    char buf[BUFFSIZE];
    if((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
        if(write(STDOUT_FILENO, buf, n) != n)
            err_sys("write error");

    if(n < 0)
        err_sys("read error");

    exit(0);
}
