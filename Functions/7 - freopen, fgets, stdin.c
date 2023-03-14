#include <stdio.h>

int main(void)
{
    char x[100];
    fgets(x, 10, stdin);
    printf("%s\n", x);

    freopen("test1.txt", "r", stdin);
    fgets(x, 100, stdin);
    printf("%s\n", x);

    FILE *file = fopen("test1.txt", "r");

    fgets(x, 100, stdin);
    printf("%s\n", x);

    freopen("test2.txt", "r", file);

    fgets(x, 100, file);
    printf("%s\n", x);

    return 0;
}