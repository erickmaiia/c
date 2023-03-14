#include <stdio.h>

int main(void)
{
    int x = 10;
    double y = 2.5;
    char z = 'a';

    int *pX = &x;
    double *pY = &y;
    char *pZ = &z;

    double sum = *pX + *pY;

    int *result = 6422272;

    printf("Adress x: %i, Value x: %i\n", pX, *pX);
    printf("Adress y: %i, Value y: %f\n", pY, *pY);
    printf("Adress z: %i, Value z: %c\n", pZ, *pZ);
    printf("%f\n", sum);
    printf("%i", *result);

    return 0;
}