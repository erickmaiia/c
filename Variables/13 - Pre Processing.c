#include <stdio.h>

#define YES 100

#define NO -100

int main(void)
{
    int x;
    printf("Write a number: ");
    scanf("%i", &x);

    if (x <= 10)
    {
        printf("%i", NO);
    }
    else
    {
        printf("%i", YES);
    }

    return 0;
}