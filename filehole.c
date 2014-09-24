#include "apue.h"
#include <fcntl.h>
#include "error.c"

char buf1[] = "abcdefghij";
char buf2[] = "wBCDEFGHIJ";

int main()
{
    int fd;
    if((fd = open("file.hole", O_RDWR | O_CREAT | O_TRUNC, FILE_MODE)) < 0)
        err_sys("creat error");

    if(write(fd, buf1, 10) != 10)
        err_sys("buf1 write error");
    //printf("the offset is %d \n", offset);

    if(lseek(fd, 16384, SEEK_SET) == -1)
        err_sys("lseek error");

    if(write(fd, buf2, 10) != 10)
        err_sys("buf2 write error");

    exit(0);
}
