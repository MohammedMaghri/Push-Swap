/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 14:44:14 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/14 15:02:19 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sa_swap(Node *list_a)
{
	Node	*first ;
	int		sec;
	int		num;

	if (count_list(list_a) <= 1)
		return ;
	first = list_a;
	num = first->array;
	first = first->next;
	sec = first->array;
	list_a->array = sec;
	list_a = list_a->next;
	list_a->array = num;
	putstr("sa\n");
}

void	sb_swap(Node *list_b)
{
	int		sec;
	int		num;
	Node	*first ;

	if (count_list(list_b) <= 1)
		return ;
	first = list_b;
	num = first->array;
	first = first->next;
	sec = first->array;
	list_b->array = sec;
	list_b = list_b->next;
	list_b->array = num;
	putstr("sb\n");
}

void	ss_swap(Node *list_a, Node *list_b)
{
	if (count_list(list_a) <= 1 || count_list(list_b) <= 1)
		return ;
	sa_swap(list_a);
	sb_swap(list_b);
	putstr("ss\n");
}
