#include <stdio.h>

int main()
{
    int myAge;
    myAge = 19;
    int motherAge = 52;
    int fatherAge = 49;
    int brotherAge = 25;
    int totalAge;
    totalAge = myAge + motherAge + fatherAge + brotherAge;
    printf("The total age is %i\n", totalAge);
    return 0;
}