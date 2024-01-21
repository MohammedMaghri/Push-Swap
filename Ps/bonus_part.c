/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_part.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:57:56 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/21 19:01:28 by mmaghri          ###   ########.fr       */
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
		exit(1);
	while (nl.flag > 0)
	{
		nl.flag = read(fd, nl.string, 100000);
		if_null(nl.string, list);
		check_condition(nl.string, nl.flag);
		test_the_command(nl.string, list, list_b);
	}
	free(nl.string);
	last_check(list);
}

char	**command_storage(void)
{
	char	**allocation;

	allocation = malloc(sizeof(char **) * (11));
	if (!allocation)
		exit(1);
	allocation[0] = "sa\n";
	allocation[1] = "sb\n";
	allocation[2] = "ss\n";
	allocation[3] = "pa\n";
	allocation[4] = "pb\n";
	allocation[5] = "ra\n";
	allocation[6] = "rb\n";
	allocation[7] = "rr\n";
	allocation[8] = "rra\n";
	allocation[9] = "rrb\n";
	allocation[10] = "rrr\n";
	allocation[12] = NULL;
	return (allocation);
}
