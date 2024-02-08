#include <stdio.h>

struct hours_info
{
    int hours;
    int minutes;
    int seconds;
};

int main(void)
{
    struct hours_info test(struct hours_info x);

    struct hours_info now;

    now.hours = 14;
    now.minutes = 44;
    now.seconds = 30;

    struct hours_info nowTest;

    nowTest = test(now);

    printf("%i:%i:%i\n", nowTest.hours, nowTest.minutes, nowTest.seconds);

    return 0;
}

struct hours_info test(struct hours_info x)
{
    printf("%i:%i:%i\n", x.hours, x.minutes, x.seconds);
    x.hours = 100;
    x.minutes = 100;
    x.seconds = 100;

    return x;
};
