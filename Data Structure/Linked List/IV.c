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

void removeIndex(int index)
{
    if (index >= 0 && index < size)
    {
        Knot *removeIndex;
        if (index == 0)
        {
            removeIndex = start;
            start = start->next;
        }
        else
        {
            Knot *hook = start;
            for (int i = 0; i < index - 1; i++)
            {
                hook = hook->next;
            }
            removeIndex = hook->next;
            hook->next = removeIndex->next;
        }
        size--;
        free(removeIndex);
    }
}

int main(void)
{
    void append(int value, int index);
    void printList();
    void removeIndex(int index);

    append(1, 0);
    append(2, 1);
    append(3, 2);
    append(4, 3);
    printList();
    removeIndex(0);
    printList();

    return 0;
}