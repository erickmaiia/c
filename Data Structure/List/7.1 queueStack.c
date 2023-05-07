#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
} NODE;

typedef struct stack
{
    NODE *top;
    int size;
    struct stack *next;
} STACK;

typedef struct queue
{
    STACK *start;
    STACK *end;
    int size;
} QUEUE;

STACK *startStack()
{
    STACK *hook = malloc(sizeof(STACK));
    hook->top = NULL;
    hook->size = 0;
    return hook;
}

QUEUE *startQueue()
{
    QUEUE *hook = malloc(sizeof(QUEUE));
    hook->start = NULL;
    hook->end = NULL;
    hook->size = 0;
    return hook;
}

void appendQueue(STACK *s, QUEUE *q)
{
    if (q->start == NULL)
    {
        q->start = s;
        q->end = s;
        s->next = NULL;
    }
    else
    {
        q->end->next = s;
        q->end = s;
        s->next = NULL;
    }
    q->size++;
}

void appendStack(int value, STACK *s)
{

    NODE *new = malloc(sizeof(NODE));
    new->value = value;
    new->next = NULL;

    if (s->top == NULL)
    {
        s->top = new;
    }
    else
    {
        new->next = s->top;
        s->top = new;
    }
    s->size++;
}

void printStack(STACK *s)
{

    NODE *hook = s->top;
    printf("Stack: %p\n", s);
    printf("\n");

    while (hook != NULL)
    {
        printf("Value: %d\n", hook->value);
        hook = hook->next;
    }
    if (s->size == 0)
    {
        printf("Empty stack!\n");
    }
    printf("--------------------\n");
}

void printQueue(QUEUE *q)
{

    STACK *hook = q->start;
    printf("Queue: %p\n", q);
    printf("\n");

    while (hook != NULL)
    {
        printStack(hook);
        hook = hook->next;
    }
    if (q->size == 0)
    {
        printf("Empty queue!\n");
    }
    printf("--------------------\n");
}

void popStack(STACK *s)
{

    if (s->size > 0)
    {
        NODE *garbage = s->top;
        s->top = s->top->next;
        free(garbage);
        s->size--;
    }
}

void popQueue(QUEUE *q)
{

    if (q->size > 0)
    {

        STACK *garbage = q->start;
        q->start = q->start->next;
        free(garbage);
        q->size--;
    }
}
int main()
{

    // creates a stack s1 and a stack s2, as well as a queue q1 and a queue q2.

    STACK *s1 = startStack();
    STACK *s2 = startStack();
    QUEUE *q1 = startQueue();
    QUEUE *q2 = startQueue();

    appendStack(0, s1); // Appends the value to the first stack.
    appendStack(1, s1); // Appends the value to the first stack.
    appendStack(1, s2); // Appends the value to the second stack.
    appendStack(2, s2); // Appends the value to the second stack.

    // prints the contents of two stacks.

    printStack(s1);
    printStack(s2);

    // appends s1 and s2 to q1 and q2.
    appendQueue(s1, q1);
    appendQueue(s2, q2);

    // prints the contents of two queues.

    printQueue(q1);
    printQueue(q2);

    // pops the top of s1 and s2.

    popStack(s1);
    popStack(s2);

    // prints the contents of two stacks after deleted.

    printStack(s1);
    printStack(s2);

    // pops the top of q1 and q2.

    popQueue(q1);
    popQueue(q2);

    // prints the contents of two queues after deleted.

    printQueue(q1);
    printQueue(q2);

    return 0;
}
