/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_nedeed.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:58:44 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/11 21:17:56 by mmaghri          ###   ########.fr       */
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
    all.allocation = malloc(sizeof(char **) * 1000);
    if (!all.allocation)
        return NULL;
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
void ll(void)
{
    system("leaks pushswap");
    exit(1);
}
int main(int argc, char **argv)
{

    char    *res;
    char *ondstring;
    char    **test;
    int     *num;
    t_addr  add ;
    int index = 0;
    if (argc <= 1)
    {
        putstr("Not Enough Argument");
        exit(1);
    }
    while (index < count_total(argv))
    {
        if (argv[index][0] == '\0')
        {
            putstr("Error");
            exit(1);
        }
        index++ ;
    }
    res = merge_in_one(argv);
    ondstring = keep_one(res);
    test = read_to_list(ondstring);
    num = convert_to_number(test, &add);
    while (index < add.address)
    {
        printf("[%d]\n", num[index]);
        index++ ;
    }
    // atexit(ll);
    // while (1);
}