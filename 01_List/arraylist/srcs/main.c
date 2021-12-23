/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:32:02 by sujilee           #+#    #+#             */
/*   Updated: 2021/11/22 19:55:43 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arraylist.h"
#include <stdio.h>

int main()
{
	ArrayList *myArray;
	ArrayListNode *curr;
	ArrayListNode node0 = {0};
	int len = 0;
	int position = 0;
	int max;
	char c;
	printf("input maxsize: ");
	scanf("%d", &max);
	myArray = createArrayList(max);
	while(1)
	{
		printf("put Add Remove Get Print Length Clear Delete: ");
		scanf(" %c", &c);
		switch (c)
		{
		case 'A':
			printf("data, position: ");
			scanf("%d %d", &(node0.data), &position);
			addALElement(myArray, position, node0);
			break;
		case 'R':
			printf("position: ");
			scanf("%d", &position);
			removeALElement(myArray, position);
			break;
		case 'G':
			printf("position: ");
			scanf("%d", &position);
			curr = getALElement(myArray, position);
			if(curr)
				printf("%d\n", curr->data);
			break;
		case 'P':
			displayArrayList(myArray);
			break;
		case 'L':
			len = getArrayListLength(myArray);
			printf("%d\n", len);
		case 'C':
			clearArrayList(myArray);
			break;
		case 'D':
			deleteArrayList(myArray);
			break;
		default:
			break;
		}
	}
	if(myArray)
		deleteArrayList(myArray);
	return (0);
}