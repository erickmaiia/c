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
    struct queue *next;
} QUEUE;

typedef struct mainQueue
{
    QUEUE *start;
    QUEUE *end;
    int size;
} MAINQUEUE;

QUEUE *startQueue()
{
    QUEUE *hook = malloc(sizeof(QUEUE));
    hook->start = NULL;
    hook->end = NULL;
    hook->size = 0;
    return hook;
}

MAINQUEUE *startMainQueue()

{
    MAINQUEUE *hook = malloc(sizeof(MAINQUEUE));
    hook->start = NULL;
    hook->end = NULL;
    hook->size = 0;
    return hook;
}

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

void appendMainQueue(QUEUE *q, MAINQUEUE *mq)
{
    if (mq->start == NULL)
    {
        mq->start = q;
        mq->end = q;
    }
    else
    {
        mq->end->next = q;
        mq->end = q;
    }
    mq->size++;
}

void printQueue(QUEUE *q)
{

    NODE *hook = q->start;
    printf("Queue: %p\n", q);
    printf("\n");
    for (int i = 0; i < q->size; i++)
    {
        printf("Value: %d\n", hook->value);
        hook = hook->next;
    }
    if (q->size == 0)
    {
        printf("Empty queue!\n");
    }
    printf("--------------------\n");
}

void printMainQueue(MAINQUEUE *mq)
{

    QUEUE *hook = mq->start;
    printf("MainQueue: %p\n", mq);
    printf("\n");
    for (int i = 0; i < mq->size; i++)
    {
        printQueue(hook);
        hook = hook->next;
    }
    if (mq->size == 0)
    {
        printf("Empty MainQueue!\n");
    }
    printf("--------------------\n");
}



void popQueue(QUEUE *q)
{

    if (q->size > 0)
    {
        NODE *garbage = q->start;
        q->start = q->start->next;
        free(garbage);
        q->size--;
    }
}

void popMainQueue(MAINQUEUE *mq)
{
    if (mq->size > 0)
    {
        QUEUE *garbage = mq->start;
        mq->start = mq->start->next;
        free(garbage);
        mq->size--;
    }
}

int main()
{

    // creates a queue q1 and a queue q2, as well as a MainQueue mq1 and a MainQueue mq2.

    QUEUE *q1 = startQueue();
    QUEUE *q2 = startQueue();
    MAINQUEUE *mq1 = startMainQueue();
    MAINQUEUE *mq2 = startMainQueue();

    appendQueue(0, q1); // Appends the value to the first queue.
    appendQueue(1, q1); // Appends the value to the first queue.
    appendQueue(1, q2); // Appends the value to the second queue.
    appendQueue(2, q2); // Appends the value to the second queue.

    // prints the contents of two queues.

    printQueue(q1);
    printQueue(q2);

    // appends q1 and q2 to mq1 and mq2.
    appendMainQueue(q1, mq1);
    appendMainQueue(q2, mq2);

    // prints the contents of two MainQueues.

    printMainQueue(mq1);
    printMainQueue(mq2);

    // pops the top of q1 and q2.

    popQueue(q1);
    popQueue(q2);

    // prints the contents of two queues after deleted.

    printQueue(q1);
    printQueue(q2);

    // pops the top of mq1 and mq2.

    popMainQueue(mq1);
    popMainQueue(mq2);

    // prints the contents of two MainQueue after deleted.

    printMainQueue(mq1);
    printMainQueue(mq2);

    return 0;
}
