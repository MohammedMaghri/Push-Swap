/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_nedeed.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:58:44 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/14 17:27:32 by mmaghri          ###   ########.fr       */
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

char	*merge_in_one(char **string)
{
	t_fac	all;

	all.index = 1;
	all.increment = 0;
	all.counter = 0;
	all.total = count_total(string);
	all.allocation = malloc(sizeof(char **) * 1000);
	if (!all.allocation)
		return (NULL);
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

void	check_double(int *num, t_addr *ind)
{
	t_parc	doble;

	doble.index = 0;
	doble.increment = 0;
	doble.flag = 0;
	doble.total = 0;
	while (doble.index < ind->address)
	{
		doble.flag = num[doble.index];
		doble.total++ ;
		doble.increment = doble.total;
		while (doble.increment < ind->address)
		{
			if (doble.flag == num[doble.increment])
			{
				putstr("error");
				exit(1);
			}
			doble.increment++ ;
		}
		doble.increment = 0;
		doble.index++;
	}
}

void	check_args(int argc, char **array)
{
	int		i;
	t_parc	all;

	i = 0;
	all.index = 0;
	if (argc <= 1)
	{
		putstr("Not Enough Argument");
		exit(1);
	}
	while (all.index < count_total(array))
	{
		if (array[all.index][0] == '\0')
		{
			putstr("Error");
			exit(1);
		}
		while (array[all.index][i] && array[all.index][i] == ' ')
		{
			if (array[all.index][i + 1] == '\0')
			{
				putstr("Error\n");
				exit(1);
			}
			i++;
		}
		i = 0;
		all.index++ ;
	}
	while (all.index < count_total(array))
	{
		if ((lecount(array[all.index]) == 1 && array[all.index][0] == '-') || \
		(lecount(array[all.index]) == 1 && array[all.index][0] == ' '))
		{
			putstr("Error");
			exit(1);
		}
		all.index++ ;
	}
}
int main(int argc, char **argv)
{

    char    *res;
    char *ondstring;
    char    **test;
    int     *num;
    t_addr  add ;
    Node    *list;
    Node    *list_b;
    list = malloc(sizeof(struct Node));
    list_b = malloc(sizeof(struct Node));
    Node *other ;
    other = malloc(sizeof(struct Node));
    other->array = 8;
    other->next = NULL;
    list_b->array = 10;
    list_b->next = other;
	check_args(argc, argv);
    res = merge_in_one(argv);
    ondstring = keep_one(res);
    test = read_to_list(ondstring);
    num = convert_to_number(test, &add);
    check_double(num, &add);
	check_greater(num, &add);
    function_made(num, list, &add);
    // rr_rotate(&list, &list_b);
    // pb_push(&list, &list_b);
    // pa_push(&list, &list_b);
    // pa_push(&list, &list_b);
    rrr_rotate(&list, &list_b);
    while (list_b != NULL)
    {
        printf("List_B==>>>>>[%d]\n", list_b->array);
        list_b = list_b->next;
    }
    printf("\n");
    while (list != NULL)
    {
        printf("List_A==>>>>>[%d]\n", list->array);
        list = list->next;
    }
}