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

typedef struct stack
{
    int size;
    QUEUE *start;
} STACK;

QUEUE *startQueue()
{
    QUEUE *hook = malloc(sizeof(QUEUE));
    hook->start = NULL;
    hook->end = NULL;
    hook->size = 0;
    return hook;
}

STACK *startStack()
{
    STACK *hook = malloc(sizeof(STACK));
    hook->start = NULL;
    hook->size = 0;
    return hook;
}

void appendStack(QUEUE *q, STACK *s)
{
    if (s->start == NULL)
    {
        s->start = q;
    }
    else
    {
        q->next = s->start;
        s->start = q;
    }
    s->size++;
}

void appendQueue(int value, QUEUE *q)
{
    NODE *new = malloc(sizeof(NODE));
    new->value = value;
    new->next = NULL;

    if (q->start == NULL)
    {
        q->start = new;
    }
    else
    {
        new->next = q->start;
        q->start = new;
    }
    q->size++;
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

void printStack(STACK *s)
{

    QUEUE *hook = s->start;
    printf("Stack: %p\n", s);
    printf("\n");
    for (int i = 0; i < s->size; i++)
    {
        printQueue(hook);
        hook = hook->next;
    }
    if (s->size == 0)
    {
        printf("Empty stack!\n");
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

void popStack(STACK *s)
{
    if (s->size > 0)
    {

        QUEUE *garbage = s->start;
        s->start = s->start->next;
        free(garbage);
        s->size--;
    }
}

int main()
{

    // creates a stack s1 and a stack s2, as well as a queue q1 and a queue q2.

    STACK *s1 = startStack();
    STACK *s2 = startStack();
    QUEUE *q1 = startQueue();
    QUEUE *q2 = startQueue();

    appendQueue(0, q1); // Appends the value to the first queue.
    appendQueue(1, q1); // Appends the value to the first queue.
    appendQueue(1, q2); // Appends the value to the second queue.
    appendQueue(2, q2); // Appends the value to the second queue.

    // prints the contents of two queues.

    printQueue(q1);
    printQueue(q2);

    // appends q1 and q2 to s1 and s2.
    appendStack(q1, s1);
    appendStack(q2, s2);

    // prints the contents of two queues.

    printStack(s1);
    printStack(s2);

    // pops the top of q1 and q2.

    popQueue(q1);
    popQueue(q2);

    // prints the contents of two queues after deleted.

    printQueue(q1);
    printQueue(q2);

    // pops the top of s1 and s2.

    popStack(s1);
    popStack(s2);

    // prints the contents of two stacks after deleted.

    printStack(s1);
    printStack(s2);

    return 0;
}
