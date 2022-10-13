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
    char repeat;
    char lastCharacter;

    ListLDE words;
    ListLDECreate(&words);

    ListLDE wordsTo;
    ListLDECreate(&wordsTo);

    setlocale(LC_ALL, "portuguese");

    while (true)
    {
        printf("\n\nEscreva uma frase: ");
        fgets(userText, 256, stdin);
        strcpy(userTextCopy, userText);

        lastCharacter = userText[strlen(userText) - 2];

        if (lastCharacter != '.' &&
            lastCharacter != '?' &&
            lastCharacter != '!' &&
            lastCharacter != ';')
        {
            printf("Frase inválida. Coloque um ponto em seu final.\n");
            continue;
        }

        else
        {
            SplitWordsAndPushIntoList(userText, &words, &wordsTo);
            printf("============================\n");
            FormatResultString(userTextCopy, words, wordsTo);
            userTextCopy[0] = toupper(userTextCopy[0]);
            printf("Frase formatada: %s", userTextCopy);
        }

        while (true)
        {
            printf("\nDeseja escrever outra frase? (s - Sim) (n - Nao) \n");
            repeat = tolower(getchar());
            getchar();

            system("cls");

            ListLDERemoveAll(&words);
            ListLDERemoveAll(&wordsTo);

            if (repeat == 'n')
            {
                exit(1);
            }

            else if (repeat == 's')
            {
                break;
            }

            printf("\nEscolha invalida...\n");
        }
    }
}
