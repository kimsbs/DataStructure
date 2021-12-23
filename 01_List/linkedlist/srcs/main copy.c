/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:52:25 by sujilee           #+#    #+#             */
/*   Updated: 2021/11/22 17:08:19 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

int		main(void)
{
	int len = 0;
	
	LinkedList *temp;
	ListNode *curr;
	ListNode node0 = {0, 0};
	ListNode node1 = {1, 0};
	ListNode node2 = {2, 0};
	ListNode node3 = {3, 0};

	temp = createLinkedList();
	addLLElement(temp, 0, node0);
	addLLElement(temp, 0, node1);
	addLLElement(temp, 0, node2);
	addLLElement(temp, 3, node3);
	removeLLElement(temp, 0);
	removeLLElement(temp, 1);
	//curr = getLLElement(temp, 0);
	
	curr = temp->headerNode.pLink;
	while(curr)
	{
		printf("%d\n", curr->data);
		curr = curr->pLink;
	}

	
	len = getLinkedListLength(temp);
	printf("len : %d\n", len);
	deleteLinkedList(temp);
	system("leaks arraylist");

}