#include <stdio.h>

int main(void)
{
    int vector[3] = {1, 2, 3};

    int *pointer = &vector[0];
    printf("%p\n", pointer);

    pointer = &vector[1];
    printf("%p\n", pointer);

    pointer = &vector[2];
    printf("%p\n", pointer);
    return 0;
}