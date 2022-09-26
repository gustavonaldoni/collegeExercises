#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "listlse.h"

main()
{
    int userNumber = 0;
    ListLSE listLSE;

    ListLSECreate(&listLSE);

    while(userNumber != 666)
    {
        printf("Write a number: \n");
        scanf("%d", &userNumber);

        if (userNumber != 666)
            ListLSEInsertEnd(&listLSE, userNumber);
        
    }

    printf("========================\n");
    ListLSEShow(listLSE);
}