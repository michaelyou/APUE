#include <stdio.h>

#define HAHA

int main()
{
    fprintf(stdout,
            "this is a test\n"
            "this is two test\n"
#if defined HAHA
            "this is haha test\n"
#endif

#if defined WAHAHA
            "this is wohaha test\n"
#endif
            "good job\n");
}
