#include <stdio.h>

int main()
{
    int i;
    printf("Insert a integer from 1 to 5:");
    scanf("%i", &i);

    switch (i)
    {
    case 1:
        printf("First");
        break;
    case 2:
        printf("Second");
        break;
    default:
        printf("Invalid option");
    }
    return 0;
}
