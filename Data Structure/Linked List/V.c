#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
} NODE;

int size = 0;
NODE *start = NULL;

void appendRecursive(int value, NODE *current)
{
    if (start == NULL)
    {
        NODE *new = malloc(sizeof(NODE));
        new->value = value;
        new->next = NULL;
        start = new;
        size++;
    }
    else if (current->next == NULL)
    {
        NODE *new = malloc(sizeof(NODE));
        new->value = value;
        new->next = NULL;
        current->next = new;
        size++;
    }
    else
    {
        appendRecursive(value, current->next);
    }
}

void append(int value)
{
    appendRecursive(value, start);
}

void printList()
{
    NODE *aux = start;
    while (aux != NULL)
    {
        printf("%d ", aux->value);
        aux = aux->next;
    }
    printf("\n");
}

int main(void)
{
    append(1);
    append(2);

    printList();

    append(3);
    append(4);

    printList();

    return 0;
}