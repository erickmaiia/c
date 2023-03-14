#include <stdio.h>

int main(void)
{
    struct hours_info
    {
        int hours;
        int minutes;
        int seconds;
    };

    struct hours_info now;

    now.hours = 14;
    now.minutes = 44;
    now.seconds = 30;

    printf("%i:%i:%i\n", now.hours, now.minutes, now.seconds);

    return 0;
}