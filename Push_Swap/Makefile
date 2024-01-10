var= pushswap
SRC= function_nedeed.c parcing.c read_to_list.c
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
	 