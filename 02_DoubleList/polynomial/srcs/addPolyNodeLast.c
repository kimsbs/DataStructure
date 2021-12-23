#include <stdio.h>
#include <stdlib.h>
#include "polylist.h"

int addPolyNodeLast(LinkedList *pList, float coef, int degree)
{
  
	ListNode *prev = getLLElement(pList, degree);	//노드를 추가할 기준이 될 값 (0 || 추가될 노드 전 노드의 주소)
	ListNode *node; //인자로 들어온 지수와 밑 값을 넣어줄 노드 그릇	

	
	node = (ListNode*)malloc(sizeof(ListNode));
	
  //노드에 인자로 들어온 값 할당
	node->coef = coef;
	node->degree = degree;
	node->pLink = 0;

	//노드가 비어있거나, 인자로 들어온 degree가 최고차항일 경우
	if (prev == 0)
	{
		node->pLink = pList->headerNode.pLink;
		pList->headerNode.pLink = node;
	  pList->currentElementCount++;
	}
  //기존 노드 중 degree와 동일한 지수항이 있을 경우. 노드 개수의 변화도 없음
  else if (prev->degree == degree)
  {
    prev->coef += coef;
    free(node);
  }
	else
	{
		
		node->pLink = prev->pLink;
		prev->pLink = node;
	  pList->currentElementCount++;
	}
	
	
	return (TRUE);
}