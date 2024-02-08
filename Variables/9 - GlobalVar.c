#include <stdio.h>

int globalVar = 2;

int main(void)
{
    void test(void);
    printf("Global var %i\n", globalVar);
    test();
    test();
    return 0;
}

void test(void)
{
    int automaticLocalVar = 2;
    automaticLocalVar *= 2;

    static int staticLocalVar = 2;
    staticLocalVar *= 2;
    globalVar *= 2;

    printf("Automatic local %i\n", automaticLocalVar);
    printf("Static local %i\n", staticLocalVar);
    printf("Global var %i\n", globalVar);
}