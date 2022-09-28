struct Node
{
    int data;
    struct Node *next;
};

typedef struct
{
    struct Node *init;
    struct Node *end;
} ListLSE;

void ListLSECreate(ListLSE *);
bool ListLSEIsEmpty(ListLSE);

bool ListLSEInsertEnd(ListLSE *, int);

int ListLSEInit(ListLSE);
int ListLSEEnd(ListLSE);

void ListLSEShow(ListLSE);

int ListLSECountElements(ListLSE);
int ListLSESizeOf(ListLSE);

int ListLSERemove(ListLSE *list, int);

void ListLSECreate(ListLSE *list)
{
    list->init = NULL;
    list->end = NULL;
}

bool ListLSEIsEmpty(ListLSE list)
{
    return list.init == NULL && list.end == NULL;
}

bool ListLSEInsertEnd(ListLSE *list, int data)
{
    struct Node *aux;

    aux = (struct Node *)malloc(sizeof(struct Node));

    if (aux == NULL)
        return false;

    aux->data = data;

    if (ListLSEIsEmpty(*list))
    {
        list->init = aux;
        list->end = aux;

        aux->next = NULL;

        return true;
    }

    list->end->next = aux;
    aux->next = NULL;
    list->end = aux;

    return true;
}

int ListLSEInit(ListLSE list)
{
    if (ListLSEIsEmpty(list))
        return -1;

    return list.init->data;
}

int ListLSEEnd(ListLSE list)
{
    if (ListLSEIsEmpty(list))
        return -1;

    return list.end->data;
}

void ListLSEShow(ListLSE list)
{
    struct Node *aux;

    if (ListLSEIsEmpty(list))
        return;

    aux = list.init;

    while (aux != NULL)
    {
        printf("%d ", aux->data);
        aux = aux->next;
    }
}

int ListLSECountElements(ListLSE list)
{
    int counter = 0;
    struct Node *aux;

    if (ListLSEIsEmpty(list))
        return 0;

    aux = list.init;

    while (aux != NULL)
    {
        counter += 1;
        aux = aux->next;
    }

    return counter;
}

int ListLSESizeOf(ListLSE list)
{
    int numberOfElements = ListLSECountElements(list);

    return sizeof(list) + numberOfElements * sizeof(struct Node);
}

int ListLSERemove(ListLSE *list, int data)
{
    struct Node *aux, *before, *current;
    int i, temp;

    if (ListLSEIsEmpty(*list))
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

        free(aux);

        return temp;
    } 
}