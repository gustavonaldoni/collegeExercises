#include <stdio.h>
#include <stdlib.h>

void ordenar(float v[], int tamanho);

int main()
{
    int n, i;
    float *aux;

    printf("Informe quantos numeros quer gerar: ");
    scanf("%d", &n);

    srand(time(NULL));

    aux = malloc(n * sizeof(float));

    for (i = 0; i < n; i++)
    {
        aux[i] = (rand() % 101);
    }

    for (i = 0; i < n; i++)
    {
        printf("\nVetor desordenado: %5.2f", aux[i]);
    }

    ordenar(aux, n);
    printf("\n");

    for (i = 0; i < n; i++)
    {
        printf("\nVetor ordenado: %5.2f ", aux[i]);
    }
}

void ordenar(float vet[], int tam)
{
    int i, j, aux;

    for (i = 0; i < tam - 1; i++)
        for (j = tam - 1; j > i; j--)
        {
            if (vet[j] < vet[j - 1])
            {
                aux = vet[j];
                vet[j] = vet[j - 1];
                vet[j - 1] = aux;
            }
        }
}