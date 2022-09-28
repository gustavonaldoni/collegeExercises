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

int ListCSERemove(ListCSE *list, int);

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

int ListCSERemove(ListCSE *list, int data)
{
    struct Node *aux, *before, *current;
    int i, temp;

    if (ListCSEIsEmpty(*list))
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
        list->end->next = list->init;

        free(aux);

        return temp;
    }

    // Remove from any other position at of the list
    before = list->init;
    current = before->next;

    while (current->data != data && current != list->init)
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

        before->next = list->init;
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