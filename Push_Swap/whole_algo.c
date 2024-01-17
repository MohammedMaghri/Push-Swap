/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whole_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:01:41 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/17 22:39:23 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void index_all(t_Node **list, t_Node **list_b, t_lspies *lsp)
{
    t_Node *test;

    test = (*list);
    (void)lsp ;
    lsp->lastpivot = -1;
    lsp->pvtone = (count_list(*list) / 3);
    lsp->pvttwo = (count_list(*list) / 6);
    while ((*list)->next != NULL)
    {
        if (check_less(list) == 0)
            pb_push(list, list_b);
        else 
            rra_rotate(list);
        if (count_list(*list_b) == lsp->pvtone)
        {
            printf("<<< here >>>\n");
            return ;
        }
    }
}