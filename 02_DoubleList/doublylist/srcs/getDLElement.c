#include <stdlib.h>
#include "doublylist.h"

DoublyListNode* getDLElement(DoublyList* pList, int position)
{
  DoublyListNode *move;
  int cnt = 0;

  //position ����ó��
  if (position < 0 ||
      position >= pList->currentElementCount)
      return (FALSE);
  //��ȸ�� ���
  move = pList->headerNode.pRLink;

  while (cnt < position)
  {
    move = move->pRLink;
    cnt++;
  }

  return (move);
}