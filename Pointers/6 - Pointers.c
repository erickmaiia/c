#include <stdio.h>

int main(void)
{
    struct list
    {
        int value;
        struct list *next;
    };

    struct list m1, m2, m3;
    struct list *hook = &m1;

    m1.value = 10;
    m2.value = 20;
    m3.value = 30;

    m1.next = &m2;
    m2.next = &m3;
    m3.next = (struct list *)0;

    while (hook != (struct list *)0)
    {
        printf("%i\n", hook->value);
        hook = hook->next;
    }

    return 0;
}