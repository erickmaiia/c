#include <stdio.h>

int main(void)
{
    char x[] = "aaaaaa";

    FILE *file = fopen("test1.txt", "w");

    int i = 0;

    while (x[i] != '\0')
    {
        fputc(x[i], file);
        i++;
    }

    return 0;
}