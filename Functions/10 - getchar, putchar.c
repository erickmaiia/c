#include <stdio.h>

int main(void)
{
    /*     char x[10];
        int i = 0;
        while ((x[i] = getchar()) != '\n' && i < 8)
        {
            ++i;
        }
        x[++i] = '\0';
        printf("%s", x); */

    char x;
    int i = 0;
    while ((x = getchar()) != '\n')
    {
        putchar(x);
    }

    return 0;
}