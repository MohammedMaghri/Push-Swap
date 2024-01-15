/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 11:19:23 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/15 18:17:59 by mmaghri          ###   ########.fr       */
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
	str->index = 0;
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

void at_linked(Node **list)
{
	Node *link ;
	Node *temp;

	link = (*list) ;
	temp = (*list);
	while (link)
	{
		temp = (*list);
		while(temp)
		{
			if (link->array > temp->array)
				link->index++;
			temp= temp->next;
		}
		link = link->next;
	}
}

int check_highest(Node **list)
{
	int flag;
	Node *all;	
	Node *temp;
	int index ;
	int flagturn ;


	if (count_list(*list) != 3)
		return (-1);
	flag = 0;
	index = 0;
	flagturn = 1;
	all = (*list);
	while (all)
	{
		temp = (*list) ;
		while (temp)
		{
			if (all->index > temp->index )
				index++ ;
			if (index == 2)
				return flagturn;
			temp = temp->next;
		}
		index = 0;
		flagturn++ ;
		all = all->next ;
	}
	return index;
}

int check_sort(Node **list)
{
	Node *all;
	int flag;

	flag = 0;
	all = (*list);
	while (all->next != NULL)
	{
		if (all->index > all->next->index)
			flag = -1;
		if (flag == -1)
			return (-1);
		all = all->next;
	}
	return (0);
}

