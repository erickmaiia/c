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

    char pharse[100];

    while (fgets(pharse, 100, file) != NULL)
    {
        printf("%s", pharse);
    }

    fclose(file);

    return 0;
}