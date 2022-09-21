/*

Written by: Gustavo Azevedo Naldoni e André Luís Zappa
09/21/2022

QUESTION:

Crie uma função capaz de realizar multiplicação matricial da forma C = AB. A função deve receber 6
argumentos: os ponteiros para as matrizes A, B e C, o número de linhas e colunas de A e o número de
colunas de B (assuma que o número de colunas de A é igual ao número de linhas de B). O resultado
da multiplicação deve ficar armazenado em C. Crie um programa para testar sua implementação,
capaz de utilizar a função de multiplicação e apresentar as três matrizes. A função elaborada para
multiplicação não deve realizar nenhum tipo de saída de dados no terminal de texto.


*/

#include <stdio.h>

//void MatrixMult(int **, int**, int**, int, int, int);

int main()
{ 
    int mA[2][2] = {{7, 3},
                    {1, 2}};

    int mB[2][2] = {{5, 3},
                    {6, 9}};
                    
    int mC[2][2];

    MatrixMult(mA, mB, mC, 2, 2, 2);
    
    MatrixPrint(mA);
    MatrixPrint(mB);
    MatrixPrint(mC);

    return 0;
}

void MatrixPrint(int m[2][2])
{
    int i, j;

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            if (j == 0)
                printf("%d ", m[i][j]);

            else if (j == 1)
                printf("%d \n", m[i][j]);
        }
    }
}

void MatrixMult(int mA[2][2], int mB[2][2], int mC[2][2], int lA, int cA, int cB)
{
    mC[0][0] = mA[0][0] * mB[0][0] + mA[0][1] * mB[1][0];
    mC[0][1] = mA[0][0] * mB[0][1] + mA[0][1] * mB[1][1];
    mC[1][0] = mA[1][0] * mB[0][0] + mA[1][1] * mB[1][0];
    mC[1][1] = mA[1][0] * mB[0][1] + mA[1][1] * mB[1][1];
}
