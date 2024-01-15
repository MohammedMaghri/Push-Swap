/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_for_tree.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 21:13:51 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/15 13:58:56 by mmaghri          ###   ########.fr       */
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
	// int		third;
	Node	*copy ;
	Node	*reset ;
	// Node	*position ;
	Node	*other ;

	printf("yoooo");
	reset = (*list);
	copy = (*list);
	other = (*list);
	if (count_list(*list) != 3)
		return ;
	while ((*list)->next != NULL)
	{
		printf("[%d]|\n", first);
		printf("[%d]|\n", second);
		first = (*list)->array;
		second = (*list)->next->array;
		(*list) = (*list)->next ;
	}
}