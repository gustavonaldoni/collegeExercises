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
    struct Node* aux;

    aux = (struct Node*) malloc(sizeof(struct Node));

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
    struct Node* aux;

    if (ListLSEIsEmpty(list))
        return;
    
    aux = list.init;

    while(aux != NULL)
    {
        printf("%d ", aux->data);
        aux = aux->next;
    }
}

int ListLSECountElements(ListLSE list)
{
    int counter = 0;
    struct Node* aux;

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