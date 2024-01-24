/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raa_for_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 12:25:11 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/24 12:49:21 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	pb_push_bonus(t_Node **list_a, t_Node **list_b)
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
}

void	pa_push_bonus(t_Node **list_a, t_Node **list_b)
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
}

void	ra_rotate_bonus(t_Node **list_a)
{
	t_Node	*flag ;
	t_Node	*track ;
	t_Node	*follow;

	if (count_list(*list_a) <= 1)
		return ;
	flag = (*list_a);
	track = (*list_a)->next;
	follow = flag;
	(*list_a) = track ;
	while (follow->next != NULL)
		follow = follow->next;
	follow->next = flag;
	flag->next = NULL;
}

void	rb_rotate_bonus(t_Node **list_b)
{
	t_Node	*flag ;
	t_Node	*track ;
	t_Node	*follow;

	if (count_list(*list_b) <= 1)
		return ;
	flag = (*list_b);
	track = (*list_b)->next;
	follow = flag;
	(*list_b) = track ;
	while (follow->next != NULL)
		follow = follow->next;
	follow->next = flag;
	flag->next = NULL;
}

void	rr_rotate_bonus(t_Node **list_a, t_Node **list_b)
{
	if (count_list(*list_a) == 0 || count_list(*list_b) == 0)
		return ;
	ra_rotate_bonus((list_a));
	rb_rotate_bonus((list_b));
}
