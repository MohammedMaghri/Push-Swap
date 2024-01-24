/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:24:33 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/24 11:33:48 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	for_ko(void)
{
	write(2, "KO\n", 2);
	exit(1);
}

void	for_er(void)
{
	write(2, "Error\n", 2);
	exit(1);
}

void	count_if(t_Node **list_b)
{
	if (count_list(*list_b) >= 1)
	{
		write(2, "KO\n", 3);
		exit(1);
	}
}

void	up_there(char *string, char *res, int *increment, int *flag)
{
	if (string[*increment] == res[*increment])
		*flag += 1;
}

void	initilaize(int *increment, int *index, int *flag)
{
	*increment += 1;
	*index = 0;
	*flag = 0;
}
