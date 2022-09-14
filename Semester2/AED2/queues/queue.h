struct Node
{
    int data;
    struct Node *next;
};

typedef struct queue
{
    struct Node *init;
    struct Node *end;
} Queue;

void QueueCreate(Queue *);
bool QueueIsEmpty(Queue);
bool QueueInsert(Queue *, int);

void QueueCreate(Queue *queue)
{
    queue->init = NULL;
    queue->end = NULL;
}

bool QueueIsEmpty(Queue queue)
{
    return queue.init == NULL &&
           queue.end == NULL;
}

bool QueueInsert(Queue *queue, int data)
{
    struct Node *aux;

    aux = (struct Node *) malloc(sizeof(struct Node));

    if (aux == NULL)
    {
        return false;
    }

    aux->data = data;
    aux->next = NULL;

    if (QueueIsEmpty(*queue))
    {
        queue->init = aux;
        queue->end = aux;

        return true;
    }

    queue->end->next = aux;
    queue->end = aux;

    return true;
}