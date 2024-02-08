#include <stdio.h>

int main(void)
{
    float area = areaRectangle(10.0, 20.0);

    printf("Area of rectangle is %.1f", area);

    return 0;
}

float areaRectangle(float x, float y)
{
    float area = x * y;
    return area;
}