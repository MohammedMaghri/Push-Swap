/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:59:20 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/19 12:00:45 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	check_double(int *num, t_addr *ind)
{
	t_parc	doble;

	doble.index = 0;
	doble.increment = 0;
	doble.flag = 0;
	doble.total = 0;
	while (doble.index < ind->address)
	{
		doble.flag = num[doble.index];
		doble.total++ ;
		doble.increment = doble.total;
		while (doble.increment < ind->address)
		{
			if (doble.flag == num[doble.increment])
			{
				putstr("error..");
				exit(1);
			}
			doble.increment++ ;
		}
		doble.increment = 0;
		doble.index++;
	}
}
void check_plus(char **array)
{
	t_parc all;

	all.index = 0 ;
	all.i = 0;
	while (all.index < count_total(array))
	{
		while (array[all.index][all.i])
		{
			if ((number_only(array[all.index][all.i ]) == 0 && array[all.index][all.i + 1] == '-') || \
			((array[all.index][all.i] == '+' && array[all.index][all.i + 1] == '+') || \
			((array[all.index][all.i] == '+' && array[all.index][all.i + 1] == '\0')) || \
			(array[all.index][all.i] == '+' && array[all.index][all.i + 1] == ' ')))
			{
				putstr("Error..\n");
				exit(1);
			}
			all.i++ ;
		}
		all.i = 0;
		all.index++ ;
	}
}

void check_other_plus(char **array)
{
	t_parc all;

	all.index = 0;
	all.i = 0;
	while (all.index < count_total(array))
	{
		while (array[all.index][all.i])
		{
			if ((lecount(array[all.index]) == 1 && array[all.index][all.i] == '+') || \
			(number_only(array[all.index][all.i]) == 0 && array[all.index][all.i + 1] == '+' ))
			{
				putstr("Error.");
				exit(1);
			}
			all.i++;
		}
		all.i = 0;
		all.index++ ;
	}
}
