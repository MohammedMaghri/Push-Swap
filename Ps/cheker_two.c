/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheker_two.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:00:15 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/19 12:00:52 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void chek_minis(char *array)
{
	t_parc all;

	all.index = 0;

	if (array[0] == '\0' || \
	(lecount(array) == 1 && array[0] == '-'))
	{
		putstr("Error");
		exit(1);
	}
}

void check_more_min(char *array)
{
	t_parc	all;

	all.index = 0;
	while (array[all.index])
		{
			if ((array[all.index] == '-' && array[all.index + 1] == ' ' ) || \
			((array[all.index]== '-' && array[all.index + 1] == '\0') || (array[all.index] == '-' && array[all.index + 1] == '+' )))
			{
				putstr("Error");
				exit(1);
			}
			all.index++;
		}
}
void	check_args(char **array)
{
	int		i;
	t_parc	all;

	i = 0;
	all.index = 0;
	check_plus(array);
	check_other_plus(array);
	while (all.index < count_total(array))
	{
		check_more_min(array[all.index]);
		i = 0;
		chek_minis(array[all.index]);
		while (array[all.index][i] && array[all.index][i] == ' ')
		{
			if (array[all.index][i + 1] == '\0')
			{
				putstr("Error\n");
				exit(1);
			}
			i++;
		}
		i = 0;
		all.index++ ;
	}
}