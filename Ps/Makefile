var= push_swap
bons= checker
SRC= main.c function_nedeed.c parcing.c read_to_list.c array_check.c basic_functions.c list.c rr_rotate.c rrr_rotate.c ss_swap.c operation_for_tree.c less_hightst.c pa_push.c whole_algo.c cheker_two.c checker.c compelt_number.c only_for_second.c
SRC2= bonus_main.c small_function.c bonus_part.c raa_for_bonus.c rest_rr_bonus.c function_nedeed.c parcing.c read_to_list.c array_check.c basic_functions.c list.c rr_rotate.c rrr_rotate.c ss_swap.c operation_for_tree.c less_hightst.c pa_push.c whole_algo.c cheker_two.c checker.c complet_bonus.c for_extra.c compelt_number.c only_for_second.c
OBJS= $(SRC:.c=.o)
OBJS2= $(SRC2:.c=.o)
CFLAGS= -Wall -Wextra -Werror
CC= cc
RM= rm -rf

all : $(var)

bonus: $(bons)

$(var): $(OBJS) pushswap.h
	$(CC) $(CFLAGS) -o $(var) $(OBJS)

$(bons): $(OBJS2) pushswap.h
	$(CC) $(CFLAGS) -o $(bons) $(OBJS2)

%.o: %.c pushswap.h
	@$(CC) $(CFLAGS) -c $< -o $@

re : fclean all

clean:
	$(RM) $(OBJS) $(OBJS2)

fclean: clean
	$(RM) $(var) $(bons)

.PHONY : fclean all