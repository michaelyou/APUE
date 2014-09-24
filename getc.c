#include "apue.h"
#include "error.c"

int main()
{
    int c;
    setbuf(stdin, NULL);
    setbuf(stdout, NULL);
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    while((c = getc(stdin)) != EOF)
        if(putc(c, stdout) == EOF)
            err_sys("output error");

    if(ferror(stdin))
        err_sys("input error");
    exit(0);
}
