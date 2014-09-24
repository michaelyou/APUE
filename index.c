#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int index1(char *s, char *t, int pos)
{
    int i = pos;
    int j = 0;
    int len1 = strlen(s);
    int len2 = strlen(t);
    while(i < len1 && j < len2) {
        if(s[i] == t[j]) {
            ++i;
            ++j;
        }
        else {
            i = i-j+1;
            j = 0;
        }
    }
    if(j >= len2)
        return i-len2;
    else
        return 0;
}

int main()
{
    int pos = 0;
    char s1[] = "hello new world!";
    char s2[] = "new";
    pos = index1(s1, s2, pos);
    printf("the posotion they match is %d \n", pos);

    return 0;
}
