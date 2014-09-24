#include "apue.h"
#include "error.c"

void pr_stdio(const char *, FILE *);
int is_unbuffered(FILE *);
int is_linebuffered(FILE *);
int buffer_size(FILE *);

int main()
{
    FILE *fp;
    fputs("enter any character\n", stdout);
    if(getchar() == EOF)
        err_sys("gerchar error");
    fputs("one line to standard error\n", stderr);

    pr_stdio("stdin", stdin);
    pr_stdio("stdout", stdout);
    pr_stdio("stderr", stderr);

    if((fp = fopen("/etc/passwd", "r")) == NULL)
        err_sys("fopen error");
    if(getc(fp) == EOF)
        err_sys("getc error");
    pr_stdio("/etc/passwd", fp);

    exit(0);
}

void pr_stdio(const char *name, FILE*fp)
{
    printf("stream = %s, ", name);
    if(is_unbuffered(fp))
        printf("unbuffered");
    else if(is_linebuffered(fp))
        printf("line_buffered");
    else
        printf("fully buffered");

    printf(", buffer size is = %d \n", buffer_size(fp));
}

#if defined(_IO_UNBUFFERED)
printf("_SNBF \n");

int is_unbuffered(FILE *fp)
{
    return (fp->_flags & _IO_UNBUFFERED);
}

int is_linebuffered(FILE *fp)
{
    return (fp->_flags & _IO_LINE_BUF);
}

int buffer_size(FILE *fp)
{
    return (fp->_IO_buf_end - fp->_IO_buf_base);
}

#elif defined(_SNBF)
printf("_SNBF \n");

int is_buffered(FILE *fp)
{
    return (fp->_flags & _SNBF);
}

int is_linebuffered(FILE *fp)
{
    return (fp->_flags & _SLBF);
}

int buffer_size(FILE *fp)
{
    return (fp->_bf._size);
}

#elif defined(_IONBF)
printf("_IONBF");

#ifdef _lp64
#define _flag _pad[4]
#define _ptr _pad[1]
#define _base _pad[2]
#endif

int is_unbuffered(FILE *fp)
{
  return(fp->_flags & _IONBF);  
}

int is_linebuffered(FILE *fp)
{
    return (fp->_flags & _IOLBF);
}

int buffer_size(FILE *fp)
{
    #ifdef _LP64
        return (fp->base - fp->_ptr);
    #else
        return (BUFSIZE);
    #endif
}

#else

#error unkown stdio implementation!

#endif
