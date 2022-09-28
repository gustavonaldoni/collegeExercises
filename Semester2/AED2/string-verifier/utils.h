void CountWhiteSpaces(char *, Stack *);
void CutString(char *, char *, int, int);

void CountWhiteSpaces(char *string, Stack *stack)
{
    int i, k;
    char result[100];

    char cop[strlen(string)];

    for (i = 0; i < strlen(string) + 1; i++)
    {
        if (string[i] != ' ')
        {
            k++;
        }

        else if (string[i] == ' ')
        {
            CutString(string, result, i - k, i);
            StackPush(stack, result);

            k = 0;
        }
    }
}

void CutString(char *string, char *result, int init, int end)
{
    int i, j;
    int resSize = end - init + 1;

    j = 0;
    for (i = 0; i < strlen(string) + 1; i++)
    {
        if (i >= init && i <= end)
        {
            result[j] = string[i];
            j++;
        }

        if (i == end + 1)
        {
            result[j] = '\0';
        }
    }
}
