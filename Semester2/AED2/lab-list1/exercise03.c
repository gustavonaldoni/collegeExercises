/*

Written by: Gustavo Azevedo Naldoni e André Luís Zappa
09/21/2022

QUESTION:

Escreva um programa na linguagem C que contenha duas variáveis inteiras. Leia essas variáveis a
partir do teclado. Em seguida, compare seus endereços e exiba o conteúdo do maior endereço.

*/


#include <stdio.h>

int main()
{
    int x,y;

    printf("Digite um valor:");
    scanf("%d", &x);

    printf("Digite o segundo valor:");
    scanf("%d", &y);

    if (&x >= &y)
        printf("Maior endereco: %p", &x);

    else if (&x < &y)
        printf("Maior endereco: %p", &y);


    return 0;
}