/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:34:38 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/17 21:42:31 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	count_twode(char **string)
{
	int	index ;

	index = 0;
	while (string[index])
	{
		index++ ;
	}
	return (index);
}

int	check_to_add(char **string)
{
	int	index ;
	int	flag ;
	int	incre ;

	incre = 0;
	flag = 0;
	index = 0;
	while (index < count_twode(string))
	{
		while (string[index])
		{
			if (string[index][incre] == ' ')
				incre++ ;
			else
			{
				flag++ ;
				while (string[index][incre] != ' ')
					incre++ ;
			}
		}
		incre = 0;
		index++ ;
	}
	return (flag);
}

int	number_converter(char *string)
{
	t_fac	conv;

	conv.index = 0;
	conv.total = 0;
	conv.flag = 1;
	while ((string[conv.index] >= 9 && string[conv.index] <= 13) || \
	string[conv.index] == ' ')
		conv.index++ ;
	while (string[conv.index] == '-' || string[conv.index] == '+')
	{
		if (string[conv.index] == '-')
		{
			conv.flag *= -1;
		}
		conv.index++ ;
	}
	while (string[conv.index] >= '0' && string[conv.index] <= '9')
	{
		conv.total = (conv.total * 10) + (string[conv.index] - '0');
		conv.index++ ;
	}
	return (conv.total * conv.flag);
}

int	*convert_to_number(char **string, t_addr *add)
{
	t_parc	convert;
	int		*number ;

	convert.index = 0;
	convert.increment = 0;
	convert.total = count_total(string);
	number = malloc(sizeof(int) * convert.total);
	if (!number)
	{
		free_all(string);
		exit(1);
	}
	while (convert.index < convert.total && convert.increment < convert.total)
	{
		if (string[convert.increment][0] == '\0')
			convert.increment++ ;
		number[convert.index] = number_converter(string[convert.increment]);
		convert.index++ ;
		convert.increment++;
	}
	add->address = convert.index;
	free_all(string);
	return (number);
}

char	*keep_one(char *string)
{
	int		index ;
	char	*allocation;
	int		incremnt;

	index = 0;
	incremnt = 0;
	allocation = malloc(sizeof(char) * lecount(string) + 1);
	while (string[index])
	{
		if (string[index] == ' ' && string[index + 1] != ' ')
		{
			allocation[incremnt] = ' ';
			incremnt++ ;
		}
		if (string[index] != ' ')
		{
			allocation[incremnt] = string[index];
			incremnt++ ;
		}
		index++ ;
	}
	allocation[incremnt] = '\0';
	free(string);
	return (allocation);
}
