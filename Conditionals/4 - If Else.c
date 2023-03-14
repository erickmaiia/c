#include <stdio.h>

int main()
{
    int number1, number2;
    printf("Insert two integer:\n");
    scanf("%i"
          "%i",
          &number1, &number2);
    if (number1 % number2 == 0)
    {
        printf("%i is divisible per %i", number1, number2);
    }
    else
    {
        printf("Not divisible");
    }
    return 0;
}
