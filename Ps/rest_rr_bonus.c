/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rest_rr_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 12:26:38 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/21 12:31:14 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rra_rotate_bonus(t_Node **list_a)
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
}

void	rrb_rotate_bonus(t_Node **list_b)
{
	t_Node	*head;
	t_Node	*position;

	if (count_list(*list_b) == 1)
		return ;
	if (count_list(*list_b) == 2)
	{
		sb_swap(*list_b);
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

void	rrr_rotate_bonus(t_Node **list_a, t_Node **list_b)
{
	if (count_list(*list_a) == 0 || count_list(*list_b) == 0)
		return ;
	rrb_rotate(list_a);
	rrb_rotate(list_b);
}
void	sa_swap_bonus(t_Node *list_a)
{
	t_Node	*first ;
	int		sec;
	int		num;
	int		numindex;
	int		secindex ;

	if (count_list(list_a) <= 1)
		return ;
	first = list_a;
	num = first->array;
	numindex = first->index;
	first = first->next;
	sec = first->array;
	secindex = first->index ;
	list_a->array = sec;
	list_a->index = secindex;
	list_a = list_a->next;
	list_a->array = num;
	list_a->index = numindex;
}

void	sb_swap_bonus(t_Node *list_b)
{
	t_Node	*first ;
	int		sec;
	int		num;
	int		numindex;
	int		secindex ;

	if (count_list(list_b) <= 1)
		return ;
	first = list_b;
	num = first->array;
	numindex = first->index;
	first = first->next;
	sec = first->array;
	secindex = first->index ;
	list_b->array = sec;
	list_b->index = secindex;
	list_b = list_b->next;
	list_b->array = num;
	list_b->index = numindex;
}
