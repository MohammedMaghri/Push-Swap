/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 14:42:06 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/18 16:00:24 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	check_greater(int *array, t_addr *add)
{
	int	index ;
	int	flag;
	int	incre;

	index = 0;
	flag = array[index];
	while (index <= add->address)
	{
		index++ ;
		incre = index;
		while (incre < add->address)
		{
			if (flag > array[incre])
				return ;
			incre++ ;
		}
		incre = 0;
		flag = array[index];
	}
	exit(0);
}

void	rra_rotate(t_Node **list_a)
{
	t_Node	*inc ;
	t_Node	*var ;

	if (count_list(*list_a) < 2)
		return ;
	if (count_list(*list_a) == 2)
	{
		sa_swap(*list_a);
		return ;
	}
	inc = (*list_a);
	var = NULL;
	while (inc->next != NULL)
	{
		var = inc ;
		inc = inc->next;
	}
	var->next = NULL;
	inc->next = (*list_a);
	(*list_a) = inc;
	putstr("rra\n");
}

void	rrb_rotate(t_Node **list_b)
{
	t_Node	*head;
	t_Node	*position;

	if (count_list(*list_b) == 1)
		return ;
	if (count_list(*list_b) == 2)
	{
		sa_swap(*list_b);
		return ;
	}
	head = (*list_b);
	position = NULL;
	while (head->next != NULL)
	{
		position = head ;
		head = head->next ;
	}
	position->next = NULL;
	head->next = (*list_b);
	(*list_b) = head;
}

void	rrr_rotate(t_Node **list_a, t_Node **list_b)
{
	rrb_rotate(list_a);
	rrb_rotate(list_b);
	putstr("rrr\n");
}
