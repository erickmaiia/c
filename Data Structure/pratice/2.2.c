#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
    int value;
    struct queue *next;
} QUEUE;

QUEUE *start = NULL;
QUEUE *end = NULL;
int size = 0;

void append(int value)
{

    QUEUE *new = malloc(sizeof(QUEUE));
    new->value = value;
    new->next = NULL;

    if (start == NULL)
    { // fila esta vazia
        start = new;
        end = new;
    }
    else
    { // end
        end->next = new;
        end = new;
    }
    size++;
}

void printList()
{

    QUEUE *hook = start;
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

int delete()
{

    if (size > 0)
    { // start

        QUEUE *garbage = start;
        int value = start->value;
        start = start->next;
        free(garbage);
        size--;
        return value;
    }
    else
    {
        printf("Empty queue! \n :(");
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
    printList();
    delete ();
    delete ();
    delete ();
    printList();
    return 0;
}
