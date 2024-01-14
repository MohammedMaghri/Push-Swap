/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 11:19:23 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/14 12:53:55 by mmaghri          ###   ########.fr       */
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
    if (count_list(list_a) <= 1 || count_list(list_b) <= 1)
        return ;
    sa_swap(list_a);
    sb_swap(list_b);
    putstr("ss\n");
}

void pb_push(Node **list_a, Node **list_b)
{
    if (*list_a == NULL)
        return ;
    Node *other = (*list_b);
    Node *point =(*list_a)->next;
    (*list_b)  = (*list_a);
    (*list_a) = point;
    (*list_b)->next = other;
    putstr("pb\n");
}

void pa_push(Node **list_a, Node **list_b)
{
    if (*list_b == NULL)
        return;
    Node *keep = (*list_a);
    Node *flag = (*list_b);
    Node *move = (*list_b)->next;
    (*list_b) = move;
    (*list_a) = flag;
    (*list_a)->next = keep; 
    putstr("pa\n");
}

void ra_rotate(Node **list)
{
    if (count_list(*list) < 2)
        return ;
    Node *flag = (*list);
    Node *from = (*list)->next;
    (*list) = from;
    Node *hnaya = *list;
    while (hnaya->next != NULL)
        (hnaya) = (hnaya)->next;
    hnaya->next = flag;
    flag->next = NULL;
    putstr("ra\n");
}

void rb_rotate(Node **list_b)
{
    if (count_list(*list_b) == 1)
        return;
    Node *flag = (*list_b);
    Node *track = (*list_b)->next;
    Node *follow = flag;
    (*list_b) = track ;
    while (follow->next != NULL)
        follow = follow->next;
    follow->next = flag;
    flag->next = NULL;
    putstr("rb\n");
}
void rr_rotate(Node **list_a, Node **list_b)
{
    ra_rotate((list_a));
    rb_rotate((list_b));
    putstr("rr\n");
}

void rra_rotate(Node **list_a)
{
    if (count_list(*list_a) < 2)
        return ;
    if (count_list(*list_a) == 2)
    {
        sa_swap(*list_a);
        return ;
    }
    Node *inc = (*list_a);
    Node *var = NULL;
    while (inc->next != NULL)
    {
        var = inc ;
        inc = inc->next;
    }
    var->next = NULL;
    inc->next = (*list_a);
    (*list_a) = inc;
}

void rrb_rotate(Node **list_b)
{
    Node *head;
    Node *position;
    head = (*list_b);
    position = NULL;
    while (head->next != NULL)
    {
        position = head ;
        head = head->next ;
    }
    position->next = NULL;
    head->next = (*list_b);
    (*list_b) = head;
}
