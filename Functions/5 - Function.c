#include <stdio.h>

int main(void)
{
    int vector[10] = {9, 1, 0, 2, 5, 4, 3, 7, 6, 8};
    int i;

    ascendingOrder(vector, 10);

    for (i = 0; i < 10; i++)
    {
        printf("%i", vector[i]);
    }
    return 0;
}

void ascendingOrder(int vector[], int n)
{

    int temporary;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (vector[i] > vector[j])
            {
                temporary = vector[i];
                vector[i] = vector[j];
                vector[j] = temporary;
            }
        }
    }
}