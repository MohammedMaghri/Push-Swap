/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_for_tree.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 21:13:51 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/15 21:56:48 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void sort_five(Node **list, Node **list_b)
{

	if (check_sort(list) == 0)
		return ;
	pb_push(list, list_b);
	pb_push(list, list_b);

	check_tree(list);
	check_tree(list_b);
}

void check_tree(Node **list)
{
	if (check_sort(list) == 0)
		return ;
	if (count_list(*list) == 5)
		
	if (count_list(*list) == 2)
		{
			if (check_sort(list) == -1)
				sa_swap(*list);
		}
	if (check_highest(list) == 1)
	{
		ra_rotate(list);
		if (check_sort(list) == -1)
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