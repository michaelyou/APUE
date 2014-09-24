#include "next.h"
#include <stdio.h>

int kmpsearch(char *s,  char *p)
{
    int i = 0;
    int j = 0;
    int slen = strlen(s);
    int plen = strlen(p);
    while(i < slen && p < plen) {
        if(j == -1 || s[i] == p[j]) {
            i++;
            j++;

        }
        else
            j = next[j];
    }
    if(j == plen)
        return i-j;
    else
        return -1;
}
