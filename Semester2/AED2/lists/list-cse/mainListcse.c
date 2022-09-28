#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "listcse.h"

main()
{
    int userNumber = 0;
    int removed;
    ListCSE listCSE;

    ListCSECreate(&listCSE);

    while(userNumber != 666)
    {
        printf("Write a number: \n");
        scanf("%d", &userNumber);

        if (userNumber != 666)
            ListCSEInsertEnd(&listCSE, userNumber);
        
    }

    printf("\n========================\n");
    ListCSEShow(listCSE);
    printf("\n Number of elements: %d", ListCSECountElements(listCSE));
    printf("\n Size (in bytes): %d", ListCSESizeOf(listCSE));

    printf("\nWrite a number to remove from the list: \n");
    scanf("%d", &userNumber);

    removed = ListCSERemove(&listCSE, userNumber);

    printf("\nRemoved number: %d\n\n", removed);
    ListCSEShow(listCSE);
}