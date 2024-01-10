/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_to_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:38:12 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/10 19:10:40 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void paste(char string)
{
    write(1, &string, 1);
}

int count_how_much(char *string)
{
    int flag = 0;
    int index = 0;

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

char *make_new(char *string, int checkpoint)
{
    int index = 0;
    char *allocation;
    allocation = malloc(sizeof(char) *  (checkpoint + 1));
    while (index < checkpoint)
    {
        allocation[index] = string[index];
        index++ ;
    }
    allocation[index] = '\0';
    return (allocation);
}

char *string_maker(char *string)
{
    int index = 0;
    char    *allocation;
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

char **read_to_list(char *string)
{
    t_parc list;
    char    **alocation;
    char    *temp;
    int checkpoint = 0;
    list.index = 0;
    list.increment = 0;
    list.total = 0;
    alocation = malloc(sizeof(char *) * count_how_much(string) + 1);
    while (string[list.index] && lecount(string) != 0)
    {
        if (string[list.index] == ' ')
        {
            checkpoint = list.index;
            list.index++ ;
            alocation[list.increment] = make_new(string, checkpoint);
            temp = string_maker(&string[list.index]);
            free(string);
            string = string_maker(temp);
            list.index = 0;
            list.increment++ ;
        }
        list.index++;
    }
    alocation[list.increment] = NULL;
    return (alocation);
}
