#include <stdio.h>

int main()
{
    int number = 0;

    for (int i = 1; i <= 10; ++i)
    {
        number = number + 1;
        printf("%i\n", number);
    }

    return 0;
}