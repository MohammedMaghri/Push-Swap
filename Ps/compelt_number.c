/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compelt_number.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:07:03 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/22 17:55:41 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	function_check(long long number, int flag)
{
	if (number > 2147483647 && flag > 0)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	else if (flag < 0 || number < 0)
	{
		if (number > 2147483648)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
	}
}

int	make_it(char *string, int flag)
{
	int			index ;
	long long	total;
	int			track;

	track = 0;
	total = 0;
	index = 0;
	while (string[index] >= '0' && string[index] <= '9')
	{
		total = (total * 10) + (string[index] - '0');
		index++ ;
	}
	function_check(total, flag);
	return (total);
}
