#include <stdio.h>

int main(void)
{
    void testVariable(int x);
    void testPointer(int *pX);
    int test = 1;
    int *pTest = &test;

    //testVariable(test);
    testPointer(pTest);

    printf("%i", test);

    return 0;
}

void testVariable(int x)
{
    x++;
}
void testPointer(int *pX)
{
    ++*pX;
}