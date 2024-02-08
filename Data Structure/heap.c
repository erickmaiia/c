#include <stdio.h>
#include <stdlib.h>
#define size 10

int heap[size];
int n = 0;

void up(int i)
{
    int j, hook;

    j = i / 2;
    if (j >= 1)
    {
        if (heap[i] > heap[j])
        {
            hook = heap[i];
            heap[i] = heap[j];
            heap[j] = hook;
            up(j);
        }
    }
}

void insert(int value)
{
    if (n < size)
    {
        heap[n + 1] = value;
        n++;
    }
    up(n);
}

void printHeap()
{
    for (int i = 1; i < n; i++)
    {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

void down(int i, int n)
{
    int j, hook;
    j = 2 * i;

    if (j <= n)
    {
        if (j < n)
        {
            if (heap[j + 1] > heap[j])
            {
                j++;
            }
            if (heap[i] < heap[j])
            {
                hook = heap[i];
                heap[i] = heap[j];
                heap[j] = hook;
                down(j, n);
            }
        }
    }
}

void popHeap()
{
    if (n != 0)
    {
        heap[1] = heap[n];
        n = n - 1;
        down(1, n);
    }
}

int main()
{

    insert(0);
    insert(1);
    insert(5);
    insert(1);
    insert(2);
    insert(8);
    insert(13);
    insert(3);

    printHeap();
    popHeap();
    popHeap();
    printHeap();
    return 0;
}
