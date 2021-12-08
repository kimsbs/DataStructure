#ifndef _LINKED_QUEUE_
#define _LINKED_QUEUE_

#include <stdio.h>
#include <stdlib.h>
#include "simdef.h"

typedef struct DequeNodeType
{
	SimCustomer customer;
	struct DequeNodeType* pRLink;
} QueueNode;

typedef struct LinkedDequeType
{
	QueueNode* pFrontNode;		// Front ????? ??????
	QueueNode* pRearNode;		// Rear ????? ??????
} LinkedQueue;

LinkedQueue*	createLinkedQueue();
int				insert(LinkedQueue* pDeque, QueueNode element);
QueueNode*		deletefront(LinkedQueue* pDeque);
QueueNode*		peek(LinkedQueue* pDeque);
void			deleteLinkedqueue(LinkedQueue* pDeque);
int				isLinkedqueueEmpty(LinkedQueue* pDeque);

#endif

#ifndef _COMMON_QUEUE_DEF_
#define _COMMON_QUEUE_DEF_

#define TRUE		1
#define FALSE		0

#endif