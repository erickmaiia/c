#include <stdio.h>

int main(void)
{
    void clearBuffer();
    char a, b, c;

    a = getchar();
    clearBuffer();

    b = getchar();
    clearBuffer();

    c = getchar();
    clearBuffer();

    printf("%c %c %c", a, b, c);
    return 0;
}

void clearBuffer()
{
    char c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}