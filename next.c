#include "next.h"
#include <string.h>

void get_next(char *s, int *next)
{
    int i, j;
    int len = strlen(s);
    i = 0;
    j = -1;
    next[0] = -1;
    while(i < (len - 1)) {
        if(j == -1 || s[i] == s[j]) {
            i++;
            j++;
            next[i] = j;
        }
        else
            j = next[j];
    }
}
