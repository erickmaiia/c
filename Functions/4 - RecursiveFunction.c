#include <stdio.h>

int main(void)
{
    int num;

    printf("Write a number: ");
    scanf("%i", &num);
    num = recursiveFunc(num);
    printf("The factorial number is: %i\n", num);
    return 0;
}

int recursiveFunc(int x)
{
    int result;

    if (x == 0)
    {
        result = 1;
    }
    else
    {
        result = x * recursiveFunc(x - 1);
    }
    return result;
}
