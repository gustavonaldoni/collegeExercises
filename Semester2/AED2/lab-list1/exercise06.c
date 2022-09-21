/*

Written by: Gustavo Azevedo Naldoni e André Luís Zappa
09/21/2022

QUESTION:

Se i e j são variáveis inteiras e p e q ponteiros para o tipo int,
quais das seguintes expressões de atribuição são ilegais?

*/

#include <stdio.h>

int main()
{
    int i, j;
    int *p, *q;
    
    p = i; // Legal
    q = &j; // Legal
    p = &*&i; // Legal
    i = (*&)j; // Ilegal
    i = *&j; // Legal
    i = *&*&j; // Legal
    q = *p; // Legal
    i = (*p)++ + *q; // Ilegal 

    return 0;
}