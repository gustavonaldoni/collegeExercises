int CountWhiteSpaces(char *);

int CountWhiteSpaces(char * text)
{
    int i, counter;

    counter = 0;

    for (i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            counter += 1;
        }
    }

    return counter;
}