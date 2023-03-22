// Após a execução do código, o valor de X foi alterado. O valor de X é copiado para a variável apontada por *p na linha 6, e em seguida, na linha 7, o valor de X é atribuído a *p. Na linha 11, o valor de *k é atribuído a p, e na linha 12, o valor de X é atribuído a a. Portanto, o valor final de X é o mesmo que o valor final de a, que é o valor original de *p, que é 1. O valor de *p, X, a e k pertencem a variáveis inteiras (int). O valor de *p se refere ao valor armazenado no endereço de memória apontado por p, que neste caso é o valor de X.

#include <stdio.h>

int main()
{

    int x = 1;
    printf("%i\n", x);
    int *p = &x;
    printf("%p\n", p);
    *p = x;
    printf("%p\n", p);
    int a = (*p);
    printf("%i\n", a);
    int *k = &a;
    printf("%p\n", k);



    x = a;
    printf("%i\n", x);
    p = k;
    printf("%p\n", p);
    a = x;
    printf("%i\n", a);
    return 0;
}