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
} ListCDE;

void ListCDECreate(ListCDE *);
bool ListCDEIsEmpty(ListCDE);

bool ListCDEInsertEnd(ListCDE *, int);

int ListCDEInit(ListCDE);
int ListCDEEnd(ListCDE);

void ListCDEShow(ListCDE);

int ListCDECountElements(ListCDE);
int ListCDESizeOf(ListCDE);

bool ListCDERemove(ListCDE *list, int);

void ListCDECreate(ListCDE *list)
{
    list->init = NULL;
    list->end = NULL;
}

bool ListCDEIsEmpty(ListCDE list)
{
    return list.init == NULL && list.end == NULL;
}

bool ListCDEInsertEnd(ListCDE *list, int data)
{
    struct Node *aux;

    aux = (struct Node *)malloc(sizeof(struct Node));

    if (aux == NULL)
        return false;

    aux->data = data;

    if (ListCDEIsEmpty(*list))
    {
        list->init = aux;
        list->end = aux;

        aux->next = aux;
        aux->previous = aux;

        return true;
    }

    list->end->next = aux;
    aux->next = list->init;
    aux->previous = list->end;

    list->end = aux;

    return true;
}

int ListCDEInit(ListCDE list)
{
    if (ListCDEIsEmpty(list))
        return -1;

    return list.init->data;
}

int ListCDEEnd(ListCDE list)
{
    if (ListCDEIsEmpty(list))
        return -1;

    return list.end->data;
}

void ListCDEShow(ListCDE list)
{
    struct Node *aux;

    if (ListCDEIsEmpty(list))
        return;

    aux = list.init;

    do
    {
        printf("%d ", aux->data);
        aux = aux->next;
    } while (aux != list.init);
}

int ListCDECountElements(ListCDE list)
{
    int counter = 0;
    struct Node *aux;

    if (ListCDEIsEmpty(list))
        return 0;

    aux = list.init;

    do
    {
        counter += 1;
        aux = aux->next;
    } while (aux != list.init);
    
    return counter;
}

int ListCDESizeOf(ListCDE list)
{
    int numberOfElements = ListCDECountElements(list);

    return sizeof(list) + numberOfElements * sizeof(struct Node);
}

bool ListCDERemove(ListCDE *list, int data)
{
    struct Node *aux, *before, *current;
    int i;

    if (ListCDEIsEmpty(*list))
        return false;

    // Remove first element of a unitary list
    if (list->init == list->end && list->init != NULL && list->init->data == data)
    {
        aux = list->init;
        aux->data = 0;

        list->init = NULL;
        list->end = NULL;

        free(aux);

        return true;
    }

    // Remove first element of a non unitary list
    if (list->init != list->end && list->init->data == data)
    {
        aux = list->init;

        list->init = list->init->next;
        list->init->previous = list->end;
        list->end->next = list->init;

        free(aux);

        return true;
    }

    // Remove from end of the list
    if (list->end->data == data)
    {
        aux = list->end;

        list->end->previous->next = list->init;
        list->end = list->end->previous;
        list->init->previous = list->end;

        free(aux);
    }

    // Remove from any other position of the list
    before = list->init;
    current = before->next;

    while (current->data != data && current != list->init)
    {
        before = current;
        current = current->next;
    }

    if (current == list->init)
    {
        return false;
    }

    else
    {
        aux = current;

        before->next = current->next;
        current->next->previous = before;

        free(aux);

        return true;
    } 
}