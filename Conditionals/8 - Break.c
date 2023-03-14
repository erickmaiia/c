#include <stdio.h>

int main(void)
{
    for (int i = 1; i <= 20; i++)
    {
        if (i % 3 == 0 && i % 9 == 0)
        {
            printf("%i Is divisible by 3 and 9\n", i);
            break;
        }
        else
        {
            printf("Is not divisible by 3 and 9\n");
        }
    }
    getchar();
    return 0;
}