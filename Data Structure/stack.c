#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
} NODE;

NODE *start = NULL; // topo
int size = 0;

void append(int value)
{

    NODE *new = malloc(sizeof(NODE));
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

void printList()
{

    NODE *hook = start;

    for (int i = 0; i < size; i++)
    {
        printf("Value: %d\n", hook->value);
        hook = hook->next;
    }
}

int delete()
{

    if (size > 0)
    {

        NODE *garbage = start;
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

int main()
{
    append(5);
    append(10);
    append(15);
    append(20);
    append(25);
    append(30);
    delete ();
    delete ();
    delete ();
    return 0;
}
