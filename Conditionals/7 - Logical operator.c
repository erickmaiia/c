#include <stdio.h>

int main(void)
{
    int age;

    /*     printf("Your age is: ");
        scanf("%i", &age);

        if (age >= 20 && age <= 40)
        {
            printf("Sucessfully");
        }
        else
        {
            printf("Failed");
        } */
    printf("Your age is: ");
    scanf("%i", &age);

    if (age >= 20 || age <= 40)
    {
        printf("Sucessfully");
    }
    else
    {
        printf("Failed");
    }
    return 0;
}