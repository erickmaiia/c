#include <stdio.h>

int main(void)
{
    int x[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    printFunc(x);
    return 0;
}

void printFunc(int matrix[][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%i ", matrix[i][j]);
        }
        printf("\n");
    }
}