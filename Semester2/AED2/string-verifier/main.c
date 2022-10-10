/*

Written by: Gustavo Azevedo Naldoni, André Luís Zappa e André Pinheiro Devecz
09/21/2022

QUESTION:

<a escrever>

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

#include "stack.h"
#include "utils.h"

int main()
{
    char userText[256];
    char repetir = 'n';
    int flag = 1;

    Stack words;
    StackCreate(&words);
    setlocale(LC_ALL,"portuguese");

    do
    {

        printf("\n\nEscreva uma frase: ");
        fgets(userText, 256, stdin);

        if(userText[strlen(userText)-2] != '.')
        {
            printf("\n FIM DA FRASE PRECISA DE UM PONTO FINALl!!!\n");
        }

        else if(strlen(userText) > 1)
        {
            //printf("Frase digitada: %s\n", userText);
            SplitWordsAndPushIntoStack(userText, &words);
            StackShow(words);
        }

        else
        {
            printf("DIGITE UMA FRASE VALIDA!!!\n");
        }

        do
        {
            printf("\n Deseja escrever outra frase? (s - Sim) (n - Nao) \n");
            repetir = tolower(getchar());
            getchar();

            if(repetir == 'n' || repetir == 's')
                flag = 1;
            else
            {
                flag = 0;
                printf("\nEscolha invalida...\n");
            }

        }
        while(flag != 1);

        StackPop(&words);

    }
    while (repetir != 'n');

    return 0;

}