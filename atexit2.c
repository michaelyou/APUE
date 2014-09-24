#include "apue.h"

static void my_exit1(void);
static void my_exit2(void);

int main(void)
{
    if(atexit(my_exit2) != 0)
        printf("can't register my_exit2");

    if(atexit(my_exit1) != 0)
        printf("can't register my_exit1");
    if(atexit(my_exit1) != 0)
        printf("can't register my_exit1");
    printf("main is done\n");
    my_exit1();
    printf("the address of my_exit2 is %d\n", my_exit2);
    return 0;
}

static void my_exit1(void)
{
    printf("first exit handler\n");
}

static void my_exit2(void)
{
    printf("second exit handler\n");
}
