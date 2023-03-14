#include <stdio.h>

int main(void)
{
    struct hours
    {
        int hours;
        int minutes;
        int seconds;
    };

    struct hours now, *after;
    after = &now;

    after->hours = 20;
    after->minutes = 20;
    after->seconds = 20;

    printf("hours: %i minutes: %i seconds: %i\n", now.hours, now.minutes, now.seconds);

    return 0;
}