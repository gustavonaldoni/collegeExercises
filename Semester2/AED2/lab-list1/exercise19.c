/*

Written by: Gustavo Azevedo Naldoni e André Luís Zappa
09/21/2022

QUESTION:

Elabore uma função em linguagem C que escreva em um vetor a soma dos elementos correspondentes
de outros dois vetores (os tamanhos dos vetores devem ser fornecidos pelo usuário). Por exemplo,
se o primeiro vetor contiver os elementos 1, 3, 0 e 􀀀2, e o segundo vetor contiver os elementos 3, 5,
􀀀 3 e 1, o vetor de soma terá valores resultantes iguais a 4, 8, 􀀀 3 e 􀀀 1. A função deve receber 4
argumentos: os nomes dos três vetores e o número de elementos presentes em cada vetor.

*/

#include <stdio.h>
#include <stdlib.h>

void SomaVetor(int*, int*, int*, int);

int main()
{
    int n, i;
    int *v1, *v2, *soma;

    printf("Informe quantos numeros quer gerar para os vetores: ");
    scanf("%d", &n);

    srand(time(NULL));

    v1 = malloc(n * sizeof(int));
    v2 = malloc(n * sizeof(int));
    soma = malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
    {
        v1[i] = (rand() % 101);
        v2[i] = (rand() % 101);
    }

    SomaVetor(v1, v2, soma, n);

    for (i = 0; i < n; i++)
    {
        printf("%d ", soma[i]);
    }

    return 0;
}


void SomaVetor(int v1[], int v2[], int soma[], int tamanho)
{
    int i;

    for (i = 0; i < tamanho; i++)
    {
     soma[i] = v1[i] + v2[i];
    }
    
}