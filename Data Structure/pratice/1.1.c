#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int value;
    struct stack *next;
} STACK;

STACK *start = NULL; // topo
int size = 0;

void append(int value)
{

    STACK *new = malloc(sizeof(STACK));
    new->value = value;
    new->next = NULL;

    if (start == NULL)
    {
        start = new;
    }
    else
    {
        new->next = start;
        start = new;
    }
    size++;
}

int delete()
{

    if (size > 0)
    {

        STACK *garbage = start;
        int value = start->value;
        start = start->next;
        free(garbage);
        size--;
        return value;
    }
    else
    {
        printf("Empty stack! \n :(");
        return -1;
    }

    return 0;
}

void printList()
{

    STACK *hook = start;
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf("Value: %d\n", hook->value);
        hook = hook->next;
    }
    printf("\n");
    printf("Size: %d\n", size);
    printf("----------------------\n");
}

int main()
{
    append(5);
    append(10);
    append(15);
    append(20);
    append(25);
    append(30);
    printList();
    delete ();
    delete ();
    delete ();
    printList();
    return 0;
}
