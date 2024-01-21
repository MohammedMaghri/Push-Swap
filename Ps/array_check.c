/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:34:38 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/21 22:26:11 by mmaghri          ###   ########.fr       */
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

void function_check(int number)
{
	if (number < 0)
	{
		putstr("Error");
		exit(1);
	}
}
int make_it(char *string)
{
	int	index ;
	int total;
	int track;

	track = 0;
	total = 0;
	index = 0;
	while (string[index] >= '0' && string[index] <= '9')
	{
		total = (total * 10) + (string[index] - '0');
		if (track > 8)
			function_check(total);
		track++ ;
		index++ ;
	}
	return (total);
}
int	number_converter(char *string)
{
	t_fac	conv;
	int		index;

	index = 0;
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
	conv.total = make_it(&string[conv.index]);
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
		exit(1);
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
	t_parc	list;

	list.index = 0;
	list.increment = 0;
	list.allocation = malloc(sizeof(char) * lecount(string) + 1);
	if (!list.allocation)
		exit(1);
	while (string[list.index])
	{
		if (string[list.index] == ' ' && string[list.index + 1] != ' ')
		{
			list.allocation[list.increment] = ' ';
			list.increment++ ;
		}
		if (string[list.index] != ' ')
		{
			list.allocation[list.increment] = string[list.index];
			list.increment++ ;
		}
		list.index++ ;
	}
	list.allocation[list.increment] = '\0';
	free(string);
	return (list.allocation);
}
