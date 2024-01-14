/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 14:39:45 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/14 14:55:40 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ra_rotate(Node **list)
{
	Node	*from;
	Node	*hnaya;
	Node	*flag;

	from = NULL;
	if (count_list(*list) < 2)
		return ;
	(*list) = from;
	from = (*list)->next;
	flag = (*list);
	hnaya = *list;
	while (hnaya->next != NULL)
		(hnaya) = (hnaya)->next;
	hnaya->next = flag;
	flag->next = NULL;
	putstr("ra\n");
}

void	rb_rotate(Node **list_b)
{
	Node	*flag ;
	Node	*track ;
	Node	*follow;

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

void	rr_rotate(Node **list_a, Node **list_b)
{
	ra_rotate((list_a));
	rb_rotate((list_b));
	putstr("rr\n");
}
