/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:06:12 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/22 11:30:47 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	putstr(char *string)
{
	while (*string)
		write(2, string++, 1);
}

int	lecount(char *string)
{
	int	index ;

	index = 0;
	while (string[index])
	{
		index++ ;
	}
	return (index);
}

int	count_total(char **array)
{
	t_fac	all;

	all.index = 0;
	while (array[all.index])
	{
		all.index++ ;
	}
	return (all.index);
}

char	**read_to_list(char *string)
{
	t_parc	list;
	int		checkpoint;

	checkpoint = 0;
	list.index = 0;
	list.increment = 0;
	list.twode = malloc(sizeof(char **) * 100000);
	if (!list.twode)
		exit(1);
	pass_function(list.twode, string);
	return (list.twode);
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
