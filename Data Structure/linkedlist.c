#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int value;
    struct no *next;
} NO;

NO *start = NULL;
int size = 0;

void insert(int index, int value)
{
    // 1 - COMPILADOR! cria espaco na memoria para o no e nao desaloca!!!! Por favor!

    if (index >= 0 && index <= size)
    {
        NO *new = malloc(sizeof(NO));
        // 2 - seto os valores desse no
        new->value = value;
        new->next = NULL;
        // 3 - encaixo esse no na lista
        if (start == NULL)
        { // vazia
            start = new;
            size++;
        }
        else
        {
            if (index == 0)
            { // start
                new->next = start;
                start = new;
                size++;
            }
            else if (index == size)
            { // fim!
                NO *hook = start;

                for (int i = 0; i < size - 1; i++)
                {
                    hook = hook->next; // caminhada
                }

                // operacao de encaixe
                hook->next = new;
                size++;
            }
            else
            { // entre ao inves de meio

                NO *hook = start;

                for (int i = 0; i < index - 1; i++)
                {
                    hook = hook->next; // caminhada
                }
                // operacoes de encaixe! CUvalue A ORDEM IMPORTA!
                new->next = hook->next;
                hook->next = new;
                size++;
            }
        }
    }
}

void printList()
{

    // logica para percorrer a lista imprimindo os dados (altura, peso e value) de cada elemento da lista
    // DICA:
    NO *hook = start;

    for (int i = 0; i < size; i++)
    {
        printf("Value: %d\n", hook->value);
        hook = hook->next; // caminhada
    }
}

int main()
{
    insert(0, 5);
    insert(0, 10);
    insert(0, 15);
    insert(3, 20);
    insert(3, 25);
    insert(2, 30);
    printList();

    return 0;
}
