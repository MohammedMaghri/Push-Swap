/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:54:30 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/24 11:31:04 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct swap
{
	int			**puttwode;
	long long	total;
	int			negat;
	int			flag;
	int			index;
	int			res ;
	int			increment;
	char		*allocation;
	int			counter;
}	t_fac;

typedef struct bonus
{
	int		index;
	char	**res;
	int		flag;
	int		win;
	int		track;
	int		increment;
}	t_bone;
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
	int		i;
	int		checkpoint;
	char	*temp;
}	t_parc;

typedef struct foradress
{
	int	address;
}	t_addr;

typedef struct Node
{
	int			array;
	int			index;
	struct Node	*next;
}	t_Node;

typedef struct lspies
{
	int	lastpivot;
	int	pvtone;
	int	pvttwo;
}	t_lspies;

typedef struct the_check
{
	char	**res ;
	int		index;
	int		increment;
	int		flag;
}	t_check;

typedef struct till_null
{
	char	*string;
	int		flag ;
	int		track;
	int		rais ;
	int		res;
}	t_null;

void	initilaize(int *increment, int *index, int *flag);
void	up_there(char *string, char *res, int *increment, int *flag);
void	for_ko(void);
void	for_er(void);
void	count_if(t_Node **list_b);
char	*add_till(char *string);
int		all_of(char *string);
int		check_all(char *string);
void	sort_five(t_Node **list, t_Node **list_b);
void	out(void);
int		find_bottom_index(t_Node **list);
void	for_second_iteration(t_Node **list, t_Node **list_b, \
int *bottom, int *bigger);
void	for_the_second_of_thesecond(t_Node **list, t_Node **list_b, \
int *bottomindex);
void	second_iteration(t_Node **list, t_Node **list_b);
void	for_condition(t_Node **list, t_Node **list_b, int *bottomindex);
int		make_it(char *string, int flag);
void	function_check(long long number, int flag);
void	last_check(t_Node **list, t_Node **list_b);
void	check_condition(char *string, int flag);
void	if_null(char *string, t_Node **list, t_Node **list_b);
void	read_till_null(int fd, int argc, t_Node **list, t_Node **list_b);
char	**command_storage(void);
int		call_to_apply(int number, t_Node **list, t_Node **list_b);
void	test_the_command(char *string, t_Node **list, t_Node **list_b);
int		compare_all(char *string, int checker, t_Node **list, t_Node **list_b);
void	sb_swap_bonus(t_Node *list_b);
void	sa_swap_bonus(t_Node *list_a);
void	rrr_rotate_bonus(t_Node **list_a, t_Node **list_b);
void	rrb_rotate_bonus(t_Node **list_b);
void	rra_rotate_bonus(t_Node **list_a);
void	rr_rotate_bonus(t_Node **list_a, t_Node **list_b);
void	rb_rotate_bonus(t_Node **list_b);
void	ra_rotate_bonus(t_Node **list_a);
void	pa_push_bonus(t_Node **list_a, t_Node **list_b);
void	pb_push_bonus(t_Node **list_a, t_Node **list_b);
void	ss_swap_bonus(t_Node *list_a, t_Node *list_b);
void	ss_swap(t_Node *list_a, t_Node *list_b);
void	test_the_command(char *string, t_Node **list, t_Node **list_b);
char	*merge_in_one(char **string, int ac);
void	for_main(char **argv, int argc);
int		compare_all(char *string, int checker, t_Node **list, t_Node **list_b);
int		*for_bonus(char **argv, int argc);
void	pass_function(char **twode, char *string);
int		count_l(t_Node *list);
void	chek_minis(char *array);
void	check_more_min(char *array);
void	check_args(char **array);
void	check_double(int *num, t_addr *ind);
void	check_other_plus(char **array);
void	check_plus(char **array);
int		check_if_up(t_Node **list, int index);
void	index_all(t_Node **list, t_Node **list_b, t_lspies *lsp);
int		number_only(char string);
void	check_four(t_Node **list, t_Node **list_b);
void	push_positiong(t_Node **list, t_Node **list_b);
int		check_less(t_Node **list);
int		bring_last(t_Node **list);
int		check_all_heights(t_Node **list);
void	check_tree(t_Node **list);
void	check_at_index(t_Node *list);
int		check_sort(t_Node **list);
int		check_highest(t_Node **list);
void	at_linked(t_Node **list);
void	check_if_only_tree(t_Node **list);
void	check_greater(int *array, t_addr *add);
void	rrr_rotate(t_Node **list_a, t_Node **list_b);
void	rrb_rotate(t_Node **list_b);
void	rra_rotate(t_Node **list_a);
void	rr_rotate(t_Node **list_a, t_Node **list_b);
void	rb_rotate(t_Node **list_b);
void	ra_rotate(t_Node **list);
void	pa_push(t_Node **list_a, t_Node **list_b);
void	pb_push(t_Node **list_a, t_Node **list_b);
void	function_made(int *num, t_Node *list, t_addr *add);
void	sadd_list(t_Node *add, int num);
void	sa_swap(t_Node *list);
void	sb_swap(t_Node *list_b);
int		count_list(t_Node *list);
void	check_double(int *num, t_addr *ind);
char	*keep_one(char *string);
int		*convert_to_number(char **string, t_addr *add);
void	function_compare(int *arr);
int		count_twode(char **string);
int		check_to_add(char **string);
int		lecount(char *string);
int		count_how_much(char *string);
void	putstr(char *string);
int		check_validity(char *string);
int		count_total(char **array);
void	free_all(char **string);
char	**read_to_list(char *string);
char	*string_maker(char *string);
char	*make_new(char *string, int checkpoint);
#endif 