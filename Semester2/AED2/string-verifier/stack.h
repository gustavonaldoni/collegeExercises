struct Node
{
    char text[256];
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
void StackPop(Stack *);
char* StackTop(Stack);
void StackRemove(Stack *);

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

    if(!StackIsEmpty(stack))
    {
        while (aux != NULL)
        {
            printf("Palavra: %s\n", aux->text);
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

void StackPop(Stack *stack)
{
    struct Node *aux;

    while(stack->top != NULL)
    {
    aux = stack->top;
    stack->top = aux->next; 

    strcpy(aux->text, " ");
    aux->next = NULL;

    free(aux);
    }
}

char* StackTop(Stack stack)
{
    if (StackIsEmpty(stack))
        return NULL;

    return stack.top->text;
}