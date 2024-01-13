/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 11:19:23 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/13 15:30:34 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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

int count_list(Node *list)
{
    t_parc count;

    count.index = 1;
    while (list->next != NULL)
    {
        list = list->next ;
        count.index++ ;
    }
    return (count.index);
}

void sa_swap(Node *list_a)
{
    int sec;
    int num;

    if (count_list(list_a) <= 1)
        return ;
    struct Node *first = list_a;
    num = first->array;
    first = first->next;
    sec = first->array;
    list_a->array = sec;
    list_a = list_a->next;
    list_a->array = num;
    putstr("sa\n");
}

void sb_swap(Node *list_b)
{
    int sec;
    int num;

    if (count_list(list_b) <= 1)
        return ;
    struct Node *first = list_b;
    num = first->array;
    first = first->next;
    sec = first->array;
    list_b->array = sec;
    list_b = list_b->next;
    list_b->array = num;
    putstr("sb\n");
}
void ss_swap(Node *list_a, Node *list_b)
{
    sa_swap(list_a);
    sb_swap(list_b);
    putstr("ss\n");
}

void pb_push(Node **list_a, Node **list_b)
{
    if (*list_a == NULL)
        return ;
    if (count_list(*list_a) < 1)
    {
        Node *point= (*list_a)->next;
        (*list_b) = (*list_a);
        (*list_a) = point;
        (*list_b)->next = NULL;;
    }
    else
    {
        Node *other = (*list_b);
        Node *point =(*list_a)->next;
        (*list_b)  = (*list_a);
        (*list_a) = point;
        (*list_b)->next = other;
    }
    putstr("pb\n");
}

// void pa_push(Node **list_a, Node **list_b)
// {
//     if (count_list(list_b) < 1)
//         return ;
//     if (count_list(list_b) < 1)

//     putstr("pb\n");
// }