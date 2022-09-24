/*

Written by: Gustavo Azevedo Naldoni
09/21/2022

QUESTION:

Determine o que será apresentado pelo seguinte programa:
a) compile
b) execute e
c) verifique se foram obtidas as respostas esperadas

*/

int main(void)
{
    float vet[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    float *f;
    int i;

    f = vet;
    printf(" \n contador / valor / valor / endereco / endereco ");
    for (i = 0; i <= 4; i++)
    {
        printf(" \n i = %d", i); // Valor de i (vai de 0 até 4)
        printf(" vet [%d ] = %.1f ", i, vet[i]); // Dado flutuante armanezado na posição i do vetor
        printf(" *( f + %d) = %.1f ", i, *(f + i)); // Dado flutuante armazenado na posição i do vetor
        printf("&vet [%d ] = %x", i, &vet[i]); // Endereço de memória do dado na posição i do vetor
        printf(" ( f + %d) = %x", i, f + i); // Endereço de memória do dado na posição i do vetor
    }
}
