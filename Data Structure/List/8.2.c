#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
    struct node *prev;
} NODE;

typedef struct queue
{
    struct node *start;
    struct node *end;
} QUEUE;

QUEUE *startQueue()
{
    QUEUE *hook = malloc(sizeof(QUEUE));
    hook->end = NULL;
    hook->start = NULL;
    return hook;
}

void appendQueue(QUEUE *q, int value)
{
    NODE *new = malloc(sizeof(NODE));
    new->value = value;
    new->next = NULL;
    new->prev = q->end;

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
}

void removeQueue(QUEUE *q)
{
    if (q->start == NULL)
    {
        printf("Fila vazia\n");
        return;
    }
    NODE *removed = q->start;
    q->start = removed->next;
    if (q->start == NULL)
    {
        q->end = NULL;
    }
    else
    {
        q->start->prev = NULL;
    }
    free(removed);
}

void printQueue(QUEUE *q)
{
    NODE *current = q->start;
    while (current != NULL)
    {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    QUEUE *q1 = startQueue();
    appendQueue(q1, 1);
    appendQueue(q1, 3);
    appendQueue(q1, 1);
    appendQueue(q1, 2);
    appendQueue(q1, 0);

    printQueue(q1);

    removeQueue(q1);

    removeQueue(q1);

    printQueue(q1);
    return 0;
}