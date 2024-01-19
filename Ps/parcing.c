/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:53:52 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/17 21:20:41 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	free_all(char **string)
{
	int	index ;

	index = 0;
	while (index < count_total(string))
	{
		free(string[index]);
		index++ ;
	}
	free(string);
}

int	check_number(char string)
{
	if ((string >= '0' && string <= '9') || string == ' ' || string == '-' || string == '+')
		return (0);
	return (-1);
}

int	check_validity(char *string)
{
	int	index;

	index = 0;
	while (string[index])
	{
		if (string[index] == '-')
		{
			if (string[index + 1] == '-')
			{
				putstr("Error");
				exit(1);
			}
		}
		if (check_number(string[index]) != 0)
		{
			putstr("Error\n");
			exit(1);
		}
		index++ ;
	}
	return (0);
}
