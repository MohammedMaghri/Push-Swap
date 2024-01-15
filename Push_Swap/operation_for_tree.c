/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_for_tree.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 21:13:51 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/14 22:22:54 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	check_biggest(Node **list, int num, int index)
{
	t_parc	elem;
	Node	*new ;

	new = (*list);
	elem.index = 0;
	(void)num;
	while (new->next != NULL)
	{
		new = new->next ;
		elem.index++;
		if (elem.index == index)
			break ;
	}
		printf("%d--\n", new->array);
		printf("%d--\n", new->next->array);
}

void	check_if_only_tree(Node **list)
{
	int		first ;
	int		second;
	int		third;
	Node	*copy ;

	copy = (*list);
	if (count_list(*list) != 3)
		return ;
	first = copy->array;
	check_biggest(list, first, 1);
	copy = copy->next;
	second = copy->array;
	copy = copy->next;
	third = copy->array ;
}
