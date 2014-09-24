#include "apue.h"
#include "error.c"
#include <fcntl.h>

int main()
{
    if(open("tempfile", O_RDWR) < 0)
        err_sys("open error");
    if(unlink("tempfile") < 0)
        err_sys("unlink error");
    printf("file unlinked \n");

    sleep(15);
    printf("done");
    exit(0);
}
