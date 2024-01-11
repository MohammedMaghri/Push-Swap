#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

typedef struct s_list
{
    int index;
    int content;
    struct s_list *next;
}               t_list;

void ft_newnode(t_list **stack, int content)
{
    t_list *curr;
    t_list *new_node;

    new_node = malloc(sizeof(t_list));
    if(!new_node)
        return ;
    curr = *stack;
    while(curr->next)
        curr = curr->next;
    new_node->content = content;
    curr->next = new_node;
    new_node->next = NULL;
}

int main()
{
    t_list *stacka; 

    stacka = malloc(sizeof(t_list));
    if(!stacka)
        return 0;
    stacka->next = NULL;
    ft_newnode(&stacka, 1);
    ft_newnode(&stacka, 2);
    ft_newnode(&stacka, 3);
    ft_newnode(&stacka, 4);
    ft_newnode(&stacka, 5);
    ft_newnode(&stacka, 6);
    while(stacka)
    {
        printf("%d\n", stacka->content);
        stacka = stacka->next;
    }
}