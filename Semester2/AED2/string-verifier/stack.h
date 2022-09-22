struct Node
{
    char *text;
    struct Node *next;
};

typedef struct
{
    struct Node *top;
} Stack;

void StackCreate(Stack *);
bool StackIsEmpty(Stack);
bool StackPush(Stack *, char*);
void StackShow(Stack);
char StackPop(Stack *);
char StackTop(Stack);

int StackCountElements(Stack);
int StackSizeOf(Stack);

void StackCreate(Stack *stack)
{
    stack->top = NULL;
}

bool StackIsEmpty(Stack stack)
{
    return stack.top == NULL;
}

bool StackPush(Stack *stack, char* text)
{
    struct Node *aux;

    aux = (struct Node *)malloc(sizeof(struct Node));

    if (aux == NULL)
        return false;

    strcpy(aux->text, text);
    aux->next = stack->top;
    stack->top = aux;

    return true;
}

void StackShow(Stack stack)
{
    struct Node *aux;
    aux = stack.top;

    if (StackIsEmpty(stack))
    {
        printf("Stack is empty ...\n");
    }

    else
    {
        while (aux != NULL)
        {
            printf("Data: %s\n", aux->text);
            aux = aux->next;
        }
    }
}

int StackCountElements(Stack stack)
{
    int counter;
    struct Node *aux;

    counter = 0;
    aux = stack.top;

    if (StackIsEmpty(stack))
    {
        return -1;
    }

    else
    {
        while (aux != NULL)
        {
            counter += 1;
            aux = aux->next;
        }
    }

    return counter;
}

int StackSizeOf(Stack stack)
{
    int numberOfElements;
    struct Node aux;

    if (StackIsEmpty(stack))
        return 0;

    numberOfElements = StackCountElements(stack);
    return sizeof(stack) + sizeof(aux) * numberOfElements;
}

char StackPop(Stack *stack)
{
    struct Node *aux;

    if (stack->top == NULL)
        return -1;

    aux = stack->top;
    stack->top = aux->next; 

    aux->text = "";
    aux->next = NULL;

    free(aux);

    return aux->text;

}

char StackTop(Stack stack)
{
    if (StackIsEmpty(stack))
        return -1;

    return stack.top->text;
}