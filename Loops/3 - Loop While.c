#include <stdio.h>

int main()
{
    int factorial;
    int cont = 1;
    int total = 1;
    printf("Write the number to become factorial:");
    scanf("%i", &factorial);

    while (factorial != 0)
    {
        total *= cont;
        ++cont;
        --factorial;
    }
    printf("%i", total);
    return 0;
}