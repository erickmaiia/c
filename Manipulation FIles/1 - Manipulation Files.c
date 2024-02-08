#include <stdio.h>

int main(void)
{
    FILE *file;

    file = fopen("Test.txt", "w");

    fprintf(file, "hamudzinho");

    fclose(file);

    return 0;
}