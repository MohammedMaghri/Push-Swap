/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whole_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:01:41 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/24 12:16:13 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	find_bottom_index(t_Node **list)
{
	t_Node	*test;
	int		last ;

	test = (*list);
	while (test->next)
		test = test->next;
	last = test->index;
	return (last);
}

int	check_if_up(t_Node **list, int index)
{
	t_Node	*all;
	int		i;
	int		total;
	int		this_res;

	i = 0;
	all = *list;
	total = (count_list(*list) / 2);
	while (all != NULL)
	{
		if (all->index == index)
			break ;
		all = all->next;
		i++;
	}
	this_res = (total - i);
	if (this_res <= 0)
		return (-1);
	return (0);
}

void	index_all(t_Node **list, t_Node **list_b, t_lspies *lsp)
{
	if (check_sort(list) == 0)
		exit(0);
	lsp->lastpivot = -1;
	lsp->pvtone = (count_list(*list) / 3);
	lsp->pvttwo = (count_list(*list) / 6);
	while (count_list(*list) > 3)
	{
		if ((*list)->index < lsp->pvtone)
			pb_push(list, list_b);
		else
			ra_rotate(list);
		if (count_list(*list_b) > 1 && ((*list_b)->index >= lsp->lastpivot && \
		(*list_b)->index <= lsp->pvttwo))
			rb_rotate(list_b);
		if (count_list(*list_b) == lsp->pvtone)
		{
			lsp->lastpivot = lsp->pvtone;
			lsp->pvttwo = (count_list(*list) / 6) + lsp->pvtone;
			lsp->pvtone = (lsp->pvtone + (count_list(*list) / 3));
		}
	}
	check_tree(list);
	second_iteration(list, list_b);
}
