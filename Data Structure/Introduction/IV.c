#include <stdio.h>

void changeInt(int *pointer1, int *pointer2)
{
    int temp = *pointer1;
    *pointer1 = *pointer2;
    *pointer2 = temp;
}

int main(void)
{
    void changeInt(int *pointer1, int *pointer2);
    int i = 0;
    int j = 1;

    printf("I: %i | J: %i\n", i, j);
    changeInt(&i, &j);
    printf("I: %i | J: %i", i, j);
    return 0;
}
