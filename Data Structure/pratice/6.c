#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    int value;
    int id;
    struct node *next;
} NODE;

typedef struct idstack
{
    int size;
    NODE *start;
} IDSTACK;

IDSTACK *startStack()
{
    IDSTACK *hook = malloc(sizeof(IDSTACK));
    hook->start = NULL;
    hook->size = 0;
    return hook;
}

NODE *startNode(int value, int keyC)
{
    NODE *hook = malloc(sizeof(NODE));
    hook->value = value;
    hook->id = keyC;
    hook->next = NULL;
    return hook;
}

void appendID(IDSTACK *hook, int value, int key)
{
    NODE *new = startNode(value, key);
    new->next = hook->start;
    hook->start = new;
    hook->size++;
}

int popId(IDSTACK *idS)
{
    int value = -1;
    NODE *garbage = idS->start;

    if (idS->start != NULL)
    {

        value = idS->start->value;
        idS->start = idS->start->next;
    }

    free(garbage);
    idS->size--;
    return value;
}

void printStk(IDSTACK *idS)
{
    NODE *hook = idS->start;

    printf("\nTop-> ");
    while (hook != NULL)
    {

        printf("{id: %d Value: %d};", hook->id, hook->value);
        hook = hook->next;
    }
    printf("<- Base <=> Size: %d\n", idS->size);
}

int main()
{

    IDSTACK *stackMain = startStack();
    IDSTACK *stackHook = startStack();
    int n, rmCall;
    int count = 0;

    printf("Enter how many calls will be made: ");
    scanf("%d", &n);

    printf("Type the value and its key:\n");

    do
    {
        int valueUser, keyUser;
        scanf("%d", &valueUser);
        scanf("%d", &keyUser);

        appendID(stackMain, valueUser, keyUser);
        count++;
    } while (count < n);

    printf("\nSTACK STATUS:");
    printStk(stackMain);

    printf("\nEnter how many elements you want to remove: ");
    scanf("%d", &rmCall);
    count = 0;

    if (rmCall > n)
    {
        printf("\nThis operation is not possible\n");
    }
    else
    {

        printf("\nELEMENT REMOVAL\nEnter key for removal: ");

        while (count < rmCall)
        {

            int keyRemove;
            scanf("%d", &keyRemove);

            while (stackMain->size != 0 && stackMain->start->id != keyRemove)
            {

                appendID(stackHook, stackMain->start->value, stackMain->start->id);
                popId(stackMain);
            }
            printf("\nKey removed successfully: %d | Value: %d\n", keyRemove, popId(stackMain));

            while (stackHook->start != NULL)
            {

                appendID(stackMain, stackHook->start->value, stackHook->start->id);
                popId(stackHook);
            }

            printf("\nSTACK STATUS:");
            printStk(stackMain);
            count++;
        }
    }

    return 0;
}