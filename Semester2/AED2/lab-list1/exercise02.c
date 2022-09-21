/*

Written by: Gustavo Azevedo Naldoni e André Luís Zappa
09/21/2022

QUESTION:

Escreva um programa na linguagem C que contenha duas variáveis inteiras. 
Compare seus endereços e exiba o maior endereço.

*/

#include <stdio.h>

int main()
{
    int x, y;

    //printf("%d e %d", &x, &y);

    if (&x >= &y)
        printf("%p", &x);

    else if (&x < &y)
        printf("%p", &y);

    return 0;
}