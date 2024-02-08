#include <stdio.h>

int main()
{
    int base;
    int height;
    int area;
    printf("Write the base value: ");
    scanf("%i", &base);
    printf("Write the height value: ");
    scanf("%i", &height);
    area = base * height;
    printf("The area is %i\n", area);
    return 0;
}