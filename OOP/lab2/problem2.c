#include <stdio.h>

const char *my_strchr(char str[], char c)
{
    char *p = str;
    while (*p != '\0')
    {
        if (*p == c)
            return p;
        p += 1;
    }
    return NULL;
}

int main()
{
    char c = 'l', str[] = "hello";
    printf("%s", my_strchr(str, c));
    return 0;
}