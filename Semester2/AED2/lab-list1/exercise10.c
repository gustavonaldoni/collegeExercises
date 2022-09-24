/*

Written by: Gustavo Azevedo Naldoni
09/24/2022

QUESTION:

Considerando a declaração int mat[4]; *p; x;,
quais das seguintes expressões são válidas?

*/

int main(void)
{
    int mat[4], *p, x;

    p = mat + 1; // Válido
    p = mat++; // Inválido
    p = ++mat; // Inválido
    x = (*mat)++; // Válido
}