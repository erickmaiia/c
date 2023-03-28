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

void removeIndex(int index)
{
    if (index >= 0 && index < size)
    {
        NODE *removeIndex;
        if (index == 0)
        {
            removeIndex = start;
            start = start->next;
        }
        else
        {
            NODE *hook = start;
            for (int i = 0; i < index - 1; i++)
            {
                hook = hook->next;
            }
            removeIndex = hook->next;
            hook->next = removeIndex->next;
        }
        size--;
        free(removeIndex);
    }
}

int main(void)
{
    insert(1, 0);
    insert(2, 1);
    insert(3, 2);
    insert(4, 3);
    printList();
    removeIndex(0);
    printList();

    return 0;
}