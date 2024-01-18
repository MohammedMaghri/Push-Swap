var= push_swap
SRC= function_nedeed.c parcing.c read_to_list.c array_check.c basic_functions.c list.c rr_rotate.c rrr_rotate.c ss_swap.c operation_for_tree.c less_hightst.c pa_push.c whole_algo.c
OBJS= $(SRC:.c=.o)
CFLAGS= -Wall -Wextra -Werror
CC= cc
RM= rm -rf
all : $(var)

$(var) : $(OBJS)
	$(CC) $(CFLAGS) -o $(var) $(OBJS)

clean: $(var)
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(var) $(OBJS)
	 