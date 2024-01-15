/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_for_tree.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 21:13:51 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/15 20:51:41 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void check_tree(Node **list)
{
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