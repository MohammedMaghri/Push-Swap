/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:56:49 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/12 19:53:30 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <stddef.h>

int lencount(char *string)
{
    int index = 0;
    while (string[index])
    {
        index++;
    }
    return (index);
}
char *make_string(char *string)
{
    int index = 0;
    char *allocation;

    allocation = malloc(sizeof(char) * lencount(string) + 1);
    while (string[index])
    {
        allocation[index] = string[index];
        index++ ;
    }
    allocation[index] = '\0';
    return (allocation);
}
void linked_tes(Node *me, char *string)
{
    char *testing = "Pointer Two";
    char *argtr = "Pointer to the Third Argument";

    me->string = make_string(string);
    me->next = NULL;
    
    Node *test = malloc(sizeof(struct Node));
    test->string = make_string(testing);
    me->next = test;
    test->next = NULL;
    Node *tree = malloc(sizeof(struct Node));
    tree->string = make_string(argtr);
    test->next = tree;
    tree->next = NULL;
}

int main()
{
    char    *array;
    Node *test;
    Node *curent;
    test = malloc(sizeof(struct Node));
    test->next = NULL;
    array = "Me testing";
    linked_tes(test, array);
    curent = test ;
    int index = 0;
    while (curent != NULL)
    {
        index++ ;
        printf("[%s].." , curent->string);
        curent = curent->next ;
    }
    printf("\nnumber of lists are {%d}" , index);
}