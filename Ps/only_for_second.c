/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   only_for_second.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:34:58 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/22 21:39:35 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	for_second_iteration(t_Node **list, t_Node **list_b, \
int *bottom, int *bigger)
{
	while (((*list)->index - 1) != ((*list_b)->index))
	{
		if ((*list_b)->index > *bottom || \
		*bottom == *bigger)
		{
			pa_push(list, list_b);
			ra_rotate(list);
			*bottom = find_bottom_index(list);
		}
		else
			rrb_rotate(list_b);
	}
	while (*list_b && (*list)->index == (*list_b)->index + 1)
		pa_push(list, list_b);
	while (find_bottom_index(list) == (*list)->index - 1)
	{
		rra_rotate(list);
		*bottom = find_bottom_index(list);
	}
}

void	for_the_second_of_thesecond(t_Node **list, t_Node **list_b, \
int *bottomindex)
{
	while (*list_b && (*list)->index == (*list_b)->index + 1)
		pa_push(list, list_b);
	while (find_bottom_index(list) == (*list)->index - 1)
	{
		rra_rotate(list);
		*bottomindex = find_bottom_index(list);
	}
}

void	for_condition(t_Node **list, t_Node **list_b, int *bottomindex)
{
	pa_push(list, list_b);
	ra_rotate(list);
	*bottomindex = find_bottom_index(list);
}

void	second_iteration(t_Node **list, t_Node **list_b)
{
	int	flag;
	int	biggest_number;
	int	bottomindex;

	biggest_number = find_bottom_index(list);
	bottomindex = find_bottom_index(list);
	while (count_list(*list_b) != 0)
	{
		flag = check_if_up(list_b, ((*list)->index) - 1);
		if (flag == 0)
		{
			while (((*list)->index - 1) != ((*list_b)->index))
			{
				if ((*list_b)->index > bottomindex || \
				bottomindex == biggest_number)
					for_condition(list, list_b, &bottomindex);
				else
					rb_rotate(list_b);
			}
			pa_push(list, list_b);
		}
		else if (flag == -1)
			for_second_iteration(list, list_b, &bottomindex, &biggest_number);
		for_the_second_of_thesecond(list, list_b, &bottomindex);
	}
}
