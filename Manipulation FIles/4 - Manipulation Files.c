#include <stdio.h>

int main(void)
{
    FILE *file;

    file = fopen("Test.txt", "a");

    if (file == NULL)
    {
        printf("Error");
        return 0;
    }

    fprintf(file, "First line\n");

    char phrase[] = "Second line\n";

    fputs(phrase, file);

    char character = '3';
    fputc(character, file);

    fclose(file);

    return 0;
}