/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_part.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:57:56 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/21 12:32:06 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

char *for_saftey(char *string)
{
    int index ;
    char *allocation;

    index = 0;
    allocation = malloc(sizeof(char) * lecount(string) + 1);
    if (!allocation)
        exit(1);
    while (string[index])
    {
        allocation[index] = string[index];
        index++ ;
    }
    allocation[index] = '\0';
    return allocation;
}
char *merge(char *string, char *wedohave)
{
    char *allocation;
    int index;
    int total;
    int increment;

    if (!string)
        return(for_saftey(wedohave));
    if (!wedohave)
        return (for_saftey(string));
    increment = 0;
    total = (lecount(string) + lecount(wedohave) + 1);
    index = 0;
    allocation = malloc(sizeof(char) * total);
    if (!allocation)
        exit(1);
    while (string[index])
        allocation[increment++] = string[index++];
    allocation[increment] = ' ';
    increment++;
    index = 0;
    while (wedohave[index])
        allocation[increment++] = wedohave[index++];
    allocation[increment] = '\0';
    free(wedohave);
    return (allocation);
}
void check_function(char *string)
{
	int index ;

	index = 0;
	while (string[index])
	{

	}
}
void    read_till_null(int fd, int argc, t_Node **list, t_Node **list_b)
{
    char *string;
    int flag ;
    int track;
    int rais ;

    rais = 0;
    flag  = 1;
    string = malloc((sizeof(char **)) * argc);
    while (flag > 0)
    {
        flag = read(fd, string, 100000);
		if (((lecount(string) != 3 && lecount(string) != 4) || (flag >= 1 && flag <= 2)))
		{
			putstr("Error");
			exit(1);
		}
        test_the_command(string, list, list_b);
    }
    free(string);
    track = check_sort(list);
        if (track == -1)
        {
            putstr("KO");
            exit(1);
        }
        else 
            {
                putstr("OK");
                exit(1);
            }
}

char **command_storage(void)
{
    char **allocation;

    allocation = malloc(sizeof(char **) * (11));
    if (!allocation)
        exit(1);
    allocation[0] = "sa\n";
    allocation[1] = "sb\n";
    allocation[2] = "ss\n";
    allocation[3] = "pa\n";
    allocation[4] = "pb\n";
    allocation[5] = "ra\n";
    allocation[6] = "rb\n";
    allocation[7] = "rr\n";
    allocation[8] = "rra\n";
    allocation[9] = "rrb\n";
    allocation[10] = "rrr\n";
    allocation[12] = NULL;
    return (allocation);
} 

void test_the_command(char *string, t_Node **list, t_Node **list_b)
{
    char	**res ;
    int		flag;

    res = command_storage();
    if (lecount(string) >= 5)
        exit(1);
	else if (lecount(string) == 4)
    {
		flag = compare_all(string, 4, list, list_b);
		if (flag == 1)
			{
				putstr("Error");
				exit(1);
			}
        string[0] = '*';
    }
	else if (lecount(string) == 3)
    {
		flag = compare_all(string, 3, list, list_b);
		if (flag == 1)
			{
				putstr("Error");
				exit(1);
			}
        string[0] = '*';
    }
}

int call_to_apply(int number, t_Node **list, t_Node **list_b)
{
    (void)list_b;
    if (number == 0)
        return (sa_swap_bonus((*list)), -1);
    else if (number == 1)
        return (sb_swap_bonus((*list)), -1);
    else if (number == 2)
        return (ss_swap_bonus((*list), *list_b), -1);
    else if (number == 3)
        return (pa_push_bonus((list), (list_b)), -1);
    else if (number == 4)
        return (pb_push_bonus((list), (list_b)), -1);
    else if (number == 5)
        return (ra_rotate_bonus((list)), -1);
    else if (number == 6)
        return (rb_rotate_bonus((list)), -1);
    else if (number == 7)
        return (rr_rotate_bonus((list), list_b), -1);
    else if (number == 8)
        return (rra_rotate_bonus((list)), -1);
    else if (number == 9)
        return (rrb_rotate_bonus((list)), -1);
    else if (number == 10)
        return (rrr_rotate_bonus((list), (list_b)), -1);
    return (0);
}
int compare_all(char *string, int checker, t_Node **list, t_Node **list_b)
{
    int     index;
    char    **res;
    int     flag;
    int     win;
	int		track;
	int		increment;

	increment = 0;
	track = 0;
    win = 1;
    flag = 0;
    index = 0;
    res = command_storage();
    while (increment < 11)
    {
        while (res[increment][index])
        {
            if (res[increment][index] == string[index])
                flag++;
            if (flag == checker)
			{
                win = (0);
				flag = 0;
                call_to_apply(increment, list, list_b);
				return (win);
			}
            index++;
        }
		increment++ ;
        index = 0;
        flag = 0;
    }
    return (-1);
}

int main(int argc, char **argv)
{
	int			*num;
	t_addr		add;
	t_Node		*list;
	t_Node		*list_b;
	list = malloc(sizeof(struct Node));
	list_b = NULL ;
	check_args(argv);
	num = convert_to_number(read_to_list(keep_one(merge_in_one(argv, argc))) \
	, &add);
	check_double(num, &add);
	check_greater(num, &add);
	function_made(num, list, &add);
	at_linked(&list);
    read_till_null(0, argc, &list, &list_b);
}
