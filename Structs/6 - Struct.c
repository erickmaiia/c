#include <stdio.h>

struct hours_info
{
    int hh;
    int mm;
    int ss;
};

int main(void)
{
    void takeHours(struct hours_info list[2]);
    void printHours(struct hours_info list[2]);

    struct hours_info hoursList[2];

    takeHours(hoursList);
    printHours(hoursList);
    return 0;
}

void takeHours(struct hours_info list[2])
{
    for (int i = 0; i < 2; i++)
    {
        printf("Write the %i hours hh:mm:ss: ", i + 1);
        scanf("%i:%i:%i", &list[i].hh, &list[i].mm, &list[i].ss);
    }
}

void printHours(struct hours_info list[2])
{
    for (int i = 0; i < 2; i++)
    {
        printf("The %i hour is %i:%i:%i\n", i + 1, list[i].hh, list[i].mm, list[i].ss);
    }
}