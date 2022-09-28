struct Node
{
    int data;
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

bool ListLDEInsertEnd(ListLDE *, int);

int ListLDEInit(ListLDE);
int ListLDEEnd(ListLDE);

void ListLDEShow(ListLDE);

int ListLDECountElements(ListLDE);
int ListLDESizeOf(ListLDE);

int ListLDERemove(ListLDE *list, int);

void ListLDECreate(ListLDE *list)
{
    list->init = NULL;
    list->end = NULL;
}

bool ListLDEIsEmpty(ListLDE list)
{
    return list.init == NULL && list.end == NULL;
}

bool ListLDEInsertEnd(ListLDE *list, int data)
{
    struct Node *aux;

    aux = (struct Node *)malloc(sizeof(struct Node));

    if (aux == NULL)
        return false;

    aux->data = data;

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

int ListLDEInit(ListLDE list)
{
    if (ListLDEIsEmpty(list))
        return -1;

    return list.init->data;
}

int ListLDEEnd(ListLDE list)
{
    if (ListLDEIsEmpty(list))
        return -1;

    return list.end->data;
}

void ListLDEShow(ListLDE list)
{
    struct Node *aux;

    if (ListLDEIsEmpty(list))
        return;

    aux = list.init;

    while (aux != NULL)
    {
        printf("%d ", aux->data);
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

int ListLDERemove(ListLDE *list, int data)
{
    struct Node *aux, *before, *current;
    int i, temp;

    if (ListLDEIsEmpty(*list))
        return -1;

    // Remove first element of a unitary list
    if (list->init == list->end && list->init != NULL && list->init->data == data)
    {
        aux = list->init;
        temp = aux->data;

        aux->data = 0;

        list->init = NULL;
        list->end = NULL;

        free(aux);

        return temp;
    }

    // Remove first element of a non unitary list
    if (list->init != list->end && list->init->data == data)
    {
        aux = list->init;
        temp = aux->data;

        list->init = list->init->next;

        free(aux);

        return temp;
    }

    // Remove from any other position at of the list
    before = list->init;
    current = before->next;

    while (current->data != data && current->next != NULL)
    {
        before = current;
        current = current->next;
    }

    if (current == NULL)
    {
        return -1;
    }

    // Got to the last element at the list
    else if (current->next == NULL)
    {
        aux = current;
        temp = aux->data;

        before->next = NULL;
        list->end = before;

        free(aux);
        
        return temp;
    }

    else
    {
        aux = current;
        temp = aux->data;

        before->next = current->next;
        current->next->previous = before;

        free(aux);

        return temp;
    } 
}