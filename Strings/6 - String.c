#include <stdio.h>

int main(void)
{
    char firstName[30];
    char lastName[30];

    printf("Insert your first name and last name: ");
    scanf("%s%s", &firstName, &lastName);
    printf("%s %s", firstName, lastName);
    return 0;
}