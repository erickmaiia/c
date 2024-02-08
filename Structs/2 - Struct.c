#include <stdio.h>

int main(void)
{
    struct hours_info
    {
        int hours;
        int minutes;
        int seconds;
        char character;
    };

    struct hours_info now;

    now.hours = 14;
    now.minutes = 44;
    now.seconds = 30;

    struct hours_info after;

    after.hours = now.hours + 10;
    after.minutes = now.minutes;
    after.seconds = now.seconds;
    after.character = 'a';

    printf("%i:%i:%i , %c", after.hours, after.minutes, after.seconds, after.character);

    return 0;
}