/*

Written by: Gustavo Azevedo Naldoni e André Luís Zappa
09/21/2022

QUESTION:

Determine o que será apresentado pelo seguinte programa:
a) compile
b) execute e
c) verifique se foram obtidas as respostas esperadas

*/

#include <stdio.h>

int main(void)
{
    int valor;
    int *p1;
    float temp;
    float *p2;
    char aux;
    char *nome = " Ponteiros ";
    char *p3;
    int idade;
    int vetor[3];
    int *p4;
    int *p5;

    printf(" \n\n ------ . : . ------\ n");

    /* ( a ) */
    valor = 10;
    p1 = &valor;
    *p1 = 20;
    printf("%d\n", valor); // Apareceu 20 (resposta esperada)

    /* ( b ) */
    temp = 26.5;
    p2 = &temp;
    *p2 = 29.0;
    printf(" %.1f \n", temp); // Apareceu 29.0 (resposta esperada)

    /* ( c ) */
    p3 = &nome[0];
    aux = *p3;
    printf("%c\n", aux); // Apareceu espaço em branco (resposta esperada)

    /* ( d ) */
    p3 = &nome[4];
    aux = *p3;
    printf("%c\n", aux); // Apareceu t (resposta esperada)

    /* ( e ) */
    p3 = nome;
    printf("%c\n", *p3); // Apareceu espaço em branco (resposta esperada)

    /* ( f ) */
    p3 = p3 + 4;
    printf("%c\n", *p3); // Apareceu t (resposta esperada)

    /* ( g ) */
    p3--;
    printf("%c\n", *p3); // Apareceu n (resposta esperada)

    /* ( h ) */
    vetor[0] = 31;
    vetor[1] = 45;
    vetor[2] = 27;
    p4 = vetor;
    idade = *p4;
    printf("%d\n", idade); // Apareceu 31 (resposta esperada)

    /* ( i ) */
    p5 = p4 + 1;
    idade = *p5;
    printf("%d\n", idade); // Apareceu 45 (resposta esperada)

    /* ( j ) */
    p4 = p5 + 1;
    idade = *p4;
    printf("%d\n", idade); // Apareceu 27 (resposta esperada)

    /* ( k ) */
    p4 = p4 - 2;
    idade = *p4;
    printf("%d\n", idade); // Apareceu 31 (resposta esperada)

    /* ( l ) */
    p5 = &vetor[2] - 1;
    printf("%d\n", *p5); // Apareceu 45 (resposta esperada)

    /* ( m ) */
    p5++;
    printf("%d\n", *p5); // Apareceu 31 (resposta esperada)
    return (0);
    
}