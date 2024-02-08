#include <stdio.h>

int main(void)
{
    char note[5];

    note[0] = 'A';
    note[1] = 'B';
    note[2] = 'C';
    note[3] = 'D';
    note[4] = 'F';

    printf("%c", note[2]);

    return 0;
}