#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
} NODE;

int size = 0;
NODE *start = NULL;

void insert(int value, int index)
{
    if (index >= 0 && index <= size)
    {
        NODE *new = malloc(sizeof(NODE));
        new->value = value;
        new->next = NULL;

        if (start == NULL)
        {
            start = new;
        }

        else if (index == 0)
        {
            new->next = start;
            start = new;
        }

        else
        {
            NODE *hook = start;
            for (int i = 0; i < index - 1; i++)
            {
                hook = hook->next;
            }
            new->next = hook->next;
            hook->next = new;
        }
        size++;
    }
}

float exponential(NODE *hook)
{
    float result = 0;
    while (hook != NULL)
    {
        if (hook->value % 2 == 0 && hook->value >= 0)
        {
            result = result + hook->value;
        }
        hook = hook->next;
    }
    return result * result;
}

void printList()
{
    NODE *hook = start;
    while (hook != NULL)
    {
        printf("%d ", hook->value);
        hook = hook->next;
    }
    printf("\n");
}

int main()
{
    insert(2, 0);
    insert(2, 0);

    printList();

    float x = exponential(start);

    printf("%.2f", x);

    return 0;
}