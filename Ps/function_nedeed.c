/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_nedeed.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:58:44 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/20 16:50:05 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

char	*move_string(char *string)
{
	t_fac	all;

	all.allocation = malloc(sizeof(char) * lecount(string) + 1);
	while (string[all.increment])
	{
		all.allocation[all.increment] = string[all.increment];
		all.increment++;
	}
	return (all.allocation);
}

char	*merge_in_one(char **string, int ac)
{
	t_fac	all;

	all.index = 1;
	all.increment = 0;
	all.counter = 0;
	all.total = count_total(string);
	all.allocation = malloc(sizeof(char **) * (ac + 1));
	if (!all.allocation)
		exit(1);
	while (all.index < all.total)
	{
		while (string[all.index][all.increment])
		{
			check_validity(string[all.index]);
			all.allocation[all.counter] = string[all.index][all.increment];
			all.increment++;
			all.counter++;
		}
		all.allocation[all.counter] = ' ' ;
		all.counter++ ;
		all.increment = 0;
		all.index++ ;
	}
	all.allocation[all.counter] = '\0';
	return (all.allocation);
}

int	number_only(char string)
{
	if (string >= '0' && string <= '9')
		return (0);
	if (string == '-')
		return (-1);
	return (1);
}

void	for_main(char **argv, int argc)
{
	int			*num;
	t_addr		add;
	t_Node		*list;
	t_Node		*list_b;
	t_lspies	lsp;

	list = malloc(sizeof(struct Node));
	list_b = NULL ;
	check_args(argv);
	num = convert_to_number(read_to_list(keep_one(merge_in_one(argv, argc))) \
	, &add);
	check_double(num, &add);
	check_greater(num, &add);
	function_made(num, list, &add);
	at_linked(&list);
	index_all(&list, &list_b, &lsp);
}
int	main(int argc, char **argv)
{
	if (argc <= 1)
	{
		putstr("Error");
		exit(1);
	}
	for_main(argv, argc);
}
