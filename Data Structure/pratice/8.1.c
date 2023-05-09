#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int token;
    struct node *next;
} NODE;

typedef struct queue
{
    struct node *start;
    struct node *end;
    int size;
} QUEUE;

NODE *startNode(int token)
{
    NODE *hook = malloc(sizeof(NODE));
    hook->token = token;
    hook->next = NULL;
    return hook;
}

QUEUE *startQueue(void)
{
    QUEUE *hook = malloc(sizeof(QUEUE));
    hook->end = NULL;
    hook->start = NULL;
    hook->size = 0;
    return hook;
}

void appendQueue(QUEUE *q, int value)
{

    NODE *new = startNode(value);

    if (q->start == NULL)
    {

        q->start = new;
        q->end = new;
    }
    else if ((q->start->token) < (new->token))
    {

        new->next = q->start;
        q->start = new;
    }
    else if ((q->end->token) > (new->token))
    {

        q->end->next = new;
        q->end = new;
    }
    else
    {
        NODE *hook = q->start;

        while (hook->next->token > new->token)
        {
            hook = hook->next;
        }

        new->next = hook->next;
        hook->next = new;
    }
    q->size++;
}

int popQueue(QUEUE *q)
{

    if (q->size != 0)
    {

        NODE *garbage = q->start;
        q->start = q->start->next;
        int returnValue = garbage->token;
        free(garbage);
        q->size--;
        return returnValue;
    }
    else
    {
        return -1;
    }
}

void printQueue(QUEUE *q)
{
    NODE *hook = q->start;
    while (hook != NULL)
    {
        printf("%d ", hook->token);
        hook = hook->next;
    }
    printf("\n");
}

int main(void)
{

    QUEUE *q1 = startQueue();

    appendQueue(q1, 5);
    appendQueue(q1, 1);
    appendQueue(q1, 2);
    appendQueue(q1, 1);
    appendQueue(q1, 3);
    appendQueue(q1, 0);

    printQueue(q1);
    popQueue(q1);
    popQueue(q1);

    printQueue(q1);

    return 0;
}