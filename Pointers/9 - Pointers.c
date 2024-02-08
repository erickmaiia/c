#include <stdio.h>

int main(void)
{
    int vector[3] = {1, 2, 3};
    int *pointer = vector;

    printf("%i", *pointer);
    return 0;
}