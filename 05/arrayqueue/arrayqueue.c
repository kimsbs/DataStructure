#include "arrayqueue.h"

ArrayQueue* createArrayQueue(int maxElementCount)
{
    ArrayQueue *queue;

    queue = (ArrayQueue *)malloc(sizeof(ArrayQueue));
    if(!queue)
        return (FALSE);
    queue->maxElementCount = maxElementCount;
    queue->currentElementCount = 0;
    queue->front = 0;
    queue->rear = 0;
    queue->pElement = (ArrayQueueNode *)malloc(sizeof(ArrayQueueNode) * maxElementCount);
    if(!queue->pElement)
        return (FALSE);
    return(queue);
}

int enqueueAQ(ArrayQueue* pQueue, ArrayQueueNode element)
{
    int rear = pQueue->rear;

    if(!pQueue || isArrayQueueFull(pQueue))
        return (FALSE);
    pQueue->pElement[rear] = element;
    pQueue->rear = (rear + 1) % pQueue->maxElementCount;
    pQueue->currentElementCount++;
    return (TRUE);
}

ArrayQueueNode *dequeueAQ(ArrayQueue* pQueue)
{
    ArrayQueueNode* node;
    int front = pQueue->front;

    if(!pQueue || isArrayQueueEmpty(pQueue))
        return (FALSE);
    node = &pQueue->pElement[front];
    pQueue->pElement[front].data = '\0';
    pQueue->front = (front + 1) % pQueue->maxElementCount;
    pQueue->currentElementCount--;
    return (node);
}

ArrayQueueNode *peekAQ(ArrayQueue* pQueue)
{
    ArrayQueueNode *node;
    int front = pQueue->front;

    if(!pQueue || isArrayQueueEmpty(pQueue))
        return (FALSE);
    node = &pQueue->pElement[front];
    return (node);
}

void deleteArrayQueue(ArrayQueue* pQueue)
{
    if(!pQueue)
        return ;
    free(pQueue->pElement);
    free(pQueue);
}

int isArrayQueueFull(ArrayQueue* pQueue)
{
    if (pQueue->currentElementCount == pQueue->maxElementCount)
        return(TRUE);
    return(FALSE);
}

int isArrayQueueEmpty(ArrayQueue* pQueue)
{
    if (pQueue->currentElementCount == 0)
        return(TRUE);
    return(FALSE);
}

void displayArrayQueue(ArrayQueue *pQueue)
{
    if (!pQueue)
        return;
    printf("Queue max size : %d\n", pQueue->maxElementCount);
    printf("Queue size : %d\n", pQueue->currentElementCount);
    for (int i = pQueue->front; i < pQueue->front + pQueue->currentElementCount; i++)
    {
        printf("{index: %d, data: %c}\n", i - pQueue->front, pQueue->pElement[i % pQueue->maxElementCount].data);
    }
}

void loop()
{
    ArrayQueue *pQueue;
    ArrayQueueNode *deQueue;
    ArrayQueueNode node0;

    int number;
    pQueue = createArrayQueue(10);
    while (1)
    {
        printf("1 : Enqueue\n2 : Dequeue\n3 : Peek\n4 : Display\n5 : Delete\n");
        scanf(" %d", &number);
        switch (number)
        {
        case 1:
            printf("data : ");
            getchar();
            scanf("%c", &node0.data);
            enqueueAQ(pQueue, node0);
            displayArrayQueue(pQueue);
            break;
        case 2:
            deQueue = dequeueAQ(pQueue);
            printf("%c has dequeue!\n", deQueue->data);
            displayArrayQueue(pQueue);
            break;
        case 3:
            deQueue = peekAQ(pQueue);
            printf("tada %c!\n", deQueue->data);
            break;
        case 4:
            displayArrayQueue(pQueue);
            break;
        case 5:
            deleteArrayQueue(pQueue);
            return ;
        default:
            break;
        }
    }
    return ;
}

int main(void)
{
    loop();
    system("leaks a");
}