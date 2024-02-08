#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node
{
    char consonant;
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

void appendChar(STACK *s, char c)
{

    NODE *new = malloc(sizeof(NODE));
    new->consonant = c;
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

char popChar(STACK *s)
{
    NODE *garbage = s->top;
    char character = ' ';
    if (s->top != NULL)
    {

        character = s->top->consonant;
        s->top = s->top->next;
    }
    free(garbage);
    s->size--;
    return character;
}

int vowel(char c)
{

    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
    {
        return 1;
    }
    return 0;
}

int main()
{
    char c[100];
    int j = 0;
    STACK *charStack = startStack();

    printf("Enter an expression to be encrypted: ");
    fgets(c, 100, stdin);
    printf("Encrypted expression: ");
    while (c[j] != '\0')
    {

        if (isalpha(c[j]) && !(vowel(c[j])))
        {
            appendChar(charStack, c[j]);
        }
        else
        {

            while (charStack->size != 0)
            {
                printf("%c", popChar(charStack));
            }
            printf("%c", c[j]);
        }
        j++;
    }
    return 0;
}