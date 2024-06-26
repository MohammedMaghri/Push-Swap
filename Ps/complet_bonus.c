/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complet_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 18:32:58 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/24 12:47:39 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

char	*add_till(char *string)
{
	char	*allocation;	
	int		index;
	int		increment;

	index = 0;
	increment = 0;
	allocation = malloc(sizeof(char) * 4);
	if (!allocation)
		exit(1);
	while (string[index] && string[index] != '\n')
	{
		allocation[index] = string[index];
		index++ ;
	}
	allocation[index] = '\0';
	return (allocation);
}

int	all_of(char *string)
{
	t_bone	zz;

	zz.increment = 0;
	zz.index = 0;
	zz.flag = 0;
	zz.res = command_storage();
	while (zz.index < 11)
	{
		while (string[zz.increment])
		{
			if (string[zz.increment] == zz.res[zz.index][zz.increment])
				zz.flag++ ;
			if (zz.flag == lecount(string))
			{
				free(string);
				return (1);
			}
			zz.increment++;
		}
		initilaize(&zz.index, &zz.increment, &zz.flag);
	}
	free(string);
	return (0);
}

void	test_the_command(char *string, t_Node **list, t_Node **list_b)
{
	int		flag;

	if (lecount(string) >= 5)
		exit(1);
	if (lecount(string) == 3)
	{
		flag = compare_all(string, 3, list, list_b);
		if (flag == 1)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		string[0] = '*';
	}
	else if (lecount(string) == 2)
	{
		flag = compare_all(string, 2, list, list_b);
		if (flag == 1)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		string[0] = '*';
	}
}

int	call_to_apply(int number, t_Node **list, t_Node **list_b)
{
	(void)list_b;
	if (number == 0)
		return (sa_swap_bonus((*list)), -1);
	else if (number == 1)
		return (sb_swap_bonus((*list_b)), -1);
	else if (number == 2)
		return (ss_swap_bonus((*list), *list_b), -1);
	else if (number == 3)
		return (pa_push_bonus((list), (list_b)), -1);
	else if (number == 4)
		return (pb_push_bonus((list), (list_b)), -1);
	else if (number == 5)
		return (ra_rotate_bonus((list)), -1);
	else if (number == 6)
		return (rb_rotate_bonus((list_b)), -1);
	else if (number == 7)
		return (rr_rotate_bonus((list), list_b), -1);
	else if (number == 8)
		return (rra_rotate_bonus((list)), -1);
	else if (number == 9)
		return (rrb_rotate_bonus((list_b)), -1);
	else if (number == 10)
		return (rrr_rotate_bonus((list), (list_b)), -1);
	return (0);
}

int	compare_all(char *string, int checker, t_Node **list, t_Node **list_b)
{
	t_bone	bon;

	bon.increment = 0;
	bon.win = 1;
	bon.flag = 0;
	bon.index = 0;
	bon.res = command_storage();
	while (bon.increment < 11)
	{
		while (string[bon.index])
		{
			if (bon.res[bon.increment][bon.index] == string[bon.index])
				bon.flag++;
			if (bon.flag == checker)
			{
				bon.win = (0);
				free(bon.res);
				return (call_to_apply(bon.increment, list, list_b), bon.win);
			}
			bon.index++;
		}
		initilaize(&bon.increment, &bon.index, &bon.flag);
	}
	free(bon.res);
	return (-1);
}
