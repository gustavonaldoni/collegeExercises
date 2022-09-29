#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "listcde.h"

main()
{
    int userNumber = 0;
    int removed;
    ListCDE listCSE;

    ListCDECreate(&listCSE);

    while(userNumber != 666)
    {
        printf("Write a number: \n");
        scanf("%d", &userNumber);

        if (userNumber != 666)
            ListCDEInsertEnd(&listCSE, userNumber);
        
    }

    printf("\n========================\n");
    ListCDEShow(listCSE);
    printf("\n Number of elements: %d", ListCDECountElements(listCSE));
    printf("\n Size (in bytes): %d", ListCDESizeOf(listCSE));

    printf("\nWrite a number to remove from the list: \n");
    scanf("%d", &userNumber);

    removed = ListCDERemove(&listCSE, userNumber);

    printf("\nRemoved number: %d\n\n", removed);
    ListCDEShow(listCSE);
}