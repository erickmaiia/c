#include <stdio.h>

int main()
{
    int i, y;
    printf("Insert a integer:\n");
    scanf("%i", &i);

    if (i >= 0)
    {
        do
        {
            y = i % 10;
            printf("%i", y);
            i /= 10;
        } while (i != 0);
        printf("\n");
    }
    else if (i < 1)
    {
        i = i * -1;
        printf("-");
        do
        {
            y = i % 10;
            printf("%i", y);
            i /= 10;
        } while (i != 0);
    }
    return 0;
}
