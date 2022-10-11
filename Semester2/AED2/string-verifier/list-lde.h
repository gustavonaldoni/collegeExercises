struct Node
{
    char text[50];
    struct Node *previous;
    struct Node *next;
};

typedef struct
{
    struct Node *init;
    struct Node *end;
} ListLDE;

void ListLDECreate(ListLDE *);
bool ListLDEIsEmpty(ListLDE);

bool ListLDEInsertEnd(ListLDE *, char *);

char *ListLDEInit(ListLDE);
char *ListLDEEnd(ListLDE);

void ListLDEShow(ListLDE);

int ListLDECountElements(ListLDE);
int ListLDESizeOf(ListLDE);

bool ListLDERemove(ListLDE *, char *);
bool ListLDERemoveAll(ListLDE *);

void ListLDECreate(ListLDE *list)
{
    list->init = NULL;
    list->end = NULL;
}

bool ListLDEIsEmpty(ListLDE list)
{
    return list.init == NULL && list.end == NULL;
}

bool ListLDEInsertEnd(ListLDE *list, char *text)
{
    struct Node *aux;

    aux = (struct Node *)malloc(sizeof(struct Node));

    if (aux == NULL)
        return false;

    strcpy(aux->text, text);

    if (ListLDEIsEmpty(*list))
    {
        list->init = aux;
        list->end = aux;

        aux->previous = NULL;
        aux->next = NULL;

        return true;
    }

    list->end->next = aux;
    aux->previous = list->end;
    aux->next = NULL;
    list->end = aux;

    return true;
}

char *ListLDEInit(ListLDE list)
{
    if (ListLDEIsEmpty(list))
        return NULL;

    return list.init->text;
}

char *ListLDEEnd(ListLDE list)
{
    if (ListLDEIsEmpty(list))
        return NULL;

    return list.end->text;
}

void ListLDEShow(ListLDE list)
{
    struct Node *aux;

    if (ListLDEIsEmpty(list))
        return;

    aux = list.init;

    while (aux != NULL)
    {
        printf("%s ", aux->text);
        aux = aux->next;
    }
}

int ListLDECountElements(ListLDE list)
{
    int counter = 0;
    struct Node *aux;

    if (ListLDEIsEmpty(list))
        return 0;

    aux = list.init;

    while (aux != NULL)
    {
        counter += 1;
        aux = aux->next;
    }

    return counter;
}

int ListLDESizeOf(ListLDE list)
{
    int numberOfElements = ListLDECountElements(list);

    return sizeof(list) + numberOfElements * sizeof(struct Node);
}

bool ListLDERemove(ListLDE *list, char *text)
{
    struct Node *aux, *before, *current;
    int i;
    char temp[50];

    if (ListLDEIsEmpty(*list))
        return false;

    // Remove first element of a unitary list
    if (list->init == list->end && list->init != NULL && strcmp(list->init->text, text) == 0)
    {
        aux = list->init;
        strcpy(temp, aux->text);

        list->init = NULL;
        list->end = NULL;

        free(aux);

        return true;
    }

    // Remove first element of a non unitary list
    if (list->init != list->end && strcmp(list->init->text, text) == 0)
    {
        aux = list->init;
        strcpy(temp, aux->text);

        list->init = list->init->next;

        free(aux);

        return true;
    }

    // Remove from any other position at of the list
    before = list->init;
    current = before->next;

    while (strcmp(list->init->text, text) != 0 && current->next != NULL)
    {
        before = current;
        current = current->next;
    }

    if (current == NULL)
    {
        return false;
    }

    // Got to the last element at the list
    else if (current->next == NULL)
    {
        aux = current;
        strcpy(temp, aux->text);

        before->next = NULL;
        list->end = before;

        free(aux);

        return true;
    }

    else
    {
        aux = current;
        strcpy(temp, aux->text);

        before->next = current->next;
        current->next->previous = before;

        free(aux);

        return true;
    }
}

bool ListLDERemoveAll(ListLDE *list)
{
    struct Node *aux1, *aux2;

    if (ListLDEIsEmpty(*list))
        return false;

    aux1 = list->init;

    while (aux1 != NULL)
    {
        aux2 = aux1;
        aux1 = aux1->next;

        ListLDERemove(list, aux2->text);
    }

    return true;
}