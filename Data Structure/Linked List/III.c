#include <stdio.h>
#include <stdlib.h>

typedef struct knot
{
    int value;
    struct knot *next;
} Knot;

int size = 0;
Knot *start = NULL;

void append(int value, int index)
{
    if (index >= 0 && index <= size)
    {
        Knot *new = malloc(sizeof(Knot));
        new->value = value;
        new->next = NULL;

        if (start == NULL)
        {
            start = new;
        }

        else if (index == 0)
        {
            new->next = start;
            start = new;
        }

        else
        {
            Knot *hook = start;
            for (int i = 0; i < index - 1; i++)
            {
                hook = hook->next;
            }
            new->next = hook->next;
            hook->next = new;
        }
        size++;
    }
}

void printList()
{
    Knot *hook = start;
    while (hook != NULL)
    {
        printf("%d ", hook->value);
        hook = hook->next;
    }
    printf("\n");
}

void reverseRecursive(Knot *n)
{
    if (n == NULL)
    {
        return;
    }
    reverseRecursive(n->next);
    printf("%d ", n->value);
}

int main(void)
{
    void append(int value, int index);
    void printList();
    void reverseRecursive(Knot * n);

    append(1, 0);
    append(2, 1);
    append(3, 2);
    append(4, 0);
    printList();
    reverseRecursive(start);
    return 0;
}