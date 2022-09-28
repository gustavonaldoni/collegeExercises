#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "listlde.h"

main()
{
    int userNumber = 0;
    int removed;
    ListLDE listLDE;

    ListLDECreate(&listLDE);

    while(userNumber != 666)
    {
        printf("Write a number: \n");
        scanf("%d", &userNumber);

        if (userNumber != 666)
            ListLDEInsertEnd(&listLDE, userNumber);
        
    }

    printf("\n========================\n");
    ListLDEShow(listLDE);
    printf("\n Number of elements: %d", ListLDECountElements(listLDE));
    printf("\n Size (in bytes): %d", ListLDESizeOf(listLDE));

    printf("\nWrite a number to remove from the list: \n");
    scanf("%d", &userNumber);

    removed = ListLDERemove(&listLDE, userNumber);

    printf("\nRemoved number: %d\n\n", removed);
    ListLDEShow(listLDE);
}