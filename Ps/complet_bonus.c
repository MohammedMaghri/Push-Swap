/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complet_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 18:32:58 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/23 23:50:42 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <stdio.h>

void	up_there(char *string, char *res, int *increment, int *flag)
{
	if (string[*increment] == res[*increment])
		*flag += 1;
}

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
	int		index ;
	int		increment;
	int		flag;
	char	**res ;

	increment = 0;
	index = 0;
	flag = 0;
	res = command_storage();
	while (index < 11)
	{
		while (string[increment])
		{
			if (string[increment] == res[index][increment])
				flag++ ;
			if (flag == lecount(string))
			{
				free(string);
				return (1);
			}
			increment++;
		}
		flag = 0;
		increment = 0;
		index++ ;
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
		return (sb_swap_bonus((*list)), -1);
	else if (number == 2)
		return (ss_swap_bonus((*list), *list_b), -1);
	else if (number == 3)
		return (pa_push_bonus((list), (list_b)), -1);
	else if (number == 4)
		return (pb_push_bonus((list), (list_b)), -1);
	else if (number == 5)
		return (ra_rotate_bonus((list)), -1);
	else if (number == 6)
		return (rb_rotate_bonus((list)), -1);
	else if (number == 7)
		return (rr_rotate_bonus((list), list_b), -1);
	else if (number == 8)
		return (rra_rotate_bonus((list)), -1);
	else if (number == 9)
		return (rrb_rotate_bonus((list)), -1);
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
		bon.increment++ ;
		bon.index = 0;
		bon.flag = 0;
	}
	free(bon.res);
	return (-1);
}
