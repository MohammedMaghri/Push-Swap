/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:34:38 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/10 19:06:29 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int count_twode(char **string)
{
    int index = 0;

    while (string[index])
    {
        index++ ;
    }
    return (index);
}
int check_to_add(char **string)
{
    int index = 0;
    int flag = 0;
    int incre = 0;
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
int number_converter(char *string)
{
    t_fac   conv;

    conv.index = 0;
    conv.total = 0;
    conv.flag = 1;

    while ((string[conv.index] >= 9 && string[conv.index] <= 13) || string[conv.index] == ' ')
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

// char **check_each_array(char **string)
// {
//     t_fac   check;
//     check.puttwode;

//     check.index = 0;
//     check.total = count_twode(string);
//     while (string[check.index])
//     {

//     }
// }