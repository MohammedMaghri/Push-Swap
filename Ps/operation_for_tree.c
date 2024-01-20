/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_for_tree.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 21:13:51 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/19 19:00:57 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	bring_last(t_Node **list)
{
	t_Node	*last;
	int		num ;

	last = (*list);
	while (last->next->next != NULL)
		last = last ->next;
	last = last->next;
	num = last->array ;
	return (num);
}

void	check_four(t_Node **list, t_Node **list_b)
{
	int	small;

	while (count_list(*list) > 3)
	{
		small = check_less(list);
		if (small == 1)
			pb_push(list, list_b);
		else if (small == 2)
			ra_rotate(list);
		else if (small == 3)
			rra_rotate(list);
		else if (small == 4)
			rra_rotate(list);
		else if (small == 5)
			rra_rotate(list);
	}
	check_tree(list);
	pa_push(list, list_b);
}

void	basic_for_you(t_Node **list)
{
	if (check_sort((list)) == 0)
		return ;
	if (count_list(*list) == 2)
	{
		if (check_sort(list) == -1)
		{
			sa_swap(*list);
			return ;
		}
	}
}

void	check_tree(t_Node **list)
{
	int	this;

	basic_for_you(list);
	this = check_highest(list);
	if (this == 0)
	{
		ra_rotate(list);
		if (check_sort(list) == -1)
			sa_swap(*list);
		return ;
	}
	else if (this == 1)
	{
		rra_rotate(list);
		if (check_sort(list) == -1)
			sa_swap(*list);
		return ;
	}
	else if (this == 2)
	{
		if (check_sort(list) == -1)
			sa_swap(*list);
		return ;
	}
}
