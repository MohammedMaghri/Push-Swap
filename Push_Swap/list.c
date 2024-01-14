/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 11:19:23 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/14 15:06:50 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sadd_list(Node *add, int num)
{
	Node	*str;

	str = malloc(sizeof(struct Node));
	while (add->next != NULL)
		add = add->next;
	add->next = str;
	str->array = num;
	str->next = NULL;
}

void	function_made(int *num, Node *list, t_addr *add)
{
	t_parc	made;

	made.index = 0;
	list->array = num[made.index];
	list->next = NULL;
	made.index++ ;
	while (made.index < add->address)
	{
		sadd_list(list, num[made.index]);
		made.index++;
	}
}

int	count_list(Node *list)
{
	t_parc	count;

	count.index = 1;
	while (list->next != NULL)
	{
		list = list->next ;
		count.index++ ;
	}
	return (count.index);
}

void	pb_push(Node **list_a, Node **list_b)
{
	Node	*other ;
	Node	*point ;

	if (*list_a == NULL)
		return ;
	other = (*list_b);
	point = (*list_a)->next;
	(*list_b) = (*list_a);
	(*list_a) = point;
	(*list_b)->next = other;
	putstr("pb\n");
}

void	pa_push(Node **list_a, Node **list_b)
{
	Node	*keep ;
	Node	*flag ;
	Node	*move ;

	if (*list_b == NULL)
		return ;
	keep = (*list_a);
	flag = (*list_b);
	move = (*list_b)->next;
	(*list_b) = move;
	(*list_a) = flag;
	(*list_a)->next = keep;
	putstr("pa\n");
}
