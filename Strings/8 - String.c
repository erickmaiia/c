#include <stdio.h>

int main(void)
{
    char name[20];
    int i = 0;
    printf("Write a random phrase: ");
    scanf("%s", name);

    while (name[i] != '\0')
    {
        alphabetical(name[i]);
        i++;
    }

    return 0;
}

void alphabetical(char var)
{
    if ((var >= 'a' && var <= 'z') || (var >= 'A' && var <= 'Z'))
    {
        printf("Is a letter\n");
    }
    else
    {
        printf("Is not a letter\n");
    }
}