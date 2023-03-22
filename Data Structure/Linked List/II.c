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

float questao2(Knot *hook)
{
    float result = 0;
    while (hook != NULL)
    {
        if (hook->value % 2 == 0 && hook->value >= 0)
        {
            result = result + hook->value;
        }
        hook = hook->next;
    }
    return result * result;
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

int main()
{
    void append(int value, int index);
    void printList();
    float questao2(Knot * hook);

    append(2, 0);
    append(2, 0);

    printList();

    float x = questao2(start);

    printf("%.2f", x);

    return 0;
}