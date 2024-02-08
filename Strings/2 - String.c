#include <stdio.h>

int main(void)
{

    char sentence1[] = {'h', 'e', 'l', 'l', 'o', ' '};
    char sentence2[] = {'w', 'o', 'r', 'l', 'd'};
    char newSentence[11] = {};

    concatString(sentence1, 6, sentence2, 5, newSentence);

    for (int i = 0; i < 11; i++)
    {
        printf("%c", newSentence[i]);
    }

    return 0;
}

void concatString(char x[], int lenX, char y[], int lenY, char z[])
{
    for (int i = 0; i < lenX; i++)
    {
        z[i] = x[i];
    }
    for (int j = 0; j < lenY; j++)
    {
        z[lenX + j] = y[j];
    }
}