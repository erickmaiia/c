#include <stdio.h>
#include <stdlib.h>

int main(void)
{ 
    int *p = (int *) malloc(sizeof(int));

    if (p == NULL)
    {
        printf("No memorry allocation");
    }

    *p = 1000;

    printf("%i", *p);

    return 0;
}