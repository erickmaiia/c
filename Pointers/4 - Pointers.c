#include <stdio.h>

int main(void)
{
    struct hours
    {
        int *pHours;
        int *pMinutes;
        int *pSeconds;
    };

    struct hours today;

    int hours = 200;
    int minutes = 300;
    int seconds = 400;

    today.pHours = &hours;
    today.pMinutes = &minutes;
    today.pSeconds = &seconds;

    printf("Hours: %i\n Minutes: %i\n Seconds: %i\n", *today.pHours, *today.pMinutes, *today.pSeconds);

    today.pSeconds = 1000;

    printf("Seconds: %i", today.pSeconds);

    return 0;
}