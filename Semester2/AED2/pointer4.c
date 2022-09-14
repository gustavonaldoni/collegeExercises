#include <stdio.h>
#include <stdlib.h>

main()
{
    int *p;

    for (int i = 0; i < 1000; i++)
    {
        p = (int *) malloc(sizeof(int *));
        printf("Allocated address: %p\n", p);
        free(p);
    }
}