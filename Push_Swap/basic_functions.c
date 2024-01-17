/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:06:12 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/17 11:43:55 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	putstr(char *string)
{
	while (*string)
		write(1, string++, 1);
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
