#include <stdio.h>

int main(void)
{
    float a, b, sum;
    printf("Write two numbers: ");
    scanf("%f", &a);
    scanf("%f", &b);
    sum = digitSum(a, b);
    printf("The sum is: %f\n", sum);
    return 0;
}

float digitSum(float x, float y)
{

    if (x < 0)
    {
        x = absoluteValue(x);
    }
    if (y < 0)
    {
        y = absoluteValue(y);
    }

    return x + y;
}

float absoluteValue(float num)
{
    return num * -1;
}