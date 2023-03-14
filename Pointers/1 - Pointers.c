#include <stdio.h>

int main(void)
{
    int x = 10;
    int *pointer = &x;

    int y = 20;
    *pointer = y;
    printf("%i %i", x, y);
    return 0;
}