#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *p = (int *)calloc(5, sizeof(int));

    *(p+3) = 10;

    for (int i = 0; i < 5; i++)
    {
        printf("P[%i] adress is: %p | P[%i] value is: %i\n", i, &p[i], i, *(p + i));
    }
    return 0;
}