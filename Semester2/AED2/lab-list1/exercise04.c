/*

Written by: Gustavo Azevedo Naldoni e André Luís Zappa
09/21/2022

QUESTION:

Considere o seguinte trecho de programa escrito na linguagem C:
Determine o valor das seguintes expressões:

*/

#include <stdio.h>

int main()
{
    int i = 3, j = 5;
    int *p, *q;
    p = &i;
    q = &j;

    p == &i; // O valor desta expressão é 1
    *p - *q; // O valor desta expressão é -2
    **&p; // O valor desta expressão é i (3)
    *p / (*q) + 7; // O valor desta expressão é 7
}