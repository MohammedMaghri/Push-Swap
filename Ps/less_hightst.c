/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_hightst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:37:22 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/23 13:05:40 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	check_less(t_Node **list)
{
	t_Node	*all;
	t_Node	*temp;
	int		flag;
	int		index ;
	int		flagturn ;

	flag = 0;
	flagturn = 1;
	all = (*list);
	while (all)
	{
		temp = (*list);
		while (temp)
		{
			if (all->index < temp->index)
				index++ ;
			if (index == count_list(*list) - 1)
				return (flagturn);
			temp = temp->next;
		}
		index = 0;
		flagturn++ ;
		all = all->next ;
	}
	return (index);
}

int	check_highest(t_Node **list)
{
	t_Node	*all;	
	t_Node	*temp;
	int		flag;
	int		index ;
	int		flagturn ;

	flag = 0;
	flagturn = 0;
	all = (*list);
	while (all)
	{
		temp = (*list);
		while (temp)
		{
			if (all->index > temp->index)
				index++ ;
			if (index == 2)
				return (flagturn);
			temp = temp->next;
		}
		index = 0;
		flagturn++ ;
		all = all->next ;
	}
	return (index);
}

int	check_all_heights(t_Node **list)
{
	t_Node	*all;	
	t_Node	*temp;
	int		flag;
	int		index ;
	int		flagturn ;

	flag = 0;
	flagturn = 1;
	all = (*list);
	while (all)
	{
		temp = (*list);
		while (temp)
		{
			if (all->index > temp->index)
				index++ ;
			if (index == count_list(*list) - 1)
				return (flagturn);
			temp = temp->next;
		}
		index = 0;
		flagturn++ ;
		all = all->next ;
	}
	return (index);
}

void	sort_five(t_Node **list, t_Node **list_b)
{
	if (count_list(*list) <= 3)
	{
		check_tree(list);
		exit(0);
	}
	if (check_sort(list) == 0)
		exit(0);
	while (check_less(list) != 0)
		ra_rotate(list);
	pb_push(list, list_b);
	check_four(list, list_b);
	pa_push(list, list_b);
}
