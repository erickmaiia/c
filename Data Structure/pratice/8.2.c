#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
} NODE;

NODE *start = NULL;
NODE *end = NULL;
int size = 0;

void add(int value)
{

    NODE *new = malloc(sizeof(NODE));
    new->value = value;
    new->next = NULL;

    if (start == NULL)
    {
        start = new;
        end = new;
    }
    else
    {
        end->next = new;
        end = new;
    }
    size++;
}

void imprimir()
{

    NODE *hook = start;

    for (int i = 0; i < size; i++)
    {
        printf("Value: %d\n", hook->value);
        hook = hook->next;
    }
}

int remover()
{

    NODE *hook = start->next;
    NODE *bigger = start;
    int value;
    while (hook->next != NULL)
    {
        if (hook->next->value > bigger->next->value)
        {
            bigger = hook;
        }
        hook = hook->next;
    }
    if (bigger->next->value > start->value)
    {

        NODE *garbage = bigger->next;
        value = garbage->value;
        if (bigger->next->value == end->value)
        {
            end = bigger;
        }
        bigger->next = bigger->next->next;
        free(garbage);
    }
    else
    {
        NODE *garbage = start;
        value = start->value;
        start = start->next;
        free(garbage);
    }
    size--;
    return value;
}

int main()
{
    add(0);
    add(1);
    add(1);
    add(2);
    add(3);
    printf("Removed value: %d\n", remover());
    return 0;
}
