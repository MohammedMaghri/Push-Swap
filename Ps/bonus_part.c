/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_part.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:57:56 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/24 11:25:25 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

char	*for_saftey(char *string)
{
	int		index ;
	char	*allocation;

	index = 0;
	allocation = malloc(sizeof(char) * lecount(string) + 1);
	if (!allocation)
		exit(1);
	while (string[index])
	{
		allocation[index] = string[index];
		index++ ;
	}
	allocation[index] = '\0';
	return (allocation);
}

void	free_out(char *string)
{
	free(string);
	write(1, "Error\n", 1);
	exit(1);
}

char	*merge(char *string, char *wedohave)
{
	char	*allocation;
	int		index;
	int		total;
	int		increment;

	if (!string)
		return (for_saftey(wedohave));
	if (!wedohave)
		return (for_saftey(string));
	increment = 0;
	total = (lecount(string) + lecount(wedohave) + 1);
	index = 0;
	allocation = malloc(sizeof(char) * total);
	if (!allocation)
		exit(1);
	while (string[index])
		allocation[increment++] = string[index++];
	allocation[increment] = ' ';
	increment++;
	index = 0;
	while (wedohave[index])
		allocation[increment++] = wedohave[index++];
	allocation[increment] = '\0';
	free(wedohave);
	return (allocation);
}

void	read_till_null(int fd, int argc, t_Node **list, t_Node **list_b)
{
	t_null	nl;

	nl.rais = 0;
	nl.flag = 1;
	nl.string = malloc((sizeof(char **)) * argc);
	if (!nl.string)
		free_out(nl.string);
	while (nl.flag > 0)
	{
		nl.flag = read(fd, nl.string, 100000);
		if (nl.flag == 0)
			break ;
		if_null(nl.string, list, list_b);
		check_condition(nl.string, nl.flag);
		nl.rais = all_of(add_till(nl.string));
		if (nl.rais == 0)
			for_er();
		test_the_command(add_till(nl.string), list, list_b);
	}
	count_if(list_b);
	free(nl.string);
	last_check(list, list_b);
}

char	**command_storage(void)
{
	char	**allocation;

	allocation = malloc(sizeof(char **) * (11));
	if (!allocation)
	{
		free_all(allocation);
		exit(1);
	}
	allocation[0] = "sa";
	allocation[1] = "sb";
	allocation[2] = "ss";
	allocation[3] = "pa";
	allocation[4] = "pb";
	allocation[5] = "ra";
	allocation[6] = "rb";
	allocation[7] = "rr";
	allocation[8] = "rra";
	allocation[9] = "rrb";
	allocation[10] = "rrr";
	allocation[11] = NULL;
	return (allocation);
}
