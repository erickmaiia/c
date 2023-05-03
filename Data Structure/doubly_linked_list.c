#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int value;
    struct no *next;
    struct no *prev;
} NO;

NO *start = NULL;
NO *end = NULL;
int size = 0;

void insert(int index, int value)
{

    if (index >= 0 && index <= size)
    {
        // Passo 1 - aloco espaco de memoria e coloco os valuees no NO new
        NO *new = malloc(sizeof(NO));
        new->value = value;
        new->next = NULL;
        new->prev = NULL;
        // Passo 2 - encaixo esse no na lista
        if (start == NULL)
        { // vazia
            start = new;
            end = new;
        }
        else if (index == 0)
        { // start
            new->next = start;
            start->prev = new;
            start = new;
        }
        else if (index == size)
        { // end!
            end->next = new;
            new->prev = end;
            end = new;
        }
        else
        { // entre os elementos da lista ("meio")
            NO *hook = start;
            for (int i = 0; i < index; i++)
            {
                hook = hook->next; // caminhada
            }
            // operacoes de encaixe! CUIDADE A ORDEM IMPORTA!
            new->next = hook;
            hook->prev->next = new;
            hook->prev = new->prev;
            hook->prev = new;
        }
        size++;
    }
}

void printList()
{

    NO *hook = start;

    for (int i = 0; i < size; i++)
    {
        printf("Value: %d\n", hook->value);

        hook = hook->next;
    }
}

int delete(int index)
{

    // DICA e necessario desalocar o no com a funcao free()
    if (index >= 0 && index <= size - 1)
    {
        NO *garbage;
        if (size == 1)
        { // lista so tem um elemento

            // etapa 1: aponto o garbage para no a ser removido
            garbage = start;
            // etapa 2: removo o no da lista (logica)
            start = NULL;
            end = NULL;
        }
        else if (index == 0)
        { // start
            // etapa 1: aponto o garbage para no a ser removido
            garbage = start;
            // etapa 2: removo o no da lista (logica)
            start = start->next;
            start->prev = NULL;
        }
        else if (index == size - 1)
        { // end
            // etapa 1: aponto o garbage para no a ser removido
            garbage = end;
            // etapa 2: removo o no da lista (logica)
            end = end->prev;
            end->next = NULL;
        }
        else
        { // entre os elementos da lista ("meio")
            garbage = start;
            for (int i = 0; i < index; i++)
            {
                garbage = garbage->next; // caminhada
            }

            garbage->prev->next = garbage->next;
            garbage->next->prev = garbage->prev;
        }

        // etapa 3: removo o no da memoria
        int hook = garbage->value;
        free(garbage);
        size--;
        return hook;
    }
    return 0;
}

int main()
{
    insert(0, 5);
    insert(1, 10);
    insert(2, 15);
    insert(3, 20);
    insert(4, 25);
    insert(5, 30);
    printList();
    printf("-------------------\n");
    delete (1);
    delete (2);
    printList();
    return 0;
}
