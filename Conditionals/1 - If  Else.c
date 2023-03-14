#include <stdio.h>

int main()
{
    int age;
    printf("Please inform the age:");
    scanf("%i", &age);

    if (age < 18)
    {
        printf("Prohibited sale of alcoholic beverages");
    }
    else
    {
        printf("Sale of alcoholic beverages allowed");
    }
    return 0;
}
