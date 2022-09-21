/*

Written by: Gustavo Azevedo Naldoni e André Luís Zappa
09/21/2022

QUESTION:

Identifique o que será apresentado no terminal de texto por um programa escrito na linguagem C,
supondo que i ocupa o endereço 4094 na memória.
*/

#include <stdio.h>

int main()
{
    int i = 5, *p;
    p = &i;
    printf("\n Resultados : %x %d %d %d %d \n", p, *p + 2, **&p, 3 * *p, **&p + 4);

    /* Resultados
    1 - Endereço da variável i
    2 - Valor 7
    3 - Valor 5
    4 - Valor 15
    5 - Valor 9
    */

    return 0;
}