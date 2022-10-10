int SplitWordsAndPushIntoStack(char *, Stack *);

int SplitWordsAndPushIntoStack(char *string, Stack *stack)
{
    int i, k = 0, j, initWord = -1;
    char cop[256]; 

    for(i=0; i < strlen(string); i++)
    {
        if(string[i] == '.' || string[i] == ',' || string[i] == ':' || string[i] == ';' || string[i] == '?' || string[i] == '!')
        string[i] = ' ';
    }

    for (i = 0; i < strlen(string); i++)
    {
        if (string[i] == ' ')
        {    
            while(string[i+1] == ' ')
            {
                i++;
            }     

            strcpy(cop, "");
            for (j = initWord + 1; j < i; j++) 
            {
                cop[k] = string[j]; 
                k++;
            }
            cop[k] = '\0'; 
            k = 0;
            initWord = i;

            StackPush(stack, cop);
        }    
    }

    if(initWord == -1)
    {
        StackPush(stack, string);
    }

}
