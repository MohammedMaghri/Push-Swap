/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_extra.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 18:59:51 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/24 11:21:59 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	if_null(char *string, t_Node **list, t_Node **list_b)
{
	(void)list_b ;
	if (string[0] == '\0')
	{
		if (check_sort(list) == -1)
		{
			write(2, "KO\n", 3);
			exit(1);
		}
		else
		{
			write(2, "OK\n", 3);
			exit(0);
		}
	}
}

void	check_condition(char *string, int flag)
{
	if ((lecount(string) != 3 && lecount(string) != 4))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	else if (flag >= 1 && flag <= 2)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

void	last_check(t_Node **list, t_Node **list_b)
{
	int	track;

	(void)list_b ;
	track = 0;
	track = check_sort(list);
	if (track == -1)
	{
		write(2, "KO\n", 3);
		exit(1);
	}
	else
	{
		putstr("OK\n");
		exit(0);
	}
}
