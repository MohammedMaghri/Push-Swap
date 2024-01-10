/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_nedeed.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:58:44 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/10 17:30:59 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void putstr(char *string)
{
    while (*string)
        write(2, string++, 1);
}

int lecount(char *string)
{
    int index = 0;

    while (string[index])
    {
        index++ ;
    }
    return (index);
}
int count_total(char **array)
{
    t_fac   all;

    all.index = 0;
    while (array[all.index])
    {
        all.index++ ;
    }
    return (all.index);
}

char *move_string(char *string)
{
    t_fac all;

    all.allocation = malloc(sizeof(char) * lecount(string) + 1);
    while (string[all.increment])
    {
        all.allocation[all.increment] = string[all.increment];
        all.increment++;
    }
    return (all.allocation);
}
char *merge_in_one(char **string)
{
    t_fac   all;

    all.index = 1;
    all.increment = 0;
    all.counter = 0;
    all.total = count_total(string);
    all.allocation = malloc(sizeof(char *) * (all.total + 1));
    while (all.index < all.total)
    {
        while (string[all.index][all.increment])
        {
            check_validity(string[all.index]);
            all.allocation[all.counter] = string[all.index][all.increment];
            all.increment++;
            all.counter++;
        }
        all.allocation[all.counter] = '-' ;
        all.counter++ ;
        all.increment = 0;
        all.index++ ;
    }
    all.allocation[all.counter] = '\0';
    return (all.allocation);
}
int main(int argc, char **argv)
{
    if (argc <= 1)
    {
        putstr("Not Enough Argument");
        exit(1);
    }
    char *res = merge_in_one(argv);
    char **test = read_to_list(res);
    int i = 0;
    while (i < 5)
    {
        printf("[%s]\n", test[i]);
        i++;
    }
}