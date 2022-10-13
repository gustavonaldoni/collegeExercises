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

#include "list-lde.h"
#include "utils.h"

int main()
{
    char userText[256], userTextCopy[256];
    char lastCharacter;
    char repetir = 'n';
    int flag = 1;

    ListLDE words;
    ListLDECreate(&words);

    ListLDE wordsTo;
    ListLDECreate(&wordsTo);

    setlocale(LC_ALL, "portuguese");

    do
    {
        printf("\n\nEscreva uma frase: ");
        fgets(userText, 256, stdin);
        strcpy(userTextCopy, userText);

        system("cls");

        lastCharacter = userText[strlen(userText) - 2];

        if (lastCharacter != '.' &&
            lastCharacter != '?' &&
            lastCharacter != '!' &&
            lastCharacter != ';')
        {
            printf("Frase inválida. Coloque um ponto em seu final.\n");
        }

        SplitWordsAndPushIntoList(userText, &words, &wordsTo);
        printf("============================\n");
        printf("Frase original: %s", userTextCopy);
        FormatResultString(userTextCopy, words, wordsTo);
        printf("Frase corrigida: %s", userTextCopy);

        do
        {
            printf("\nDeseja escrever outra frase? (s - Sim) (n - Nao) \n");
            repetir = tolower(getchar());
            getchar();

            system("cls");

            if (repetir == 'n' || repetir == 's')
                flag = 1;
            else
            {
                flag = 0;
                printf("\nEscolha invalida...\n");
            }

        } while (flag != 1);
        ListLDERemoveAll(&words);
    } while (repetir != 'n');

    return 0;
}
