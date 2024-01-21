/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_extra.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 18:59:51 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/21 19:02:29 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	if_null(char *string, t_Node **list)
{
	if (string[0] == '\0')
	{
		if (check_sort(list) == -1)
		{
			putstr("KO\n");
			return ;
		}
		else
		{
			putstr("OK\n");
			return ;
		}
	}
}

void	check_condition(char *string, int flag)
{
	if (((lecount(string) != 3 && lecount(string) != 4) \
	|| (flag >= 1 && flag <= 2)))
	{
		putstr("Error");
		exit(1);
	}
}

void	last_check(t_Node **list)
{
	int	track;

	track = 0;
	track = check_sort(list);
	if (track == -1)
	{
		putstr("KO\n");
		exit(1);
	}
	else
	{
		putstr("OK\n");
		exit(1);
	}
}
