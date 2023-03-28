#include <stdio.h>

int sumVector(int vector[], const int n)
{
    int sum = 0;
    int *pointer;
    int *const finalVector = vector + n;

    for (pointer = vector; pointer < finalVector; ++pointer)
    {
        sum += *pointer;
    }
    return sum;
}

int main(void)
{
    int vector[10] = {5, 5, 5, 5, 5, 5, 5, 5, 5, 5};

    printf("The sum of the vectors is: %i", sumVector(vector, 10));

    return 0;
}