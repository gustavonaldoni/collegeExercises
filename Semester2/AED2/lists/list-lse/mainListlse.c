#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "listlse.h"

main()
{
    int userNumber = 0;
    int removed;
    ListLSE listLSE;

    ListLSECreate(&listLSE);

    while(userNumber != 666)
    {
        printf("Write a number: \n");
        scanf("%d", &userNumber);

        if (userNumber != 666)
            ListLSEInsertEnd(&listLSE, userNumber);
        
    }

    printf("\n========================\n");
    ListLSEShow(listLSE);
    printf("\n Number of elements: %d", ListLSECountElements(listLSE));
    printf("\n Size (in bytes): %d", ListLSESizeOf(listLSE));

    printf("\nWrite a number to remove from the list: \n");
    scanf("%d", &userNumber);

    removed = ListLSERemove(&listLSE, userNumber);

    printf("\nRemoved number: %d\n\n", removed);
    ListLSEShow(listLSE);
}