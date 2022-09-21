/*

Written by: Gustavo Azevedo Naldoni e André Luís Zappa
09/21/2022

QUESTION:

Assumindo que pulo[] é um vetor do tipo int, quais das seguintes expressões
referenciam o valor do terceiro elemento do vetor?

*/

#include <stdio.h>

int main()
{
    int pulo[5] = {0, 1, 2, 3, 4};

    *(pulo + 2); //-> ESSE!
    *(pulo + 4);
    pulo + 4;
    pulo + 2;

    return 0;
}