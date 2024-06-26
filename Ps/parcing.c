/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:53:52 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/23 23:35:25 by mmaghri          ###   ########.fr       */
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
	if ((string >= '0' && string <= '9') || string == ' ' || \
	string == '-' || string == '+')
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
				write(2, "Error\n", 6);
				exit(1);
			}
		}
		if (check_number(string[index]) != 0)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		index++ ;
	}
	return (0);
}

void	ss_swap_bonus(t_Node *list_a, t_Node *list_b)
{
	if (count_list(list_a) <= 1 || count_list(list_b) <= 1)
		return ;
	sa_swap(list_a);
	sb_swap(list_b);
}
