/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complet_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 18:32:58 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/22 11:37:34 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	test_the_command(char *string, t_Node **list, t_Node **list_b)
{
	int		flag;

	if (lecount(string) >= 5)
		exit(1);
	else if (lecount(string) == 4)
	{
		flag = compare_all(string, 4, list, list_b);
		if (flag == 1)
		{
			putstr("Error**");
			exit(1);
		}
		string[0] = '*';
	}
	else if (lecount(string) == 3)
	{
		flag = compare_all(string, 3, list, list_b);
		if (flag == 1)
		{
			putstr("Error-\n");
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
		while (bon.res[bon.increment][bon.index])
		{
			if (bon.res[bon.increment][bon.index] == string[bon.index])
				bon.flag++;
			if (bon.flag == checker)
			{
				bon.win = (0);
				return (call_to_apply(bon.increment, list, list_b), bon.win);
			}
			bon.index++;
		}
		bon.increment++ ;
		bon.index = 0;
		bon.flag = 0;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int			*num;
	t_addr		add;
	t_Node		*list;
	t_Node		*list_b;

	list = malloc(sizeof(struct Node));
	list_b = NULL ;
	check_args(argv);
	num = convert_to_number(read_to_list(keep_one(merge_in_one(argv, argc))) \
	, &add);
	check_double(num, &add);
	function_made(num, list, &add);
	at_linked(&list);
	read_till_null(0, argc, &list, &list_b);
}
