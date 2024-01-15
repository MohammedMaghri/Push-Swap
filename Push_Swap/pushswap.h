/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:54:30 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/14 22:30:54 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PUSHSWAP_H
# define	PUSHSWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct swap
{
	int		**puttwode;
	int		total;
	int		negat;
	int		flag;
	int		index;
	int		res ;
	int		increment;
	char	*allocation;
	int		counter;
} t_fac;

typedef struct forparcing
{
	int		other;
	int		freez;
	int		total;
	int		index;
	int		flag;
	int		increment;
	char	*allocation;
	char	**twode;
} t_parc;

typedef struct foradress
{
	int	address;
} t_addr ; 

typedef struct Node
{
	int	array;
	int	index;
	struct	Node *next;
} Node ;

void	check_if_only_tree(Node **list);
void	check_greater(int *array, t_addr *add);
void rrr_rotate(Node **list_a, Node **list_b);
void rrb_rotate(Node **list_b);
void rra_rotate(Node **list_a);
void rr_rotate(Node **list_a, Node **list_b);
void rb_rotate(Node **list_b);
void ra_rotate(Node **list);
void pa_push(Node **list_a, Node **list_b);
void pb_push(Node **list_a, Node **list_b);
void function_made(int *num, Node *list, t_addr *add);
void sadd_list(Node *add, int num);
void sa_swap(Node *list);
int count_list(Node *list);
void check_double(int *num, t_addr *ind);
char *keep_one(char *string);
int *convert_to_number(char **string, t_addr *add);
int count_twode_arr(int *arr);
void function_compare(int *arr);
int count_twode(char **string);
int check_to_add(char **string);
int lecount(char *string);
int count_how_much(char *string);
void putstr(char *string);
int  check_validity(char *string);
int count_total(char **array);
void free_all(char **string);
char **read_to_list(char *string);
char *string_maker(char *string);
char *make_new(char *string, int checkpoint);
#endif 