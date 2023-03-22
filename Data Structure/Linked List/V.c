#include <stdio.h>
#include <stdlib.h>

typedef struct knot
{
    int value;
    struct knot *next;
} Knot;

int size = 0;
Knot *start = NULL;

void finalAppendRecursive(int value, Knot *current)
{
    if (start == NULL)
    {
        Knot *new = malloc(sizeof(Knot));
        new->value = value;
        new->next = NULL;
        start = new;
        size++;
    }
    else if (current->next == NULL)
    {
        Knot *new = malloc(sizeof(Knot));
        new->value = value;
        new->next = NULL;
        current->next = new;
        size++;
    }
    else
    {
        finalAppendRecursive(value, current->next);
    }
}

void finalAppend(int value)
{
    void finalAppendRecursive(int value, Knot *current);
    finalAppendRecursive(value, start);
}

void printList()
{
    Knot *aux = start;
    while (aux != NULL)
    {
        printf("%d ", aux->value);
        aux = aux->next;
    }
    printf("\n");
}

int main(void)
{
    void finalAppend(int value);
    void printList();

    finalAppend(1);
    finalAppend(2);

    printList();

    finalAppend(3);
    finalAppend(4);

    printList();

    return 0;
}