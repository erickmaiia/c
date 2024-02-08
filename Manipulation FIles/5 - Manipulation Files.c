#include <stdio.h>

int main(void)
{
    FILE *file1 = fopen("Test1.txt", "r");

    FILE *file2 = fopen("Test2.txt", "w");

    if (file1 == NULL)
    {
        printf("Error");
        return 0;
    }
    if (file2 == NULL)
    {
        printf("Error");
        return 0;
    }

    copyContent(file1, file2);

    fclose(file1);
    fclose(file2);

    return 0;
}
void copyContent(FILE *file1, FILE *file2)
{
    char reader[1000];
    while (fgets(reader, 1000, file1) != NULL)
    {
        fputs(reader, file2);
    }
}