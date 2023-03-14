#include <stdio.h>

int main()
{
    int age;
    printf("Please inform the age:");
    scanf("%i", &age);

    if (age < 5)
    {
        printf("Baby");
    }
    else if (age > 5 && age <= 10)
    {
        printf("Children");
    }
    else if (age > 10 && age <= 18)
    {
        printf("Young");
    }
    else if (age > 18 && age <= 50)
    {
        printf("Adult");
    }
    else
    {
        printf("Elderly");
    }

    return 0;
}
