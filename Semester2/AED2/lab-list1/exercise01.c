/*

Written by: Gustavo Azevedo Naldoni e André Luís Zappa
09/21/2022

QUESTION:

Escreva um programa na linguagem C para declarar um inteiro, um real e um char, e ponteiros
para inteiro, real, e char. Associe as variáveis aos ponteiros (use &).
Modifique os valores de cada variável utilizando os ponteiros.
No terminal de texto, apresente os valores das variáveis antes e após a modificação.

*/

#include <stdio.h>

main()
{
    int x = 10;
    float y = 3.14;
    char s = 'Z';

    int *px;
    float *py;
    char *ps;

    px = &x;
    py = &y;
    ps = &s;

    printf("%d, %f, %c\n", x, y, s);

    *px = 20;
    *py = 6.98;
    *ps = 'S';

    printf("%d, %f, %c\n", x, y, s);
}