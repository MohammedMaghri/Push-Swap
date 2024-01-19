/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:41:08 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/18 17:53:51 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	pb_push(t_Node **list_a, t_Node **list_b)
{
	t_Node	*other ;
	t_Node	*point ;

	if (*list_a == NULL)
		return ;
	other = (*list_b);
	point = (*list_a)->next;
	(*list_b) = (*list_a);
	(*list_a) = point;
	(*list_b)->next = other;
	putstr("pb\n");
}

void	pa_push(t_Node **list_a, t_Node **list_b)
{
	t_Node	*keep ;
	t_Node	*flag ;
	t_Node	*move ;

	if (*list_b == NULL)
		return ;
	keep = (*list_a);
	flag = (*list_b);
	move = (*list_b)->next;
	(*list_b) = move;
	(*list_a) = flag;
	(*list_a)->next = keep;
	putstr("pa\n");
}
