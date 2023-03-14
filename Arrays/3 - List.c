#include <stdio.h>

int main(void)
{

    float note[5];
    float total;
    float average;
    for (int i = 0; i < 5; ++i)
    {
        printf("Write the %i note:", i);
        scanf("%f", &note[i]);
    }
    for (int i = 0; i < 5; ++i)
    {
        total += note[i];
    }
    average = total / 5;
    printf("%f", average);

    return 0;
}