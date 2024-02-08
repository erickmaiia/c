#include <stdio.h>

struct x
{
    int a;
    int b;
    int c;
};

int main(void)
{
    struct x structt;

    printf("%li", sizeof(structt));
    return 0;
}