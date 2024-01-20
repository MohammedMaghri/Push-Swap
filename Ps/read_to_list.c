/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_to_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:38:12 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/20 16:50:15 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	paste(char string)
{
	write(1, &string, 1);
}

int	count_how_much(char *string)
{
	int	flag ;
	int	index ;

	flag = 0;
	index = 0;
	while (string[index])
	{
		if (string[index] == ' ')
			index++ ;
		else
		{
			flag++ ;
			while (string[index] != ' ')
			{
				index++ ;
			}
		}
	}
	return (flag);
}

char	*make_new(char *string, int checkpoint)
{
	int		index ;
	char	*allocation;

	index = 0;
	allocation = malloc(sizeof(char) * (checkpoint + 1));
	if (!allocation)
		return (NULL);
	while (index < checkpoint)
	{
		allocation[index] = string[index];
		index++ ;
	}
	allocation[index] = '\0';
	return (allocation);
}

char	*string_maker(char *string)
{
	int		index ;
	char	*allocation;

	index = 0;
	allocation = malloc(sizeof(char) * (lecount(string) + 1));
	if (!allocation)
		return (NULL);
	while (string[index])
	{
		allocation[index] = string[index];
		index++ ;
	}
	allocation[index] = '\0';
	return (allocation);
}

void	pass_function(char **twode, char *string)
{
	t_parc	list ;

	list.index = 0;
	list.increment = 0;
	while (string[list.index] && lecount(string) != 0)
	{
		if (string[list.index] == ' ')
		{
			list.checkpoint = list.index;
			list.index++ ;
			twode[list.increment] = make_new(string, list.checkpoint);
			list.temp = string_maker(&string[list.index]);
			free(string);
			string = string_maker(list.temp);
			free(list.temp);
			list.index = 0;
			list.increment++ ;
		}
		list.index++;
	}
	twode[list.increment] = NULL;
	free(string);
}
