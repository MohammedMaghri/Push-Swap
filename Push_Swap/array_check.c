/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:34:38 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/11 12:16:13 by mmaghri          ###   ########.fr       */
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

int *convert_to_number(char **string)
{
    t_parc  convert;
    int     *number ;


    convert.index = 0;
    convert.increment = 0;
    convert.total = count_total(string);
    number = malloc(sizeof(int) * convert.total);
    while (convert.index < convert.total)
    {
        number[convert.index] = number_converter(string[convert.index]);
        convert.index++ ;
    }
    return number;
}

int count_twode_arr(int *arr)
{
    int i = 0;

    while (arr[i])
    {
        i++ ;
    }
    return i;
}

void function_compare(int *arr)
{
    t_parc  compare;

    compare.index = 0;
    compare.flag = 0;

    printf("%d", count_twode_arr(arr));
    while (compare.index < count_twode_arr(arr))
    {
        compare.flag = arr[compare.index];
        compare.index++ ;
        while (compare.index < count_twode_arr(arr))
        {
            if (compare.flag == arr[compare.index])
            {
                putstr("Doubled");
                exit(1);
            }
            compare.index++ ;
        }
        compare.index--;
        compare.index++ ;
    }
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