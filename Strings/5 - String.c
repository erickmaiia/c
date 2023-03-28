#include <stdio.h>

int main(void)
{
    if (equalStrings("home", "home"))
    {
        printf("Equal strings");
    }
    else
    {
        printf("Aren't equal strings");
    }
    return 0;
}

_Bool equalStrings(char s1[], char s2[])
{
    int i = 0;
    while (s1[i] == s2[i] && s1[i] != '\0' && s1[2] != '\0')
    {
        ++i;
    }

    if (s1[i] == '\0' && s2[i] == '\0')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}