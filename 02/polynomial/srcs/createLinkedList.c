/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createLinkedList.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:58:53 by sujilee           #+#    #+#             */
/*   Updated: 2021/11/22 16:25:33 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "polylist.h"

LinkedList *createLinkedList()
{
	//��ũ�� ����Ʈ�� �Ӹ� ����
	LinkedList *headPointer;
	
	//�޸� �Ҵ�
	headPointer = (LinkedList*)malloc(sizeof(LinkedList));
	//���� ��� ���� 0�� (��� ����)
	headPointer->currentElementCount = 0;
	//������ ListNode�� data�� �ʱ�ȭ
	headPointer->headerNode.coef = 0;
	headPointer->headerNode.degree = 0;
	//������ ListNode�� pLink�� �ʱ�ȭ
	headPointer->headerNode.pLink = 0;
	
	return (headPointer);
}