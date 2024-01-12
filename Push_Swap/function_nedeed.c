/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_nedeed.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:58:44 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/12 20:19:40 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"


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

void check_double(int *num, t_addr *ind)
{
    t_parc  doble;

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

void sadd_list(Node *add, int num)
{
    Node    *str;

    str = malloc(sizeof(struct Node));

    while (add->next != NULL)
        add = add->next;
    add->next = str;
    str->array = num;
    str->next = NULL;
}

void function_made(int *num, Node *list, t_addr *add)
{
    t_parc  made;

    made.index = 0;
    list->array = num[made.index];
    list->next = NULL;
    made.index++ ;
    while (made.index < add->address)
    {
        sadd_list(list, num[made.index]);
        made.index++;
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
    list = malloc(sizeof(struct Node));
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
        if ((lecount(argv[index]) == 1 && argv[index][0] == '-') || (lecount(argv[index]) == 1 && argv[index][0] == ' '))
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
    check_double(num, &add);
    function_made(num , list, &add);
    while (list != NULL)
    {
        printf("[%d]\n",list->array);
        list = list->next;
    }
}