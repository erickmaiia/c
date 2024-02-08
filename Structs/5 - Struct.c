#include <stdio.h>

int main(void)
{
    struct hours_info
    {
        int hours;
        int minutes;
        int seconds;
    };

    struct hours_info test[5] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}, {13, 14, 15}};

    for (int i = 0; i < 5; i++)
    {
        printf("{%i}:{%i}:{%i}", test[i].hours, test[i].minutes, test[i].seconds);
    }

    return 0;
}