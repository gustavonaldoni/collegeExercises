/*

Written by: Gustavo Azevedo Naldoni e André Luís Zappa
09/21/2022

QUESTION:

<a escrever>

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "stack.h"
#include "utils.h"

main()
{
    char userText[256];

    printf("Escreva uma frase: ");
    gets(userText);
    
    printf("Frase digitada: %s\n", userText);
    printf("Numero de espacos em branco: %d\n", CountWhiteSpaces(userText));
}