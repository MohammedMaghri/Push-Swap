/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:54:30 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/11 12:13:24 by mmaghri          ###   ########.fr       */
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
	int		total;
	int		index;
	int		flag;
	int		increment;
	char	*allocation;
} t_parc;

typedef struct Node
{
	char *string;
	struct	Node *next;
} Node ;

void function_compare(int *arr);
int *convert_to_number(char **string);
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