// Este código define uma estrutura denominada Aviso_Covid, que possui dois campos: coronaASolta, que é do tipo inteiro, e fiqueEmCasa, que é um ponteiro para uma estrutura do mesmo tipo. Em seguida, o programa define a variável main(), que inicialmente declara dois ponteiros para a estrutura Aviso_Covid: laveAsMaos e useAlcool. O programa aloca memória suficiente para alocar uma estrutura Aviso_Covid para cada ponteiro usando malloc(). Em seguida, o campo coronaASolta da variável laveAsMaos é definido como 19 e o campo fiqueEmCasa é definido como apontando para a variável useAlcool. Por fim, o campo coronaASolta da variável useAlcool é definido como 100 e o campo fiqueEmCasa é definido como NULL. Por fim, o printf() imprime a string "Cuidado com COVID-19 Fique 100 porcento dentro de casa lendo o livro de ED", com os valores dos campos coronaASolta das variáveis laveAsMaos e useAlcool inseridos nos locais apropriados. Portanto, a frase que sairá no printf do código será: "Cuidado com COVID-19 Fique 100 porcento dentro de casa lendo o livro de ED".

//Entendimento de fluxo

#include <stdio.h>
#include <stdlib.h>

typedef struct Aviso_Covid
{
    int coronaASolta;
    struct Aviso_Covid *fiqueEmCasa;
} Corona;

int main(void)
{

    Corona *laveAsMaos, *useAlcool;

    laveAsMaos = malloc(sizeof(Corona));
    useAlcool = malloc(sizeof(Corona));

    printf("\nlaveAsMaos->coronaASolta: %p | useAlcool->coronaASolta: %p\n", &laveAsMaos->coronaASolta, &useAlcool->coronaASolta);

    laveAsMaos->coronaASolta = 19;

    printf("laveAsMaos->coronaASolta: %i\n", laveAsMaos->coronaASolta);

    laveAsMaos->fiqueEmCasa = useAlcool; // Irrelevante

    useAlcool->coronaASolta = 100;
    useAlcool->fiqueEmCasa = NULL;

    printf("useAlcool->coronaASolta: %p\n", &useAlcool->coronaASolta);

    printf("Cuidado com COVID-%d Fique %d porcento dentro de casa lendo o livro de ED", laveAsMaos->coronaASolta, useAlcool->coronaASolta);

    return 0;
}
