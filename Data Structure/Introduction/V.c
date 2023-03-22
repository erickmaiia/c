#include <stdio.h>
#include <stdlib.h>

typedef struct Properties
{
    char *complement;
    char commercialProperty;
    struct Properties *next;
    int number;
} PP;

int main(void)
{
    PP *supermarket1 = malloc(sizeof(PP));
    PP *apartment17 = malloc(sizeof(PP));

    supermarket1->commercialProperty = 'N';
    supermarket1->number = 1;
    supermarket1->complement = "Commercial Property, 521 m^2";
    apartment17->commercialProperty = 'N';
    apartment17->number = 17;
    apartment17->complement = "Building 4 floors, 182 m^2";
    supermarket1->commercialProperty = 'N';

    PP *home342 = malloc(sizeof(PP));

    home342->number = 342;
    home342->next = NULL;

    supermarket1->next = home342;
    apartment17->next = supermarket1;

    supermarket1 = NULL;
    return 0;
}
