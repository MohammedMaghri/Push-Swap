/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:53:52 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/10 13:55:55 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void free_all(char **string)
{
    int index = 0;
    while (index < count_total(string))
    {
        free(string[index]);
        index++ ;
    }
    free(string);
}
int check_number(char string)
{
    if (string >= '0' && string <= '9')
        return (0);
    return (-1);
}
int  check_validity(char *string)
{
    int index = 0;

    while (string[index])
    {
        if (check_number(string[index]) != 0)
        {
            putstr("Wired Ithem In the arguments\n");
            return (-1);       
        }
        index++ ;
    }
    return (0);
}