#include <stdio.h>

int main(void)
{
    FILE *file;

    file = fopen("Test.txt", "r");

    if (file == NULL)
    {
        printf("Error");
        return 0;
    }

    int x, y, z;

    fscanf(file, "%i %i %i", &x, &y, &z);

    printf("x: %i y: %i z: %i\n", x, y, z);

    fclose(file);

    return 0;
}