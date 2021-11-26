#include <stdlib.h>
#include "doublylist.h"

int addDLElement(DoublyList* pList, int position, DoublyListNode element)
{
  DoublyListNode *new_node;
  DoublyListNode *next;
  DoublyListNode *prev;

  //����ó��
  if (position < 0 ||
      position > pList->currentElementCount)
      return (FALSE);
  
  //��带 ���� �Ҵ�
  new_node = (DoublyListNode *)malloc(sizeof(DoublyListNode));
  new_node->data = element.data;
  new_node->pLLink = 0;
  new_node->pRLink = 0;

  //����Ʈ�� ����������,
  if  (pList->currentElementCount == 0)
  {
    new_node->pRLink = pList->headerNode.pRLink;
    new_node->pLLink = pList->headerNode.pLLink;
    pList->headerNode.pRLink = new_node;
    pList->headerNode.pLLink = new_node;
  }
  else
  {
    //����Ʈ�� ������� �������, position�� 0�̾ getDLElemet�� �� left�� ���� ��尡�־ ����.
    next = getDLElement(pList, position);
    prev = next->pLLink;
    new_node->pLLink = prev;
    new_node->pRLink = next;
    prev->pRLink = new_node;
    next->pLLink = new_node;
  }
  pList->currentElementCount++;

  return (TRUE);
}