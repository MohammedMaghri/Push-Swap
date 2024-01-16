/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_for_tree.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 21:13:51 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/16 18:58:00 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int bring_last(Node **list)
{
	Node *last;
	int num ;

	last = (*list);
	while (last->next->next != NULL)
		last = last ->next;
	last = last->next;
	num = last->array ;
	return (num);
}
void push_positiong(Node **list, Node **list_b)
{

	while (count_list(*list) > 3)
	{
		if (check_less(list) == 1)
			pb_push(list, list_b);
		else if (check_less(list) == 2)
			ra_rotate(list);
		else if (check_less(list) == 3)
			rra_rotate(list);
		else if (check_less(list) == 4)
			rra_rotate(list);
		else if (check_less(list) == 5)
			rra_rotate(list);
	}
	check_tree(list);
	pa_push(list, list_b);
	pa_push(list, list_b);
}
void push_bigger(Node **list, Node **list_b)
{
	Node *listing;
	Node *tmp;
	(void)list_b ;
	listing = (*list);
	while (listing->next != NULL)
	{
		if (listing->index != 0)
				ra_rotate(list);
		listing = (*list);
		if (listing->index == 0)
		{
			pb_push(list, list_b);
			break;
		}
	}
	listing = (*list);
	while (listing->next)
	{
		if (listing->index != 1)
				ra_rotate(list);
		listing = (*list);
		if (listing->index == 1)
		{
			pb_push(list, list_b);
			break;
		}
	}
	check_tree(list);
	tmp = *list;
	pa_push(list, list_b);
	pa_push(list, list_b);
}

void sort_five(Node **list, Node **list_b)
{
	if (count_list(*list) != 5)
		return ;
	push_bigger(list, list_b);	
	if (check_sort(list) == 0)
		return ;
}

void check_tree(Node **list)
{
	if (check_sort(list) == 0)
		return ;
	else if (count_list(*list) == 2)
		{
			if (check_sort(list) == -1)
				sa_swap(*list);
			return ;
		}
	else if (check_highest(list) == 1)
	{
		ra_rotate(list);
		if (check_sort(list) == -1)
			sa_swap(*list);
		return ;
	}
	else if (check_highest(list) == 2)
	{
		rra_rotate(list);
		if (check_sort(list) == -1)
			sa_swap(*list);
		return ;
	}
	else if (check_highest(list) == 3)
	{
		if (check_sort(list) == -1)
			sa_swap(*list);
		return ;
	}

}