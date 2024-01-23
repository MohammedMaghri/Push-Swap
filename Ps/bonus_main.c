/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:35:54 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/23 18:00:37 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char **argv)
{
	int			*num;
	t_addr		add;
	t_Node		*list;
	t_Node		*list_b;

	if (argc <= 1)
		exit(0);
	list = malloc(sizeof(struct Node));
	if (!list)
		exit(1);
	list_b = NULL ;
	check_args(argv);
	num = convert_to_number(read_to_list(keep_one(merge_in_one(argv, argc))) \
, &add);
	check_double(num, &add);
	function_made(num, list, &add);
	at_linked(&list);
	read_till_null(0, argc, &list, &list_b);
	exit(0);
}
