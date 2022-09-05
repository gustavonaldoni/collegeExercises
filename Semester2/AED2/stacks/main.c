#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "stack.h"

main()
{
    Stack stack;
    int userNumber;

    StackCreate(&stack);

    while (true)
    {
        printf("Write a number: ");
        scanf("%d", &userNumber);

        if (userNumber < 10)
        {
            StackPush(&stack, userNumber);
        }

        else
        {
            break;
        }
            
    } 

    StackShow(stack);
  
}