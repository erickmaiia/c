#include <stdio.h>

int main(void)
{
    char sentence[20];

    printf("Write a string: ");
    scanf("%s", sentence);

    int num = stringLen(sentence);

    printf("The string has %i characters", num);

    return 0;
}

int stringLen(char x[])
{
    int count = 0;

    while (x[count] != '\0')
    {
        ++count;
    }
    ++count; // because '\0' is the last character invisible

    return count;
}