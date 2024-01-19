/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 14:39:45 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/17 11:33:35 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ra_rotate(t_Node **list_a)
{
	t_Node	*flag ;
	t_Node	*track ;
	t_Node	*follow;

	if (count_list(*list_a) == 1)
		return ;
	flag = (*list_a);
	track = (*list_a)->next;
	follow = flag;
	(*list_a) = track ;
	while (follow->next != NULL)
		follow = follow->next;
	follow->next = flag;
	flag->next = NULL;
	putstr("ra\n");
}

void	rb_rotate(t_Node **list_b)
{
	t_Node	*flag ;
	t_Node	*track ;
	t_Node	*follow;

	if (count_list(*list_b) == 1)
		return ;
	flag = (*list_b);
	track = (*list_b)->next;
	follow = flag;
	(*list_b) = track ;
	while (follow->next != NULL)
		follow = follow->next;
	follow->next = flag;
	flag->next = NULL;
	putstr("rb\n");
}

void	rr_rotate(t_Node **list_a, t_Node **list_b)
{
	ra_rotate((list_a));
	rb_rotate((list_b));
	putstr("rr\n");
}
