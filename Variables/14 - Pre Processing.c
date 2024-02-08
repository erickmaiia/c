#include <stdio.h>

#define PI 3.14159
#define NULLL 0

double circleArea(double ray)
{
    return ray * ray * PI;
}

int main(void)
{
    double circleArea(double ray);
    double r;
    int i = 3;

    while (i != NULLL)
    {
        printf("Write the ray: ");
        scanf("%lf", &r);
        printf("The circle area is: %lf\n", circleArea(r));
        i--;
    }

    return 0;
}