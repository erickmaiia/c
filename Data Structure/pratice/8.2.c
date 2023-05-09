#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
} NODE;
typedef struct queue
{
    NODE *start;
    NODE *end;
    int size;
} QUEUE;

void appendQueue(int value, QUEUE *q)
{

    NODE *new = malloc(sizeof(NODE));
    new->value = value;
    new->next = NULL;

    if (q->start == NULL)
    {
        q->start = new;
        q->end = new;
    }
    else
    {
        q->end->next = new;
        q->end = new;
    }
    q->size++;
}

void printQueue(QUEUE *q)
{

    NODE *hook = q->start;

    for (int i = 0; i < q->size; i++)
    {
        printf("Value: %d\n", hook->value);
        hook = hook->next;
    }
}

int popQueue(QUEUE *q)
{

    NODE *hook = q->start->next;
    NODE *bigger = q->start;
    int value;
    while (hook->next != NULL)
    {
        if (hook->next->value > bigger->next->value)
        {
            bigger = hook;
        }
        hook = hook->next;
    }
    if (bigger->next->value > q->start->value)
    {

        NODE *garbage = bigger->next;
        value = garbage->value;
        if (bigger->next->value == q->end->value)
        {
            q->end = bigger;
        }
        bigger->next = bigger->next->next;
        free(garbage);
    }
    else
    {
        NODE *garbage = q->start;
        value = q->start->value;
        q->start = q->start->next;
        free(garbage);
    }
    q->size--;
    return value;
}

QUEUE *startQueue(void)
{
    QUEUE *hook = malloc(sizeof(QUEUE));
    hook->end = NULL;
    hook->start = NULL;
    hook->size = 0;
    return hook;
}

int main()
{
    QUEUE *q1 = startQueue();

    appendQueue(0, q1);
    appendQueue(1, q1);
    appendQueue(1, q1);
    appendQueue(2, q1);
    appendQueue(3, q1);

    printQueue(q1);
    printf("Removed value: %d\n", popQueue(q1));
    printQueue(q1);
    return 0;
}
