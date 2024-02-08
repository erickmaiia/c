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
} STACK;

STACK *startStack()
{
    STACK *hook = malloc(sizeof(STACK));
    hook->top = NULL;
    hook->size = 0;
    return hook;
}

void appendStack(STACK *s, int value)
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

int pop(STACK *s)
{
    NODE *garbage = s->top;
    int value = 0;

    if (s->top != NULL)
    {

        value = s->top->value;
        s->top = s->top->next;
    }

    free(garbage);
    s->size--;
    return value;
}

void printStack(STACK *s)
{
    NODE *hook = s->top;
    printf("\nTop-> ");
    while (hook != NULL)
    {
        printf("%dt ", hook->value);
        hook = hook->next;
    }
    printf("<-Base | Size: %d\n", s->size);
}

int main()
{
    int n, count = 1;
    STACK *STACK_A = startStack();
    STACK *STACK_B = startStack();
    STACK *STACK_C = startStack();

    printf("How many loads to add: ");
    scanf("%d", &n);

    do
    {
        int cargo;
        printf("Add new load to stack: ");
        scanf("%d", &cargo);

        if (cargo == 3 || cargo == 5 || cargo == 7)
        {

            if (STACK_A->top == NULL)
            {
                appendStack(STACK_A, cargo);
            }
            else
            {

                if (STACK_A->top->value == 7)
                {
                    appendStack(STACK_A, cargo);
                }
                else
                {

                    if (cargo == 7)
                    {

                        while (STACK_A->size != 0 && STACK_A->top->value != 7)
                        {

                            if (STACK_A->top->value == 5)
                            {

                                appendStack(STACK_B, STACK_A->top->value);
                                pop(STACK_A);
                            }
                            else
                            {

                                appendStack(STACK_C, STACK_A->top->value);
                                pop(STACK_A);
                            }
                        }
                        appendStack(STACK_A, cargo);
                    }
                    else if (cargo == 5)
                    {

                        while (STACK_A->size != 0 && STACK_A->top->value != 5 && STACK_A->top->value != 7)
                        {

                            appendStack(STACK_C, STACK_A->top->value);
                            pop(STACK_A);
                        }
                        appendStack(STACK_A, cargo);
                    }
                    else
                    {
                        appendStack(STACK_A, cargo);
                    }
                }
            }
        }
        else
        {
            printf("Invalid payload for stacking.\n");
        }

        count++;
    } while (count <= n);

    while (STACK_B->top != NULL)
    {

        if (STACK_A->top->value == 3)
        {

            while (STACK_A->size != 0 && STACK_A->top->value != 7)
            {

                appendStack(STACK_C, STACK_A->top->value);
                pop(STACK_A);
            }
        }
        appendStack(STACK_A, STACK_B->top->value);
        pop(STACK_B);
    }

    while (STACK_C->top != NULL)
    {

        appendStack(STACK_A, STACK_C->top->value);
        pop(STACK_C);
    }

    printf("Stack A:");
    printStack(STACK_A);
    printf("Stack B:");
    printStack(STACK_B);
    printf("Stack C:");
    printStack(STACK_C);

    return 0;
}