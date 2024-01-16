/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_for_tree.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 21:13:51 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/16 15:09:48 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void push_bigger(Node **list, Node **list_b)
{
	Node *listing;
	Node *tmp;
	(void)list_b ;
	listing = (*list);
	while (listing->index)
	{
		if (listing->index != 0)
			ra_rotate(list);
		listing = (*list);
		if (listing->index == 0)
		{
			printf("LIST->index %d\n", listing->index);
			pb_push(list, list_b);
			break;
		}
	}
	listing = (*list);
	while (listing->index)
	{
		if (listing->index != 1)
			ra_rotate(list);
		listing = (*list);
		if (listing->index == 1)
		{
			printf("LIST->index %d\n", listing->index);
			pb_push(list, list_b);
			break;
		}
	}
	tmp = *list;
	while (tmp != NULL)
    {
        printf(" -----> [%d]\n", tmp->index);
        tmp = tmp->next;
    }
	check_tree(list);
	// pa_push(list, list_b);
	// pa_push(list, list_b);
}

void sort_five(Node **list, Node **list_b)
{
	// while (count_list(*list) != 3)
		push_bigger(list, list_b);
	// if (count_list(*list) != 5)
	// 	return ;
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
		}
	else if (check_highest(list) == 1)
	{
		ra_rotate(list);
		// if (check_sort(list) == -1)
		sa_swap(*list);
	}
	else if (check_highest(list) == 2)
	{
		rra_rotate(list);
		if (check_sort(list) == -1)
			sa_swap(*list);
	}
	else if (check_highest(list) == 3)
	{
		if (check_sort(list) == -1)
			sa_swap(*list);
	}

}