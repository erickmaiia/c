#include <stdio.h>

struct dictionary
{
    char word[20];
    char definition[200];
};

_Bool equalStrings(const char s1[], const char s2[])
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

int searchString(const struct dictionary language[], const char search[], const int lenWords)
{
    _Bool equalStrings(const char s1[], const char s2[]);
    int i = 0;
    while (i < lenWords)
    {
        if (equalStrings(search, language[i].word))
        {
            return i;
        }
        else
        {
            ++i;
        }
    }
    return -1;
}

int main(void)
{
    char word[20] = {'\0'};
    int resultSearch;
    const struct dictionary dict[3] = {
        {"home", "A home, or domicile, is a space used as a permanent or semi-permanent residence for one or many humans,"},
        {"sleep", "Sleep can be described as a state of reduced mental and physical activity, in which consciousness is altered, and sensory activity is inhibited to a certain extent."},
        {"eat", "put (food) into the mouth and chew and swallow it."}};

    printf("Write a word: ");
    scanf("%s", word);

    resultSearch = searchString(dict, word, 3);

    if (resultSearch != -1)
    {
        printf("Definiton: %s", dict[resultSearch].definition);
    }
    else
    {
        printf("Word not found");
    }

    return 0;
}