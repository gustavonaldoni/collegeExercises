struct Node
{
    int data;
    struct Node *next;
};

typedef struct
{
    struct Node *init;
    struct Node *end;
} ListCSE;

void ListCSECreate(ListCSE *);
bool ListCSEIsEmpty(ListCSE);

bool ListCSEInsertEnd(ListCSE *, int);

int ListCSEInit(ListCSE);
int ListCSEEnd(ListCSE);

void ListCSEShow(ListCSE);

int ListCSECountElements(ListCSE);
int ListCSESizeOf(ListCSE);

bool ListCSERemove(ListCSE *list, int);

void ListCSECreate(ListCSE *list)
{
    list->init = NULL;
    list->end = NULL;
}

bool ListCSEIsEmpty(ListCSE list)
{
    return list.init == NULL && list.end == NULL;
}

bool ListCSEInsertEnd(ListCSE *list, int data)
{
    struct Node *aux;

    aux = (struct Node *)malloc(sizeof(struct Node));

    if (aux == NULL)
        return false;

    aux->data = data;

    if (ListCSEIsEmpty(*list))
    {
        list->init = aux;
        list->end = aux;

        aux->next = aux;

        return true;
    }

    list->end->next = aux;
    aux->next = list->init;
    list->end = aux;

    return true;
}

int ListCSEInit(ListCSE list)
{
    if (ListCSEIsEmpty(list))
        return -1;

    return list.init->data;
}

int ListCSEEnd(ListCSE list)
{
    if (ListCSEIsEmpty(list))
        return -1;

    return list.end->data;
}

void ListCSEShow(ListCSE list)
{
    struct Node *aux;

    if (ListCSEIsEmpty(list))
        return;

    aux = list.init;

    do
    {
        printf("%d ", aux->data);
        aux = aux->next;
    } while (aux != list.init);
}

int ListCSECountElements(ListCSE list)
{
    int counter = 0;
    struct Node *aux;

    if (ListCSEIsEmpty(list))
        return 0;

    aux = list.init;

    do
    {
        counter += 1;
        aux = aux->next;
    } while (aux != list.init);

    return counter;
}

int ListCSESizeOf(ListCSE list)
{
    int numberOfElements = ListCSECountElements(list);

    return sizeof(list) + numberOfElements * sizeof(struct Node);
}

bool ListCSERemove(ListCSE *list, int data)
{
    struct Node *aux, *before, *current;
    int i;

    if (ListCSEIsEmpty(*list))
        return -1;

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
        list->end->next = list->init;

        free(aux);

        return true;
    }

    // Remove from any other position at of the list
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

    // Got to the last element at the list
    else if (current->next == list->init)
    {
        aux = current;

        before->next = list->init;
        list->end = before;

        free(aux);

        return true;
    }

    else
    {
        aux = current;

        before->next = current->next;

        free(aux);

        return true;
    }
}