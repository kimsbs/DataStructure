#include "linkedqueue.h"
#include "simutil.h"

// 고객 도착 큐에 고객 추가.
void insertCutomer(int arrivalTime, int serviceTime, LinkedQueue *pQueue)
{
    QueueNode node;
    
    node.customer.arrivalTime = arrivalTime;
    node.customer.serviceTime = serviceTime;
    node.customer.startTime = 0;
    node.customer.endTime = 0;
    
    insert(pQueue, node);
}

// 고객 도착 처리.
void processArrival(int currentTime, LinkedQueue *pArrivalQueue, LinkedQueue *pWaitQueue)
{
    QueueNode *go_to_wait;

    while (pArrivalQueue->pFrontNode &&
        currentTime >= pArrivalQueue->pFrontNode->customer.arrivalTime)
    {
        pArrivalQueue->pFrontNode->customer.status = arrival;
        go_to_wait = deletefront(pArrivalQueue);
        insert(pWaitQueue, *go_to_wait);
        free(go_to_wait);
    }
}

// 서비스 시작 처리.
QueueNode* processServiceNodeStart(int currentTime, LinkedQueue *pWaitQueue)
{
    QueueNode *service;

    if(!pWaitQueue->pFrontNode)
        return (FALSE);
    
    service = deletefront(pWaitQueue);
    service->customer.startTime = currentTime;
    service->customer.endTime = currentTime + service->customer.serviceTime;
    service->customer.status = start;

    return (service);
}

// 서비스 종료 처리.
QueueNode* processServiceNodeEnd(int currentTime, QueueNode *pServiceNode, int *pServiceUserCount, int *pTotalWaitTime)
{
    SimCustomer user;

    user = pServiceNode->customer;
    if (user.endTime <= currentTime)
    {
        pServiceNode->customer.status = end;
        (*pServiceUserCount)++;
        (*pTotalWaitTime) += user.startTime - user.arrivalTime;
        free(pServiceNode);
        return (FALSE);
    }
    return (pServiceNode);
}

//
void printSimCustomer(int currentTime, SimCustomer customer)
{
    printf("===========================================\n");
    printf("Customer status : "); 
    switch (customer.status)
    {
    case 0:
        printf("arrival\n");
        break;
    case 1:
        printf("start\n");
        break;
    case 2:
        printf("end\n");
        break;
    default:
        break;
    }
    printf("Customer arrivalTime: %d\n", customer.arrivalTime);
    printf("Customer WaitingTime: %d\n", currentTime - customer.arrivalTime);
    printf("===========================================\n");
}

// 대기 열의 상태를 출력.
void printWaitQueueStatus(int currentTime, LinkedQueue *pWaitQueue)
{
    QueueNode *move;
    int       cnt = 0;

    move = pWaitQueue->pFrontNode;
    while(move)
    {
        cnt++;
        move = move->pRLink;
    }
    printf("%d in Time %d is waiting\n", currentTime, cnt);
}

// 최종 시뮬레이션 결과(통계치) 출력.
void printReport(LinkedQueue *pWaitQueue, int serviceUserCount, int totalWaitTime)
{
    double avg = ((double)totalWaitTime / (double)serviceUserCount);

    if(pWaitQueue->pFrontNode)
        printf("WatingQueue is remain!\n");
    else
        printf("No more Customer!\n");
    printf("ServiceUserCount : %d\n", serviceUserCount);
    printf("TotalwaitTime : %d\n", totalWaitTime);
    printf("Average : %.2f", avg);
}

int     main(void)
{
    int usercount = 0;
    int waittime = 0;
    LinkedQueue *pWaintQueue;
    LinkedQueue *pArrivalQueue;
    QueueNode *doing;

    pArrivalQueue = createLinkedQueue();
    pWaintQueue = createLinkedQueue();

    insertCutomer(0, 3, pArrivalQueue);
    //insertCutomer(1, 4, pArrivalQueue);
    insertCutomer(2, 2, pArrivalQueue);
    insertCutomer(4, 1, pArrivalQueue);
    insertCutomer(6, 1, pArrivalQueue);
    insertCutomer(8, 3, pArrivalQueue);
    
    doing = NULL;
    for(int i = 0 ; i <15 ; i++)
    {
        processArrival(i, pArrivalQueue, pWaintQueue);
        if(doing)
            doing = processServiceNodeEnd(i, doing, &usercount, &waittime);
        if(!doing)
            doing = processServiceNodeStart(i, pWaintQueue);
        //printWaitQueueStatus(i, pWaintQueue);
    }
    printReport(pWaintQueue, usercount, waittime);
    if(doing)
        free(doing);
    deleteLinkedqueue(pArrivalQueue);
    deleteLinkedqueue(pWaintQueue);
}