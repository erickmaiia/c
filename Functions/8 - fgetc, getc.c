#include <stdio.h>

int main(void)
{

    char x[100];
    FILE *file = fopen("test1.txt", "r");
    int i = 0;

    while ((x[i] = fgetc(file)) != EOF) // or function call getc
    {
        ++i;
    }
    x[i] = '\0';

    printf("%s", x);

    return 0;
}