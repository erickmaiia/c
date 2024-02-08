#include <stdio.h>

int main(void)
{
    char line[100];
    char character;
    int i;

    do
    {
        character = getchar();
        line[i] = character;
        i++;
    } while (character != '\n');

    line[i - 1] = '\0';

    printf("%s\n", line);

    return 0;
}