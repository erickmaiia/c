#include <stdio.h>

void copyString(char *copy, char *paste)
{
    while (*copy != '\0')
    {
        *paste = *copy;
        ++copy;
        ++paste;
    }
    *copy = '\0';
}

int main(void)
{
    char string1[] = "Hello world!!!";
    char string2[20];

    copyString(string1, string2);
    printf("%s\n", string2);

    return 0;
}