#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct stack
{
    int value;
    struct stack *next;
} STACK;

STACK *start = NULL;
int size = 0;

void append(int value)
{
    STACK *new = malloc(sizeof(STACK));
    new->value = value;
    new->next = NULL;

    if (start == NULL)
    {
        start = new;
    }
    else
    {
        new->next = start;
        start = new;
    }
    size++;
}

int delete()
{

    if (size > 0)
    {

        STACK *garbage = start;
        int value = start->value;
        start = start->next;
        free(garbage);
        size--;
        return value;
    }
    else
    {
        printf("Empty stack! \n :(");
        return -1;
    }

    return 0;
}

int evaluate(char *expression)
{
    int operand1, operand2, result;
    char ch;

    for (int i = 0; expression[i] != '\0'; i++)
    {
        ch = expression[i];
        if (isdigit(ch))
        {
            append(ch - '0');
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            operand2 = delete ();
            operand1 = delete ();
            switch (ch)
            {
            case '+':
                result = operand1 + operand2;
                break;
            case '-':
                result = operand1 - operand2;
                break;
            case '*':
                result = operand1 * operand2;
                break;
            case '/':
                result = operand1 / operand2;
                break;
            }
            append(result);
        }
    }

    return delete ();
}

int main()
{
    char expression[100];
    float result;

    printf("Enter postfix expression: ");
    fgets(expression, 100, stdin);

    result = evaluate(expression);

    printf("Result: %.2f\n", result);

    return 0;
}
