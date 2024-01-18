/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 11:19:23 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/18 11:27:06 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sadd_list(t_Node *add, int num)
{
	t_Node	*str;

	str = malloc(sizeof(struct Node));
	while (add->next != NULL)
		add = add->next;
	add->next = str;
	str->array = num;
	str->index = 0;
	str->next = NULL;
}

void	function_made(int *num, t_Node *list, t_addr *add)
{
	t_parc	made;

	made.index = 0;
	list->array = num[made.index];
	list->next = NULL;
	made.index++ ;
	while (made.index < add->address)
	{
		sadd_list(list, num[made.index]);
		made.index++;
	}
}

int	count_list(t_Node *list)
{
	t_parc	count;

	count.index = 1;

	if (!list)
		return (0);
	while (list->next != NULL)
	{
		list = list->next ;
		count.index++ ;
	}
	return (count.index);
}

void	at_linked(t_Node **list)
{
	t_Node	*link ;
	t_Node	*temp;

	link = (*list);
	temp = (*list);
	while (link)
	{
		temp = (*list);
		while (temp)
		{
			if (link->array > temp->array)
				link->index++;
			temp = temp->next;
		}
		link = link->next;
	}
}

int	check_sort(t_Node **list)
{
	t_Node	*all;
	int		flag;

	flag = 0;
	all = (*list);
	while (all->next != NULL)
	{
		if (all->index > all->next->index)
			flag = -1;
		if (flag == -1)
			return (-1);
		all = all->next;
	}
	return (0);
}
