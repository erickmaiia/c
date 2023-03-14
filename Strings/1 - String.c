#include <stdio.h>

int main(void)
{
    char test[] = {'b', 'r', 'a', 'z', 'i', 'l'};

    for (int i = 0; i < 6; i++)
    {
        printf("%c", test[i]);
    }

    return 0;
}