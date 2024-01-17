/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_for_tree.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 21:13:51 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/17 11:24:05 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	bring_last(t_Node **list)
{
	t_Node	*last;
	int		num;

	last = (*list);
	while (last->next->next != NULL)
		last = last ->next;
	last = last->next;
	num = last->array ;
	return (num);
}

void	if_four(t_Node **list, t_Node **list_b)
{
	if (count_list(*list) == 4)
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
		return ;
	}
}

void	push_positiong(t_Node **list, t_Node **list_b)
{
	if (count_list(*list) == 4)
	{
		if_four(list, list_b);
		return ;
	}
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

void	for_check_tree(t_Node **list)
{
	if (check_highest(list) == 2)
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

void	check_tree(t_Node **list)
{
	if (count_list(*list) == 2)
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
	for_check_tree(list);
}
